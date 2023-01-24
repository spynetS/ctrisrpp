#include <chrono>
#include <thread>
#include "Game.h"
#include<cstdlib>
#include <termios.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
  
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  
  ch = getchar();
  
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  
  if(ch != EOF)
  {
      ungetc(ch, stdin);
      return 1;
  }
  
  return 0;
}
int main() {
    Game screen = Game();
    Shape firstShape(7);
    firstShape.x = 3;
    firstShape.y = 0;
    Shape *currentShape = &firstShape;

    std::vector<Cube> cubes;
    currentShape->rotate();

    while(true){
        screen.update(currentShape, cubes);
         if(kbhit()){
            char key = getchar();
            if(key == 'a') currentShape->x--;
            if(key == 'd') currentShape->x++;
         }
        if(Game::collides(*currentShape, cubes)){
            for(int i = 0; i < 4;i++){
                Cube cube = currentShape->cubes[i];
                cube.x += currentShape->x;
                cube.y += currentShape->y;
                cubes.push_back(cube);
            }
            int random = 1 + (rand() % 7);
            std::cout<<random;
            Shape shape(random);
            shape.x = currentShape->x+1;
            shape.y = 0;
            currentShape = &shape;
        }else{
            currentShape->y ++;
        }
        
        //sleep
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(200ms);
        std::cout << "\n\n";
    }
    return 0;
}
