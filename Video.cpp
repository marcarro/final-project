#include "Video.h"

Video::Video() {
  id = "-1", length = "0", rating = "0";
}

Video::Video(string nid, string nlength, string ngenre, string nname, string nrating) {
  id = nid, length = nlength, genre = ngenre, name = nname, rating = nrating;
}

string Video::getId() { return id; }
string Video::getLength() { return length; }
string Video::getGenre() { return genre; }
string Video::getName() { return name; }
string Video::getRating() { return rating; }

void Video::setId(string newId) { id = newId; }
void Video::setLength(string newLength) { length = newLength; }
void Video::setGenre(string newGenre) { genre = newGenre; }
void Video::setName(string newName) { name = newName; }
void Video::setRating(string newRating) { rating = newRating; }