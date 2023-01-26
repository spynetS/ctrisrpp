#define WIDTH 10
#define HEIGHT 20

#include <vector>
#include "Shape.h"
#include <iostream>
#include <string>


class Game{
    public:
        std::string BG = ". ";
        Game();
        void draw();
        void update(Shape *shape, std::vector<Cube> &cubes);
        std::string pixels[WIDTH*HEIGHT];
        void setPixel(int x, int y, std::string value);
        static int collides(Shape shape,int x, int y, std::vector<Cube> &cubes);
        void checkRows(Shape *shape, std::vector<Cube> &cubes);
        void sleep(int ms);
        Shape getPreview(Shape currentShape, std::vector<Cube> cubes);
};
