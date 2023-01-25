#include <string>

class Cube{
    public:
        std::string graphics; //= new std::string();
        int x,y;
        Cube(){
            graphics = "██";
        }
        Cube(int ox,int oy, std::string color){
            graphics = color+"";
            x = ox;
            y = oy;
        }
        ~Cube(){
        }
};
