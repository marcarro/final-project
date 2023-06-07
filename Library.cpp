#include "Library.h"
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

Library::Library() {
  int n = 0;
  ifstream lines("data.txt"); string line;
  while (getline(lines, line)) n++; lines.close();

  ifstream episodes("data.txt");
  line = "";

  int i = 0;
  getline(episodes, line);
  while (getline(episodes, line)) {
    stringstream ss(line);
    vector<string> fields;
    string field;
    while(getline(ss, field, ' ')) fields.push_back(field);

    if (fields.size() == 4) {
        videos.push_back(new Movie(fields[0], fields[2], fields[3], fields[1], "0"));
    } else if (fields.size() == 6) {
        videos.push_back(new Episode(fields[0], fields[2], fields[3], fields[1], "0", fields[4], fields[5]));
    }
  }
}

void Library::print() {
  for (auto video : videos)
    cout << video->getName() << endl;
  cout << flush;
}

void Library::printByRating(string rating) {
    for (auto video : videos) {
        if (video->getRating() == rating) {
            cout << video->getName() << "\n";
        }
    }
}

void Library::printByGenre(string genre) {
  for (auto video : videos) {
    if (video->getGenre() == genre) {
      cout << video->getName() << "\n";
    }
  }
  cout << flush;
}

void Library::printBySeriesAndRating(string seriesName, string rating) {
  for (auto video : videos) {
    Episode* episode = dynamic_cast<Episode*>(video);
    if (episode != nullptr && episode->getName() == seriesName && episode->getRating() == rating) {
      cout << "Title: " << episode->getTitle() << endl;
    }
  }
  cout << flush;
}

void Library::printMoviesByRating(string rating) {
    for (auto video : videos) {
        Movie* movie = dynamic_cast<Movie*>(video);
        if (movie != nullptr && movie->getRating() == rating) {
            cout << movie->getName() << "\n";
        }
    }
}