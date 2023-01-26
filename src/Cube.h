#include <string>

class Cube{
    public:
        std::string graphics; //= new std::string();
        std::string color; //= new std::string();
        int x,y;
        Cube(){
            graphics = "██";
        }
        Cube(int ox,int oy, std::string color, std::string graphics){
            this->color = color;
            this->graphics = graphics;
            x = ox;
            y = oy;
        }
        Cube(int ox,int oy, std::string color){
            this->color = color;
            graphics = "██";
            x = ox;
            y = oy;
        }
        ~Cube(){
        }
};
