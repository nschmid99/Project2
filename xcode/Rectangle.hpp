//
//  Rectangle.hpp
//  Proj1
//
//  Created by Natasha Schmid on 9/3/20.
//


#ifndef Rectangle_hpp
#define Rectangle_hpp

class Rectangle{
public:
    Rectangle();
    Rectangle(int xo, int yo,int xs,int ys);
    
    void run();
    void display();
    void update(int r1, int g1, int b1);//int c);
    //bool haspoint();
   
    
};
#endif /* Rectangle_hpp */
