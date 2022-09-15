
#include <iostream>
#include <fstream>
#include "stacker.h"


using namespace std;

 
stacker::stacker(string filename, int numFiles) {
  this->filename = filename;
  this->numFiles = numFiles;

  width, height, max_color = 0;
  
  vector<pixel> pixels;
}

void stacker::read_file(int fileIndex) {
  ifstream fin;
  int fileNum = fileIndex + 1;
  string filepath;

  // create a string that is formatted as the filepath
  if (fileNum < 10) {
    filepath = "./" + filename + "/" + filename + "_00" + to_string(fileNum) + ".ppm";
    cout << "filepath: " << filepath << endl;
  }

  //open file
  fin.open(filepath);

  string stacker::genSpecificName(string filename, int count) {
  string sfName;

  string num = count;

  
  if(count < 10) { //if count is a single digit
    sfName = filename + "/" + filename + "_0" + "0" + num + ".ppm"

  // read header
  if (fileIndex == 0) {
    fin >> magic_number >> height >> width >> max_color;
  }
  else {
    string temp;
    getline(fin, temp);
    getline(fin, temp);
    getline(fin, temp);
  }

  //read in pixels
  int i;
  fin >> pixels[i].r >> pixels[i].g >> pixels[i].b;
  while (fin) {
    i++;
    fin >> pixels[i].r >> pixels[i].g >> pixels[i].b;
    cout << pixels[i].r << pixels[i].g << pixels[i].b << endl;
  else if (count >= 10) { //if count is a double digit
    sfName = filename + "/" + filename + "_0" + num + ".ppm"
  }

  fin.close();
  return sfName;
}
