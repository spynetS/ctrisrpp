#include "Game.h"
#include<cstdlib>
#include <termios.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>

#define TIMER 50;

int fallTimer = TIMER;


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
    firstShape.x = 4;
    firstShape.y = 0;
    Shape *currentShape = &firstShape;

    std::vector<Cube> cubes;
    currentShape->rotate();

    while(true){
        screen.checkRows(currentShape, cubes);
        screen.update(currentShape, cubes);
         if(kbhit()){
            char key = getchar();
            if(key == 'a' && Game::collides(*currentShape,-1,0, cubes) != 1) currentShape->x--;
            if(key == 'd' && Game::collides(*currentShape,1,0, cubes) != 1) currentShape->x++;
            if(key == 's' && Game::collides(*currentShape,0,1, cubes) != 1) currentShape->y++;
            if(key == ' '){
                currentShape->y = screen.getPreview(*currentShape, cubes).y;
            }
            if(key == 'w'){
                currentShape->rotate();
                //move the piece from the wall
                int max = 0;
                while(Game::collides(*currentShape,0,0,cubes) != 0 && max < 5){
                    if(currentShape->x > 5){
                        currentShape->x--;
                    }
                    else{
                        currentShape->x++;
                    }
                    max++;
                }
            }
         }
        if(Game::collides(*currentShape,0,1, cubes)==1){
            for(int i = 0; i < 4;i++){
                Cube cube(currentShape->x+currentShape->cubes[i].x,
                        currentShape->y+currentShape->cubes[i].y,
                        currentShape->cubes[i].color,
                        currentShape->cubes[i].graphics);

                cubes.push_back(cube);
            }
            int random = 1 + (rand() % 7);
            std::cout<<random;
            Shape *shape = new Shape(random);
            shape->x = 4;
            shape->y = 0;
            currentShape = shape;
        }
        if(fallTimer == 0){
            currentShape->y ++;
            fallTimer = TIMER;
        }
        fallTimer--;
        
        std::cout << "\n\n";
    }
    return 0;
}
