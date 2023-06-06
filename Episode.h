#ifndef EPISODE_H
#define EPISODE_H

#include "Video.h"

class Episode : public Video {
public:
  Episode();
  Episode(string, string, string, string, string, string, string);

  string getTitle();
  string getSeason();

  void setTitle(string newTitle);
  void setSeason(string newSeason);
private:
  string title, season;
};

#endif