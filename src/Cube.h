#include <string>

class Cube{
    public:
        std::string graphics; //= new std::string();
        int x,y;
        Cube(){
            graphics = "██";
        }
        Cube(int ox,int oy){
            graphics = "██";
            x = ox;
            y = oy;
        }
        ~Cube(){
        }
};
