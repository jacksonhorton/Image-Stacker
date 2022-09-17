
#include <iostream>
#include <fstream>
#include "stacker.h"


using namespace std;

 
stacker::stacker(string filename, int numFiles) {
  this->filename = filename;
  this->numFiles = numFiles;

  magic_number = "";
  width = 0;
  height = 0;
  max_color = 0;
  
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

  return sfName;
}


void stacker::read_file(int fileIndex) {
  ifstream fin;
  // the number of the file is always +1 th index.
  int fileNum = fileIndex + 1;
  string filepath;

  // generates a string of the filepath; passes fileNum which is +1 the file index
  filepath = stacker::genSpecificName(filename, fileNum);

  cout << "Reading file: " << filepath << endl;
  
  //open file
  fin.open(filepath);

  
  //on first file, read in header info
  if (fileIndex == 0) {
    cout << "Extracting header..." << endl;
    fin >> magic_number >> width >> height >> max_color;
  }
  //for the other files, skip the header
  else {
    string junk;
    getline(fin, junk);
    getline(fin, junk);
    getline(fin, junk);
  }

  // read in the pixels from the body
  int r, g, b;
  int i = 0;  //counter
  fin >> r >> g >> b;  // priming read
    
  // read through body; reads each pixel's rgb value into pixels vector
  while (fin) {
    // if the index in pixels doesn't yet contain a pixel, push one to it; this should only run on the first iteration
    if (i >= pixels.size()) {
      pixels.push_back(pixel());
    }
    
    // appends the value 
    pixels[i].r += r;
    pixels[i].g += g;
    pixels[i].b += b;
    
    fin >> r >> g >> b;  // read next line or break file
    // increment index counter
    i++;
  }

  cout << "Loaded." << endl;
  fin.close();
}

void stacker::stack() {

  // read in all files
  for (int i = 0; i < numFiles; i++) {
    read_file(i);
  }

  // averages the vector using fileNum
  average();

  cout << "Writing out file: " << filename << ".ppm" << endl;

  //writes out file
  ofstream outFile;
  outFile.open(filename + ".ppm");

  //writes header
  outFile << magic_number << "\n" << width << " " << height
	  << "\n" << max_color << "\n";
  //writes body
  for (int i = 0; i < pixels.size(); i++) {
     outFile << pixels[i].r << " " << pixels[i].g << " "
	     <<  pixels[i].b << "\n";
  }

  outFile.close();
}

void stacker::average() {
  for (int i = 0; i < pixels.size(); i++) {
    pixels[i].r /= numFiles;
    pixels[i].g /= numFiles;
    pixels[i].b /= numFiles;
  }
}
