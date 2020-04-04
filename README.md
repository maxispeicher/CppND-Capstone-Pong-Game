# CPPND: Capstone Pong Game

This repository contains the code for the Capstone Project of the Udacity C++ Nanodegree. The code is based on the code in [this repository](https://github.com/udacity/CppND-Capstone-Snake-Game).

## Description
The code builds a Pong Game based on the original Pong Game. You can play by pressing the keys `up` and `down` for moving your "character" at the left side. The current score of the match is displayed in the title bar of the window.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## File and class structure
All source code files are located in the `src` directory.

The entrypoint for the game is in the file `main.cpp`. It creates the 3 major components of the game:
 - Controller (`controller.h` and `controller.cpp`)
 - Renderer (`renderer.h` and `renderer.cpp`)
 - Game (`game.h` and `game.cpp`)

 The Game class creates an instance of the class `PongState` which includes all necessary information about the game state. These state variables are located in multiple classes (`Puk`, `Plate` and `AiPlate`) which are all based on the base class `PongComponent`.

 ## Project rubrics
 The project fulfills the following rubric points:
  - The project demonstrates an understanding of C++ functions and control structures. 
  --> Functions and control loops are used in all classes (`*.cpp` files) 
  - The project accepts user input and processes the input. --> The project accepts up and down input for moving the "character". See `controller.cpp`
  - The project uses Object Oriented Programming techniques. --> The complete source code is organized in classes. 
  - Classes use appropriate access specifiers for class members. --> All class members have access specifiers.
  - Class constructors utilize member initialization lists. --> All class constructors use initialization lists for initializing members.
  - Classes abstract implementation details from their interfaces. --> Functionality of game components is abstracted (e.g. `update()` function of all `PongComponent`s)
  - Classes encapsulate behavior. --> Classes reflect the parts of Pong (e.g. `Puk`, `Plate` and `AiPlate`)
  - Classes follow an appropriate inheritance hierarchy. --> `PongState`, `Puk` and `Plate` classes are based on `PongComponent`. `AiPlate` is based on `Plate`.
  - Derived class functions override virtual base class functions. --> `PongState` overrides the `update()` function of the base class `PongComponent`.
  - The project makes use of references in function declarations. --> The `update()` function of the classes `Puk` and `AiPlate` uses references. 