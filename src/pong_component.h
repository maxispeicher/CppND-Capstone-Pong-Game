#ifndef PONG_COMPONENT_H
#define PONG_COMPONENT_H

#include <iostream>
class PongComponent
{
public:
    virtual void update() {
        std::cout << "PongComponent updated!" << std::endl;
    };
protected:
    PongComponent(int grid_width, int grid_height):
    _grid_width(grid_width), _grid_height(grid_height) {}
    int _grid_width;
    int _grid_height;
};



#endif