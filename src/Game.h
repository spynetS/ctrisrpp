#define WIDTH 10
#define HEIGHT 10
#include <vector>
#include "Shape.h"
#include <iostream>

class Game{
    public:
        Game();
        void draw();
        void update(Shape *shape, std::vector<Cube> &cubes);
        int pixels[WIDTH*HEIGHT];
        void setPixel(int x, int y, int value);
        static bool collides(Shape shape, std::vector<Cube> &cubes);
};
