//
//  Rectangle.cpp
//  Proj1
//
//  Created by Natasha Schmid on 9/3/20.
//

#include "Rectangle.hpp"

using namespace ci;
using namespace ci::app;
Rectf curSquare;
int x1;
int x2;
int y;
int y2;
int r;
int g;
int b;
//int c;
Rectangle::Rectangle(){     //create rectangle class
}
Rectangle::Rectangle(int xo, int yo,int xs,int ys){     //initialize rectangle class
    x1=xo;      //upper left corner xpos
    x2=xs;      //bottom right corner xpos
    y=yo;       //upper left corner ypos
    y2=ys;      //bottom right corner ypos
   curSquare = Rectf(x1, y, x2, y2);
 //x1, y1 is top left corner x2, y2 is bottom right corner
}


void Rectangle::display(){
   // gl::color(0,1,0,1);
    gl::drawSolidRect(curSquare);   //when called draws square to screen
}
