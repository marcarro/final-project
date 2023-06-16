#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
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

  virtual void printDetails() = 0;
  friend std::ostream& operator<<(std::ostream& os, const Video& video);
private:
  string id, length, genre, name, rating;
};

#endif