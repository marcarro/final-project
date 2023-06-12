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
  if (!validateRating(rating)) {
    cout << "Invalid rating. Please enter a number between 0.0 and 10.0." << endl;
    return;
  }

  for (auto video : videos) {
    if (video->getRating() == rating) {
      cout << video->getName() << "\n";
    }
  }
}

void Library::printByGenre(string genre) {
  if (!validateGenre(genre)) {
    cout << "No videos of genre " << genre << " found." << endl;
    return;
  }

  for (auto video : videos) {
    if (video->getGenre() == genre) {
      cout << video->getName() << "\n";
    }
  }
  cout << flush;
}

void Library::printBySeriesAndRating(string seriesName, string rating) {
  if (!validateSeriesName(seriesName)) {
    cout << "No series with the name " << seriesName << " found." << endl;
    return;
  }

  if (!validateRating(rating)) {
    cout << "Invalid rating. Please enter a number between 0.0 and 10.0." << endl;
    return;
  }

  for (auto video : videos) {
    Episode* episode = dynamic_cast<Episode*>(video);
    if (episode != nullptr && episode->getName() == seriesName && episode->getRating() == rating) {
      cout << "Title: " << episode->getTitle() << endl;
    }
  }
  cout << flush;
}

void Library::printMoviesByRating(string rating) {
  if (!validateRating(rating)) {
    cout << "Invalid rating. Please enter a number between 0.0 and 10.0." << endl;
    return;
  }
  
  for (auto video : videos) {
    Movie* movie = dynamic_cast<Movie*>(video);
    if (movie != nullptr && movie->getRating() == rating) {
      cout << movie->getName() << "\n";
    }
  }
}

void Library::rateVideo() {
  string title;
  string rating;

  // Ask user for the title
  cout << "Enter the title of the video you wish to rate: ";
  cin >> title;

  if (!validateTitle(title)) {
    cout << "No video with the title " << title << " was found." << endl;
    return;
  }

  // Ask user for the rating
  cout << "Enter your rating (0.0 to 10.0): ";
  cin >> rating;

  if (!validateRating(rating)) {
    cout << "Invalid rating. Please enter a number between 0.0 and 10.0." << endl;
    return;
  }

  // Loop over all videos to find the one with the entered title
  for (auto video : videos) {
    if (video->getName() == title) {
      // When the video is found, update its rating
      video->setRating(rating);
      cout << "You rated the video " << title << " with a rating of " << rating << endl;
      return;
    }
  }
}

bool Library::validateTitle(const string& title) {
  // Loop over all videos to find the one with the entered title
  for (auto video : videos) {
    if (video->getName() == title) {
      // If the video is found, return true
      return true;
    }
  }
  // If no video with the entered title is found, return false
  return false;
}

bool Library::validateRating(const string& rating) {
  // Check if the rating is a number between 0 and 10
  try {
    double ratingValue = stod(rating);
    if (ratingValue >= 0.0 && ratingValue <= 10.0) {
      return true;
    }
  } catch (...) {
      // if conversion to double failed return false
  }
  return false;
}

bool Library::validateGenre(const string& genre) {
  // Loop over all videos to find the one with the entered genre
  for (auto video : videos) {
    if (video->getGenre() == genre) {
      // If a video with the genre is found, return true
      return true;
    }
  }
  // If no video with the entered genre is found, return false
  return false;
}

bool Library::validateSeriesName(const string& seriesName) {
  // Loop over all videos to find the one with the entered series name
  for (auto video : videos) {
    Episode* episode = dynamic_cast<Episode*>(video);
    if (episode != nullptr && episode->getName() == seriesName) {
      // If a video with the series name is found, return true
      return true;
    }
  }
  // If no video with the entered series name is found, return false
  return false;
}
