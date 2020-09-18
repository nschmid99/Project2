//
//  Square.hpp
//  Project2
//
//  Created by Natasha Schmid on 9/17/20.
//

#ifndef Square_hpp
#define Square_hpp

#include <stdio.h>
#include "CinderOpenCV.h"

class Square
{
protected:
    int N;
    virtual float count(ci::Rectf)=0;
    virtual float getDivisorOfSum()=0;
    void setN(int n){N=n;}


    virtual void drawRect()
    {
        //for i,j etc.

        //do all the things to find the squares -

        ci::Rectf curSquare;
        float sum = count(curSquare);
        
        //divide sum by the appropriate numbers
        //use the result from above to change color
        //draw squares
    }
    

};



class SquaresFrameDiff : public Square
{
private:
 cv::Mat frameDiff;
public:
    virtual void drawRect(cv::Mat b)
    {
        frameDiff = b;
        Square::drawRect();
        
    }
    virtual float count(ci::Rectf curSquare)
    {
        //return the sum from the framedifferencing
        return 0;
    }
    
    float getDivisorOfSum()
    {
        return 1;
    }
    

};

class SquaresFeatures : public Square
{
    private:
    std::vector<cv::Point2f> features;
    
  public:
    virtual void drawRect(std::vector<cv::Point2f> pts)
    {
        features = pts;
        Square::drawRect();
        
    }

    virtual float count(ci::Rectf curSquare)
    {
        //return the sum of the features points
        return 0;
    }
    
    float getDivisorOfSum()
    {
        return 1;
    }
    
};



#endif /* Square_hpp */
