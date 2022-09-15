/**
 * @file main.cpp
 * @author Kenneth Wallace, William Hayes, Jackson Horton
 * @date 2022-09-15
 * @brief Calls stacker class.
 * 
 * Stacker class will prompt user for a folder (filename) and number of images n to process, then proceeds to stack n amount of images.
 */

#include "stacker.h"
#include <iostream>

using namespace std;

int main() {

  //Name of folder to get files from.
  string filename;
  //Number of files to read from.
  int numFiles;

  //Prompts user for name of folder to get images from.
  cout << "Please enter the image you wish to stack: ";
  getline(cin, filename);

  //Prompts user for number of images to be read/processed.
  cout << "Please enter the number of images: ";
  cin >> numFiles;

  //Constructing stacker object with filename && number of files.
  stacker image(filename, numFiles);

  //Calling stack method to start stacking.
  //image.stack();

  image.read_file(1);
  
  return 0;
}

