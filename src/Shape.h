#include "Cube.h"

class Shape{
    public:
        Shape(int type);
        int x,y;
        Cube cubes[4];
        void rotate();
        void update();
        void draw();
};

