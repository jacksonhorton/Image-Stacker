/**
 * @file stacker.h
 * @author Kenneth Wallace, William Hayes, Jackson Horton
 * @date 2022-09-15
 * @brief 
 * 
 * 
 */

#ifndef STACKER_H
#define STACKER_H


/**
 * The Stacker class will read the color values from all the pixels in an image into a vector of pixels. It will get important information like the width and height of the ppm image, the magic_number, and the max_color will be gathered from the first image read and applied to the final composition. Once all of the pixels are read into the pixel vector, the values for each pixel are averaged. Then, the final composition can be made.
 * 
 *
 * @class Stacker stacker.h "Image-Stacker/stacker.h"
 * @brief Stacker will take multiple images and average the values of their pixels to create a prettier image.
 *
 */
class Stacker {
 private:

/**
 * 
 *
 * @class pixel stacker.h "GP_2_Image_Stacker/stacker.h"
 * @brief 
 *
 */
  struct pixel {
    int r, g, b;
  };

  //Height of image in pixels (column)
  int height;
  
  //Width of image in pixels (row)
  int width;

  //Maximum RGB Value (Default: 255)
  int max_color;

  //Maximum number of files to read from; used in average().
  int numFiles;

  //Name of folder and 
  std::string filename;
  std::string magic_number;
  std::vector<pixel> pixels;
  

public:
  Stacker();
  Stacker(std::string filename, int numFiles);
  
  void stack();
  void read_file();
  void average();
  
  std::string genSpecificName(std::string filename, int count);

};

#endif //STACKER_H
