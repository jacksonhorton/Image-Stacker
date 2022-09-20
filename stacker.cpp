/**
 * @file stacker.cpp
 * @author William Hayes
 * @date 2022-09-18
 * @brief This file implements the stacker class's methods
 * 
 * This files implemenets the methods for the stacker class,
 * such as: the parameterized constructor, the read_file method,
 * the stacker method, etc.
 */


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
  
  string num = to_string(fileNum); //converts the file number to a string

  if(fileNum < 10) //if the fileNum is a single digit integer
    sfName = filename + "/" + filename + "_0" + "0" + num + ".ppm";
  
  else if (fileNum >= 10) //else if fileNum is a double digit integer
    sfName = filename + "/" + filename + "_0" + num + ".ppm";
  
  else //else if fileNum is a triple digit integer
    sfName = filename + "/" + filename + "_" + num + ".ppm";

  // returns the specific file name and path based on the filename and current file number given

  return sfName;
}


void stacker::read_file(int fileIndex) {
  ifstream fin;

  int rTemp, gTemp, bTemp;

  uint i = 0; //counter
  
  string filepath;
  
  int fileNum = fileIndex + 1; //the number of the file is always the index + 1
  
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
    string junk; //declared junk here, so junk will be deleted once the else statement is completed
    
    getline(fin, junk);
    getline(fin, junk);
    getline(fin, junk);
  }

  fin >> rTemp >> gTemp >> bTemp;  //priming read, reads the rgb pixel values
    
  // read through body; reads each pixel's rgb value into pixels vector
  while (fin) {
    // if the index in pixels doesn't yet contain a pixel, push one to it; this should only run on the first iteration
    if (i >= pixels.size()) {
      pixels.push_back(pixel());
    }
    
    //appends the value 
    pixels[i].r += rTemp;
    pixels[i].g += gTemp;
    pixels[i].b += bTemp;
    
    fin >> rTemp >> gTemp >> bTemp;  //read next line or break file
    
    i++; //increment the index counter by one
  }

  cout << "Loaded." << endl;
  
  fin.close();
}

void stacker::stack() {
  ofstream outFile;
  
  // read in all files
  for (int i = 0; i < numFiles; i++) {
    read_file(i);
  }

  // averages the vector using fileNum
  average();

  cout << "Writing out file: " << filename << ".ppm" << endl;

  //creates .ppm file as the out put
  outFile.open(filename + ".ppm");

  //writes header
  outFile << magic_number << "\n" << width << " " << height
	  << "\n" << max_color << "\n";
  //writes body
  for (uint i = 0; i < pixels.size(); i++) {
     outFile << pixels[i].r << " " << pixels[i].g << " "
	     <<  pixels[i].b << "\n";
  }

  outFile.close();
}

void stacker::average() {
  for (uint i = 0; i < pixels.size(); i++) {
    pixels[i].r /= numFiles;
    pixels[i].g /= numFiles;
    pixels[i].b /= numFiles;
  }
}
