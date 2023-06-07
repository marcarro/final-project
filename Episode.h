#ifndef EPISODE_H
#define EPISODE_H

#include "Video.h"

class Episode : public Video {
public:
  Episode();
  Episode(string id, string length, string genre, string name, string rating, string ntitle, string nseason);

  string getTitle();
  string getSeason() override;

  void setTitle(string newTitle);
  void setSeason(string newSeason);
private:
  string title, season;
};

#endif