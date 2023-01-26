#include "Game.h"
#include <algorithm>
#include <chrono>
#include <thread>
#include <stdlib.h>

Game::Game(){
    for(int i = 0; i < WIDTH*HEIGHT; i++){
        pixels[i] = BG;
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
            pixels[i] = value+"\u001b[0m";
        }

        if(x == WIDTH-1){
            y++;
            x=-1;
        }
        x++;
    }
}
void Game::update(Shape *shape, std::vector<Cube> &cubes){
    system ("clear");
    //clear pixel,s
    for(int i = 0; i<WIDTH*HEIGHT;i++){
        pixels[i] = BG;
    }
    for(Cube cube : cubes){
        setPixel(cube.x, cube.y, cube.color + cube.graphics);
    }
    Shape preview = getPreview(*shape, cubes);
    //set shapes pixels
    for(int i = 0; i < 4;i++){
        int x = shape->x;
        int y = shape->y;
        Cube cube = shape->cubes[i];
        setPixel(x+cube.x, y+cube.y, cube.color + cube.graphics);

        int px = preview.x;
        int py = preview.y;
        Cube pcube = preview.cubes[i];
        setPixel(px+pcube.x, py+pcube.y, pcube.color + pcube.graphics);
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
                    sleep(20);
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
Shape Game::getPreview(Shape currentShape, std::vector<Cube> cubes){
    Shape shape(currentShape.type);
    shape.x = currentShape.x;
    shape.cubes[0] = currentShape.cubes[0];
    shape.cubes[1] = currentShape.cubes[1];
    shape.cubes[2] = currentShape.cubes[2];
    shape.cubes[3] = currentShape.cubes[3];
    shape.cubes[0].graphics = "[]";
    shape.cubes[1].graphics = "[]";
    shape.cubes[2].graphics = "[]";
    shape.cubes[3].graphics = "[]";

    for(int i = 0; i < 20; i++){
        shape.y = i;
        if(collides(shape, 0,1,cubes)){
            return shape;
        }
    }
    return shape;
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
