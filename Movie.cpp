#include "Movie.h"

Movie::Movie() : Video() {}
Movie::Movie(string id, string length, string genre, string name, string rating) : Video(id, length, genre, name, rating) {}

void Movie::printDetails() {
  cout << "ID: " << getId() << ", Length: " << getLength() << ", Genre: " << getGenre()
       << ", Name: " << getName() << ", Rating: " << getRating() << endl;
}