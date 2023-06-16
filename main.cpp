#include <iostream>
#include "Library.h"
#include "Episode.h"
#include "Movie.h"
using namespace std;

int main() {
  // Change method arguments to test input validation !
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
  cout << "\nEpisode printDetails() (abstract fn): \n";
  Episode ep1("101", "45", "drama", "Superman", "10", "Beep", "1");
  ep1.printDetails();
  cout << "\nMovie printDetails() (abstract fn): \n";
  Movie mov1("102", "90", "terror", "scary movie", "5");
  mov1.printDetails();
  cout << "\nEpisode operator << overload: \n";
  cout << ep1 << "\n";
  cout << "\nMovie operator << overload: \n";
  cout << mov1 << "\n";
}