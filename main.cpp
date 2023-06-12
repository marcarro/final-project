#include <iostream>
#include "Library.h"
#include "Episode.h"
using namespace std;

int main() {
  Library lib;
  cout << "printByRating(): \n";
  lib.printByRating("0");
  cout << "\nprintByGenre(): \n";
  lib.printByGenre("drama");
  cout << "\nprintBySeriesAndRating(): \n";
  lib.printBySeriesAndRating("Stranger_Things", "0");
  cout << "\nprintMoviesByRating(): \n";
  lib.printMoviesByRating("0");
  cout << "\nrateVideo(): \n";
  lib.rateVideo();
}