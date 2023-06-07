#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class Video {
public:
  Video();
  Video(string, string, string, string, string);
  virtual ~Video() {}

  string getId();
  string getLength();
  string getGenre();
  string getName();
  string getRating();
  virtual string getEpisode() { return ""; }
  virtual string getSeason() { return ""; }

  void setId(string newId);
  void setLength(string newLength);
  void setGenre(string newGenre);
  void setName(string newName);
  void setRating(string newRating);

private:
  string id, length, genre, name, rating;
};

#endif