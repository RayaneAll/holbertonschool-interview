#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];
const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

/**
 * printCharacters - prints character names in order
 * @characters: list of character API URLs
 * @index: current character index
 */
function printCharacters (characters, index) {
  if (index === characters.length) {
    return;
  }

  request(characters[index], (error, response, body) => {
    if (error) {
      return;
    }

    console.log(JSON.parse(body).name);
    printCharacters(characters, index + 1);
  });
}

request(filmUrl, (error, response, body) => {
  if (error) {
    return;
  }

  printCharacters(JSON.parse(body).characters, 0);
});
