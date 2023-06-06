#ifndef MOVIE_H
#define MOVIE_H

#include "Video.h"

class Movie : public Video {
public:
  Movie();
  Movie(string id, string length, string genre, string name, string rating);
};

#endif