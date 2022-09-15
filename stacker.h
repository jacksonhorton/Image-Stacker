#ifndef STACKER_H
#define STACKER_H


/**
 * Stacker will take multiple images and average the values of their pixels to create a prettier image.
 *
 * @class Stacker stacker.h "Image-Stacker/stacker.h"
 * @brief The Stacker class will read the color values from all the pixels in an image into a vector of pixels. It will get important information like the width and height of the ppm image, the magic_number, and the max_color will be gathered from the first image read and applied to the final composition. Once all of the pixels are read into the pixel vector, the values for each pixel are averaged. Then, the final composition can be made.
 *
 */
class Stacker {
 public:
  Stacker(string filename, int num_of_files);
  void stack();
  void read_file();
  void average();
  
  
 private:
  stuct pixel {
    int r, g, b;
  };

  int width;
  int height;
  int max_color;
  int num_of_files;
  std::string filename;
  std::string magic_number;
  std::vector<pixel> pixels;
  
}

  

#endif //STACKER_H
