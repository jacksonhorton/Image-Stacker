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
 * @post creates a stacker object
 * 
 */
  stacker(std::string filename, int numFiles);

/**
 * Calls all other functions in this order:
 * read_file() to read in all files
 * average() to average out all the pixel ints
 * 
 * It then creates an output file with all of the average values.
 *
 * @pre A folder to read from (that exists)
 * @post output file created, pixels vector has averaged values within it.
 * 
 */
  void stack();

/**
 * Reads in a file to straight into the pixels vector, if a element within the vector is null it will define a pixel struct within that element and fill it.
 *
 * @param int fileIndex file to read from
 * @pre a folder to read from (that exists)
 * @post file is read into the pixels vector
 * 
 */
  void read_file(int fileIndex);

/**
 * Averages out all integer values within the pixels vector by dividing them by numFiles.
 *
 * @pre a pixels vector to modify
 * @post averages out all integer values within the pixels vector.
 * 
 */
  void average();

/**
 * Generates the file path using the given filename.
 *
 * @param std::string filename given filename
 * @param int count the number of images to stack
 * @pre a filename and number of images
 * @return std::string a file path to pass to an fstream.
 * 
 */
  std::string genSpecificName(std::string filename, int count);

};

#endif //STACKER_H
