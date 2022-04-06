-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Finding the Chamberlin Street Duck Theft Description - Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
-- Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.
SELECT street, description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2020;

-- Finding the interview transcripts from the same day to gather key information about the suspect.
SELECT id, name, transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2020;

--161 | Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
--If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
--162 | Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
--I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
--163 | Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call,
--I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Getting number plates of people leaving the courthouse between 10:15 and 10:25.
SELECT id, hour, minute, activity, license_plate FROM courthouse_security_logs WHERE day = 28 AND month = 7 AND year = 2020 AND hour = 10 AND minute < 25 AND minute > 15;

--260 | 10 | 16 | exit | 5P2BI95
--261 | 10 | 18 | exit | 94KL13X
--262 | 10 | 18 | exit | 6P58WS2
--263 | 10 | 19 | exit | 4328GD8
--264 | 10 | 20 | exit | G412CB7
--265 | 10 | 21 | exit | L93JTIZ
--266 | 10 | 23 | exit | 322W7JE
--267 | 10 | 23 | exit | 0NTHK55

-- Find account numbers of people who withdrew money from the Fifer Street ATM on the day of robbery.
SELECT id, account_number, atm_location, transaction_type, amount FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2020 AND atm_location = 'Fifer Street';

--246 | 28500762 | Fifer Street | withdraw | 48
--264 | 28296815 | Fifer Street | withdraw | 20
--266 | 76054385 | Fifer Street | withdraw | 60
--267 | 49610011 | Fifer Street | withdraw | 50
--269 | 16153065 | Fifer Street | withdraw | 80
--288 | 25506511 | Fifer Street | withdraw | 20
--313 | 81061156 | Fifer Street | withdraw | 30
--336 | 26013199 | Fifer Street | withdraw | 35

-- Cross Reference account numbers that withdrew money on Fifer Street on the 28.07.2020 with account owners.
SELECT account_number, person_id, name, phone_number, passport_number, license_plate FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id
WHERE account_number = 28500762 OR account_number = 28296815 OR account_number = 76054385 OR account_number = 49610011 OR account_number = 16153065 OR account_number = 25506511
OR account_number = 81061156 OR account_number = 26013199;

--49610011 | 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
--26013199 | 514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE
--16153065 | 458378 | Roy | (122) 555-4581 | 4408372428 | QX4YZN3
--28296815 | 395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN
--25506511 | 396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ
--28500762 | 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8
--76054385 | 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
--81061156 | 438727 | Victoria | (338) 555-6650 | 9586786673 | 8X428L0

-- PLATES MATCHING ACCOUNT NUMBERS THAT WITHDREW MONEY ON FIFER STREET:
--25506511 | 396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ
--28500762 | 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8
--49610011 | 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
--26013199 | 514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE

-- Find names of all Fiftyville Airports and find the earliest flight on the 29th of July 2020. Next, find the destination airport ID to determine where the suspect flew.
SELECT flights.id, abbreviation, full_name, city, day, month, year, hour, minute, destination_airport_id FROM airports JOIN flights ON airports.id = flights.origin_airport_id
WHERE city = 'Fiftyville' AND day = 29 AND month = 7 AND year = 2020 ORDER BY hour;
--36 | CSF | Fiftyville Regional Airport | Fiftyville | 29 | 7 | 2020 | 8 | 20 | 4

-- Find the destination airport ID to determine where the suspect flew.
SELECT abbreviation, full_name, city FROM airports WHERE id = 4;
-- LONDON HEATHROW AIRPORT

-- Find passport numbers of people on the plane and cross reference with plates and account numbers found above.
SELECT flight_id, passport_number, seat FROM passengers JOIN flights ON passengers.flight_id = flights.id
WHERE flight_id = 36;

-- 36 | 7214083635 | 2A
-- 36 | 1695452385 | 3B
-- 36 | 5773159633 | 4A = 49610011 | 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
-- 36 | 1540955065 | 5C
-- 36 | 1988161715 | 6D
-- 36 | 9878712108 | 7A
-- 36 | 8496433585 | 7B = 28500762 | 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8

-- ERNEST AND DANIELLE WERE ON THE PLANE TO LONDON HEATHROW

-- FIND WHO IS THE ASSOCIATE AND WHO STOLE THE DUCK BY FOLLOWING THE PHONE CALLS (LESS THAN A MINUTE CALL TIME)
SELECT caller, receiver, duration FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2020 AND duration <= 60 AND caller = '(389) 555-5198';
SELECT caller, receiver, duration FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2020 AND duration <= 60 AND caller = '(367) 555-5533';
-- (367) 555-5533 | (375) 555-8161 | 45
SELECT name, phone_number, passport_number, license_plate FROM people WHERE phone_number = '(375) 555-8161';
-- Berthold | (375) 555-8161 |  | 4V16VO0

-- ERNEST & BERTHOLD
