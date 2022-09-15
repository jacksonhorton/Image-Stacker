/**
 * @file main.cpp
 * @author Kenneth Wallace, William Hayes, Jackson Horton
 * @date 2022-09-15
 * @brief 
 * 
 * 
 */

#include "Stacker.h"
#include <iostream>

using namespace std;

int main() {

  //
  string filename;
  int numFiles;

  cout << "Please enter the image you wish to stack: ";
  getline(cin, filename);

  cout << "Please enter the number of images: ";
  cin >> numFiles;

  stacker image(filename, numFiles);

  image.stack();
  
  return 0;
}

