#include "Episode.h"

Episode::Episode() : Video() {
  season = "0";
}

Episode::Episode(string id, string length, string genre, string name, string rating, string ntitle, string nseason) : Video(id, length, genre, name, rating) {
  title = ntitle;
  season = nseason;
}

string Episode::getTitle() { return title; }
string Episode::getSeason() { return season; }

void Episode::setTitle(string newTitle) { title = newTitle; }
void Episode::setSeason(string newSeason) { season = newSeason; }

void Episode::printDetails() {
  using namespace std;
  cout << "ID: " << getId() << ", Length: " << getLength() << ", Genre: " << getGenre()
       << ", Name: " << getName() << ", Rating: " << getRating() << ", Title: " << getTitle() 
       << ", Season: " << getSeason() << endl;
}

ostream& operator<<(ostream& os, const Episode& ep) {
  os << static_cast<const Video&>(ep);
  os << " Title: " << ep.title << ", Season: " << ep.season;
  return os;
}