//
//  Rectangle.hpp
//  Proj1
//
//  Created by Natasha Schmid on 9/3/20.
//

//#pragma once
#ifndef Rectangle_hpp
#define Rectangle_hpp
//#include "cinder/Cinder.h"
//
//#include "cinder/app/App.h"
//
//#include "cinder/gl/gl.h"
//
//#include "cinder/CinderMath.h"
//#include "cinder/Matrix.h"
//#include "cinder/Vector.h"
//#include "cinder/Quaternion.h"

//#include <stdio.h>
class Rectangle{
public:
    Rectangle();
    Rectangle(int xo, int yo,int xs,int ys);
    
    void run();
    void update();
    void display();
    
};
#endif /* Rectangle_hpp */
