SELECT name
FROM people JOIN stars ON people.id = person_id JOIN movies ON movies.id = stars.movie_id
WHERE title = 'Toy Story';