#include "Shape.h"
#include <iostream>

Shape::Shape(int type){
    //i
    if(type == 1){
        cubes[0] = Cube(0,2 , "\u001b[36m██\u001b[0m");
        cubes[1] = Cube(0,1 , "\u001b[36m██\u001b[0m");
        cubes[2] = Cube(0,0 , "\u001b[36m██\u001b[0m");
        cubes[3] = Cube(0,-1, "\u001b[36m██\u001b[0m");
    }
    //T
    if(type == 2){
        cubes[0] = Cube(0,1 , "\u001b[35m██\u001b[0m");
        cubes[1] = Cube(0,0 , "\u001b[35m██\u001b[0m");
        cubes[2] = Cube(1,0 , "\u001b[35m██\u001b[0m");
        cubes[3] = Cube(-1,0, "\u001b[35m██\u001b[0m");
    }
    //j
    if(type == 3){
        cubes[0] = Cube(-1,-1, "\u001b[34m██\u001b[0m");
        cubes[1] = Cube(0,-1 , "\u001b[34m██\u001b[0m");
        cubes[2] = Cube(0,1  , "\u001b[34m██\u001b[0m");
        cubes[3] = Cube(0,0  , "\u001b[34m██\u001b[0m");
    }
    //L
    if(type == 4){
        cubes[0] = Cube(1,-1, "\u001b[33m██\u001b[0m");
        cubes[1] = Cube(0,-1, "\u001b[33m██\u001b[0m");
        cubes[2] = Cube(0,0 , "\u001b[33m██\u001b[0m");
        cubes[3] = Cube(0,1 , "\u001b[33m██\u001b[0m");
    }
    //s
    if(type == 5){
        cubes[0] = Cube(-1,1,"\u001b[32m██\u001b[0m");
        cubes[1] = Cube(0,1, "\u001b[32m██\u001b[0m");
        cubes[2] = Cube(0,0, "\u001b[32m██\u001b[0m");
        cubes[3] = Cube(1,0, "\u001b[32m██\u001b[0m");
    }
    //z
    if(type == 6){
        cubes[0] = Cube(1,1, "\u001b[31m██\u001b[0m");
        cubes[1] = Cube(0,1, "\u001b[31m██\u001b[0m");
        cubes[2] = Cube(0,0, "\u001b[31m██\u001b[0m");
        cubes[3] = Cube(-1,0,"\u001b[31m██\u001b[0m");
    }
    //0
    if(type == 7){
        cubes[0] = Cube(1,0, "\u001b[33m██\u001b[0m");
        cubes[1] = Cube(0,1, "\u001b[33m██\u001b[0m");
        cubes[2] = Cube(0,0, "\u001b[33m██\u001b[0m");
        cubes[3] = Cube(1,1, "\u001b[33m██\u001b[0m");
    }

}
void Shape::rotate(){
    for(int i = 0; i < 4; i++){
        Cube *cube = &cubes[i];

        int x_temp = -cube->y;
        cube->y =  cube->x;
        cube->x =  x_temp;
    }
}
