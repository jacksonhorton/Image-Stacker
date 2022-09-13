## Author: Kenneth Wallace, William Hayes, Jackson Horton
## Group: CULT OF THE EMACS
# Makefile for Group Project 2: Image Stacker
# Last Modified: 9-12-2022
#
# Used for quickly and automatically compiling an executable.
#
# Type 'make' to create an executable for testing called "stacker".


### VARIABLES

## Compiler variable
CC = g++

## Compiler Flag variable
# Compile with debugging features and all errors + warnings.
CFLAGS = -g -Wall -Wextra

## Target Flag variable
# Contains all targets to fully compile.
# !! If adding more targets, implement them in targets and add them here so they are compiled. !!
TARGET = main.o stacker.o

## Remove Flag variable
RM = rm -i


### TARGETS

## Default entry
# Sets the default target to be called when typing 'make'.
default: all

## all
# Using $(TARGET) it will link all object (*.o) files.
# Defines name of output to "stacker".
all: $(TARGET)
	$(CC) $(CFLAGS) $(TARGET) -o stacker 

## main.o
# Requires main.cpp and all header files.
main.o: main.cpp stacker.h
	$(CC) $(CFLAGS) -c main.cpp
  
## stacker.o
# Requires stacker header and implementation files.
	stacker.o: stacker.cpp stacker.h

## clean
# Removes all unnecessary files including objects (*.o) and emacs backup (*~) files.
clean:
	$(RM) *.o *~

