/**
 * @file stacker.h
 * @author Kenneth Wallace, William Hayes, Jackson Horton
 * @date 2022-09-15
 * @brief This file declares the Stacker class
 * 
 * This file declares the Stacker class and it's data members/methods
 */


#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>

/**
 * The Stacker class will read the color values from all the pixels in an image into a vector of pixels. 
 * It will get important information like the width and height of the ppm image, the magic_number, and the max_color will be gathered from the first image read and applied to the final composition. 
 * Once all of the pixels are read into the pixel vector, the values for each pixel are averaged. Then, the final composition can be made.
 *
 * @class Stacker stacker.h "Image-Stacker/stacker.h"
 * @brief Stacker will take multiple images and average the values of their pixels to create a prettier image.
 *
 */
class stacker {
 private:

/**
 * A pixel storage structure.
 * Stores three color values for pixels: red (r), green (g), and blue (b).
 * Maximum value is defined by max_color, which is usually 255.
 * Each pixel is initialized to 0.
 *
 * @class pixel stacker.h "GP_2_Image_Stacker/stacker.h"
 * @brief the struct pixel will store the integer values for red (r), green (g), and blue (b) color values for each pixel
 *
 */
  struct pixel {
    int r, g, b = 0;
  };

  //Height of image in pixels (column)
  int height;
  
  //Width of image in pixels (row)
  int width;

  //Maximum RGB Value (Default: 255)
  int max_color;

  //Maximum number of files to read from; used in average().
  int numFiles;

  //Name of folder to pull .ppm files from.
  std::string filename;

  //Type of PPM file to process (Default: P3)
  std::string magic_number;

  //Pixel structure storage vector. Stores pixel structures.
  std::vector<pixel> pixels;
  

public:

  //NO DEFAULT CONSTRUCTOR

/**
 * Parameterized constructor for the stacker class.
 *
 * @param std::string filename filename input to read .ppm files from
 * @param int numFiles number of .ppm files to read in
 * @pre .ppm files to read in
 * @post 
 * 
 */
  stacker(std::string filename, int numFiles);

/**
 * 
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void stack();

/**
 * 
 *
 * @param int fileIndex 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void read_file(int fileIndex);

/**
 * 
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void average();

/**
 * 
 *
 * @param std::string filename 
 * @param int count 
 * @pre 
 * @return std::string 
 * @post 
 * 
 */
  std::string genSpecificName(std::string filename, int count);

};

#endif //STACKER_H
