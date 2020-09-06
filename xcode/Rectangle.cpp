//
//  Rectangle.cpp
//  Proj1
//
//  Created by Natasha Schmid on 9/3/20.
//

#include "Rectangle.hpp"
//#include "CinderOpenCV.h"
//#include "cinder/app/App.h"
//#include "cinder/app/RendererGl.h"
//#include "cinder/gl/gl.h"
using namespace ci;
using namespace ci::app;
Rectf curSquare;
int x1;
int x2;
int y;
int y2;
Rectangle::Rectangle(){     //create rectangle class
}
Rectangle::Rectangle(int xo, int yo,int xs,int ys){     //initialize rectangle class
    x1=xo;      //upper left corner xpos
    x2=xs;      //bottom right corner xpos
    y=yo;       //upper left corner ypos
    y2=ys;      //bottom right corner ypos
   curSquare = Rectf(x1, y, x2, y2); //x1, y1 is top left corner x2, y2 is bottom right corner
}

void Rectangle::display(){
    gl::drawSolidRect(curSquare);   //when called draws square to screen
}

