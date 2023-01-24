#include "Shape.h"
#include <iostream>



Shape::Shape(int type){
    graphics = 'x';
    std::cout<<type;
    //i
    if(type == 1){
        cubes[0] = Cube(0,3);
        cubes[1] = Cube(0,2);
        cubes[2] = Cube(0,1);
        cubes[3] = Cube(0,0);
    }
    //T
    if(type == 2){
        cubes[0] = Cube(0,1);
        cubes[1] = Cube(0,0);
        cubes[2] = Cube(1,0);
        cubes[3] = Cube(-1,0);
    }
    //j
    if(type == 3){
        cubes[0] = Cube(1,1);
        cubes[1] = Cube(0,1);
        cubes[2] = Cube(-1,1);
        cubes[3] = Cube(-1,0);
    }
    //l
    if(type == 4){
        cubes[0] = Cube(-1,2);
        cubes[1] = Cube(0,0);
        cubes[2] = Cube(0,2);
        cubes[3] = Cube(0,1);
    }
    //s
    if(type == 5){
        cubes[0] = Cube(-1,1);
        cubes[1] = Cube(0,1);
        cubes[2] = Cube(0,0);
        cubes[3] = Cube(1,0);
    }
    //z
    if(type == 6){
        cubes[0] = Cube(1,1);
        cubes[1] = Cube(0,1);
        cubes[2] = Cube(0,0);
        cubes[3] = Cube(-1,0);
    }
    //0
    if(type == 7){
        cubes[0] = Cube(1,0);
        cubes[1] = Cube(0,1);
        cubes[2] = Cube(0,0);
        cubes[3] = Cube(1,1);
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
