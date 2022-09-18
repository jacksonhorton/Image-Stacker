# Image-Stacker
Names: William Hayes, Kenneth Wallace, and Jackson Horton
Date:9/18/2022

## Required Files
* main.cpp - runs the Stacker class methods to create a .ppm file with a cleaner picture
* stacker.h - declares the Stacker class and it's data members/methods
* stacker.cpp - implements the Stacker class and it's data members/methods


## Compilation Instructions
First, compile the program by typing into console "make". Next, run the program by typing
into console "./stacker". The user will then be prompted to type in the name of the folder
or file containing the .ppm files they wish to stack. Next, the user will be prompted as
to how many files they wish to stack; for a cleaner picture we recommend inputting the max
number of .ppm files in the file.

## Program Usage
This program is meant to take name of the file containing the .ppm files the user wishes to
stack and the number of files they wish to stack. The program will then generate the 
appropriate file name; for example, "name/name_001.ppm". It'll then open each .ppm file to
gather the total red, greed, and blue values for every pixel before dividing the values of every pixel by
the number of files stacked to get the average red, green, and blue value for each pixel.
Finally, the program will take the new average values and use them to create an .ppm file.
This new .ppm should be a cleaner, more clear picture than the old .ppm files.


Before (One image)         |  After (10 combined images)
:-------------------------:|:-------------------------:
![](https://user-images.githubusercontent.com/59177560/190923466-c9890d09-1477-4a58-bbde-b95a29916c2d.png)  |  ![](https://user-images.githubusercontent.com/59177560/190924219-507b501d-c4ce-4767-a354-36b5cc6f70fb.png)

## Notes
* We decided to not use a default constructor for every data member in this assignment, 
because we figured that since most of the data is coming from input, i.e. the user and 
.ppm files,  we could save time and lines of code by using a parameterized constructor
instead of a default constructor.
* We tried coding with 2 people at the same time for the first half of this project, but
this resulted in code being deleted, erractic behavior from github, and caused confusion.
So, needless to say we're going to code one person at a time from now on.
* When merged 2 stacker.cpp files together one of the methods was put in the middle of 
another method. So, there were some issues in that reguard.
* One way we could improve the program is by including a looping for users that want to 
stack and create multiple .ppm files. This loop could be ended by typing "q" when prompted
for the file name in main.cpp.
