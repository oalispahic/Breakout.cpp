//
// Created by Omar Alispahic on 23. 7. 2025..
//
#include <iostream>
#ifndef BREAKOUT___OBJECTS_H
#define BREAKOUT___OBJECTS_H

struct Point{
    int x,y;
    int angleFactor;
};

class Paddle{
    Point * elements;
    int size = 0;
public:
    Paddle(int x = 10, int y = 17, int size = 5): size(size){
        elements = new Point[size];
        for(int i = 0; i<size; i++){
            elements[i].x = i+x;
            elements[i].y = y;
        }
    }

    int paddleSize() const {return size;}

    Point pointArray(int num){return elements[num];}

    void updateX(int num);

    /*void testPrint(){
        for(int i = 0; i<size; i++){
            std::cout<<"point["<<i<<"]"<<"= "<<elements[i].x<<" "<<elements[i].y<<'\n';
        }
    }*/

};

void Paddle::updateX(int num) {
    for(int i = 0; i<size; i++){
        elements[i].x+=num;
    }
}

#endif //BREAKOUT___OBJECTS_H
