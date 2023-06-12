#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include "Video.h"
#include "Movie.h"
#include "Episode.h"

class Library {
public:
  Library();
  void print();
  void printByRating(string rating);
  void printByGenre(string genre);
  void printBySeriesAndRating(string seriesName, string rating);
  void printMoviesByRating(string rating);
  void rateVideo();
private:
  vector<Video*> videos;
};

#endif