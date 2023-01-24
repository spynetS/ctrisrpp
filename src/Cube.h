#include <iostream>
#include <string>

class Cube{
    public:
        std::string graphics = "██";
        int x,y;
        Cube(){}
        Cube(int ox,int oy){
            graphics = "██";
            x = ox;
            y = oy;
        }
};
