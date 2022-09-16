
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


string stacker::genSpecificName(string filename, int fileNum) {
  string sfName;
  // converts the file number to a string.
  string num = to_string(fileNum);

  
  // if the file number is < 10
  if(fileNum < 10)
    sfName = filename + "/" + filename + "_0" + "0" + num + ".ppm";
  // if the fileNum is < 100 (and implicitly > 9 based on if statement)
  else if (fileNum >= 10)
    sfName = filename + "/" + filename + "_0" + num + ".ppm";
  // if the file number is > 99, we assume it to be 3 digits, or < 1000
  else
    sfName = filename + "/" + filename + "_" + num + ".ppm";

  // returns the specific file name and path based on the filename and current file number given
  cout << sfName << endl;
  return sfName;
}


void stacker::read_file(int fileIndex) {
  ifstream fin;
  // the number of the file is always +1 th index.
  int fileNum = fileIndex + 1;
  string filepath;

  // generates a string of the filepath; passes fileNum which is +1 the file index
  filepath = stacker::genSpecificName(filename, fileNum);

  //open file
  fin.open(filepath);

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
  }

  fin.close();
}
