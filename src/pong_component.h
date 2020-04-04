#ifndef PONG_COMPONENT_H
#define PONG_COMPONENT_H

class PongComponent
{
public:
    virtual void update() = 0;
protected:
    PongComponent(int grid_width, int grid_height):
    _grid_width(grid_width), _grid_height(grid_height) {}
    int _grid_width;
    int _grid_height;
};



#endif