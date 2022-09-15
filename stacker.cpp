
#include <iostream>
#include <vector>
#include <string>
#include "stacker.h"

using namespace std;

Stacker::Stacker() {
  magic_number = "null";

  filename = "Name";

  numFiles = 0;
  width = 0;
  height = 0;
  max_color = 0;

  vector<pixel> pixels;

  pixels.r = 0;
  pixels.g = 0;
  pixels.b = 0;
  

}

Stacker::Stacker(string filename, int numFiles) {
  this->filename;
  this->num_of_files = numFiles;
}



string Stacker::genSpecificName(string filename, int count) {
  string sfName;

  string num = count;

  
  if(count < 10) { //if count is a single digit
    sfName = filename + "/" + filename + "_0" + "0" + num + ".ppm"

  }

  else if (count >= 10) { //if count is a double digit
    sfName = filename + "/" + filename + "_0" + num + ".ppm"
    
  }

  return sfName;
}
