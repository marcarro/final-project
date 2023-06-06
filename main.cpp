#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

#include "Movie.h"
#include "Episode.h"
#include "Video.h"
using namespace std;

int main() {
  int n = 0;
  ifstream lines("data.txt"); string line;
  while (getline(lines, line)) n++; lines.close();
  
  ifstream episodes("data.txt");
  string id, length, genre, name, rating, title, season;
  line = "";

  vector<Video*> library(n - 1);
  int i = 0;
  getline(episodes, line);
  while (getline(episodes, line)) {
  stringstream ss(line);
  getline(ss, id, ' ');
  getline(ss, name, ' ');
  getline(ss, length, ' ');
  getline(ss, genre, ' ');
  getline(ss, title, ' ');
  getline(ss, season, ' ');
  getline(ss, rating, ' ');

  library[i++] = new Movie(id, length, genre, name, rating);
  cout << library[i - 1]->getName() << endl;
}
  // for (auto video: library) {
  //   cout << video->getName() << "\n";
  // }
}