#include "Game.h"
#include <algorithm>
#include <chrono>
#include <thread>

Game::Game(){
    for(int i = 0; i < WIDTH*HEIGHT; i++){
        pixels[i] = ". ";
    }
}
void Game::sleep(int time){
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}
void Game::setPixel(int nx, int ny, std::string value){
    int x = 0;
    int y = 0;
    for(int i = 0; i < WIDTH*HEIGHT; i++){
        if(nx == x && ny == y){
            pixels[i] = value;
        }

        if(x == WIDTH-1){
            y++;
            x=-1;
        }
        x++;
    }
}
void Game::update(Shape *shape, std::vector<Cube> &cubes){
    //clear pixels
    for(int i = 0; i<WIDTH*HEIGHT;i++){
        pixels[i] = ". ";
    }
    for(Cube cube : cubes){
        setPixel(cube.x, cube.y, cube.graphics);
    }
    //set shapes pixels
    for(int i = 0; i < 4;i++){
        int x = shape->x;
        int y = shape->y;
        Cube cube = shape->cubes[i];
        
        setPixel(x+cube.x, y+cube.y, cube.graphics);
    }
    draw();
    sleep(20);
}
void Game::draw(){
    int x = 0;
    for(int i = 0; i < WIDTH*HEIGHT; i++){
        std::string pixel = pixels[i];
        std::cout << pixel;
        if(x == WIDTH-1){
            std::cout << "\n";
            x=-1;
        }
        x++;
    }
}
void Game::checkRows(Shape *shape,std::vector<Cube> &cubes){
    for(int i = 20; i >= 0; i--){
        int rowcount = 0;
        for(Cube cube : cubes){
            if(cube.y == i){
                rowcount ++;
            }
        }
        if(rowcount == 10){
            for(int j = 0; j < cubes.size(); j++){
                if(cubes[j].y == i){
                    cubes[j].y = 100;
                    update(shape, cubes);
                    sleep(40);
                    j=0;
                }
            }
            for(int j = 0; j < cubes.size(); j++){
                if(cubes[j].y < i){
                    cubes[j].y ++;
                }
            }
            i++;
        }
    }
}
int Game::collides(Shape shape,int x, int y, std::vector<Cube> &cubes){
    shape.y+=y; 
    shape.x+=x; 
    //next pos
    for(int i = 0; i < 4; i++){
        Cube cube = shape.cubes[i];
        for(Cube fallenCube : cubes){
            if(cube.x + shape.x == fallenCube.x &&
                cube.y + shape.y == fallenCube.y){
                return 1;
            }
        }
        if(cube.y + shape.y == HEIGHT){
            return 1;
        }
        if(cube.x + shape.x > WIDTH-1 || cube.x + shape.x < 0){
            return 2;
        }
    }

    return 0;
}
