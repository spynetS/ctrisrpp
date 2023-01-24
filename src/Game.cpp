#include "Game.h"

Game::Game(){
    for(int i = 0; i < WIDTH*HEIGHT; i++){
        pixels[i] = ". ";
    }
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
    for(int i = 0; i<4;i++){
        int x = shape->x;
        int y = shape->y;
        Cube cube = shape->cubes[i];
        
        setPixel(x+cube.x, y+cube.y, cube.graphics);
    }
    draw();
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
bool Game::collides(Shape shape, std::vector<Cube> &cubes){
    shape.y++; 
    //next pos
    for(int i = 0; i < 4; i++){
        Cube cube = shape.cubes[i];
        for(Cube fallenCube : cubes){
            if(cube.x + shape.x == fallenCube.x &&
                    cube.y + shape.y == fallenCube.y){
                return true;
            }
        }
        if(cube.y + shape.y == HEIGHT-1){
            return true;
        }
    }

    return false;
}
