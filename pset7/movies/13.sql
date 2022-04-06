SELECT DISTINCT name
FROM people JOIN stars ON people.id = stars.person_id
WHERE movie_id IN
(SELECT movie_id
FROM people JOIN stars ON people.id = stars.person_id
WHERE birth = '1958' and name = 'Kevin Bacon')
AND name != 'Kevin Bacon';