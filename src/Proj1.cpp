
/*
 
 Programmer: Courtney Brown
 Date: c2019
 Notes: Demonstration of frame-differencing and subtraction
 Purpose/Description:
 
 This program demonstrates simple frame-differencing
 
 Uses:
 
 cv::absdiff - finds the difference between two frames (in cv::Mat format)
 
 cv::GaussianBlur - Blurs the image. The amount of blur is how sensitive the frame-differencing is to motion.
 
 cv::Threshold - Thresholds the image. You may try to see the results of this on the current frame (I encourage you). It simply replaces values between 0.0 & 1.0 with EITHER 1 or 0, so that greys are removed. This has been used in the past
    for extremely simple background subtration / foreground detection / image segmentation.
 See OpenCV Tutorial here:
 https://docs.opencv.org/3.1.0/db/d8e/tutorial_threshold.html
 
 Output/Drawing:
 Draws the result of simple frame-differencing. Subtracts current frame from the previous. Acts as an effective motion detector.
 
 Instructions:
 Copy and paste this code into your cpp file.
 
 Run. Observe the results. Change some of the parameters.
 
 For your project, you can probably start with creating the squares of the data without further information/lecture
 
 For the background subtraction, we will need the lecture/explanation to move forward.
 
 */


#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/tracking.hpp>

//includes for background subtraction
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/video.hpp>


#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Capture.h" //needed for capture
#include "cinder/Log.h" //needed to log errors

#include "Osc.h" //add to send OSC

#include <math.h>
#include "Rectangle.hpp"

#include "CinderOpenCV.h"

using namespace ci;
using namespace ci::app;
using namespace std;

int n=10;
int co=0;
int cq=0;
//Rectangle rr();
Rectangle rr;
class FrameDifferencingApp : public App {
  public:
    void setup() override;
    void keyDown( KeyEvent event ) override;

    void update() override;
    void draw() override;
    
  protected:
    CaptureRef                 mCapture;
    gl::TextureRef             mTexture;
    
    //for framedifferencing
    cv::Mat                    mPrevFrame;
    cv::Mat                    mFrameDifference;
    ci::SurfaceRef             mSurface;

    void frameDifference(cv::Mat &outputImg);
    
};

//initialization
void FrameDifferencingApp::setup()
{
    //set up our camera
    try {
        mCapture = Capture::create(640, 480); //first default camera
        mCapture->start();
    }
    catch( ci::Exception &exc)
    {
        CI_LOG_EXCEPTION( "Failed to init capture ", exc );
    }
    
    mPrevFrame.data = NULL;
    mFrameDifference.data = NULL;
    
//    int x=getWindowWidth()/n;
//    int y=getWindowHeight()/n;
////
//
//    for(int i=0;i<=n;i++){
//          for(int j=0;j<=n;j++){
//
//     Rectangle rr(i*x,j*y,x*(i+1),y*(j+1));
//             // rr.display();
//
//          }}


    
}

void FrameDifferencingApp::keyDown( KeyEvent event )
{
    //TODO: save the current frame as the background image when user hits a key
    
    //eg:
    if(event.getChar() == 'a')
    {
        //TODO: do a thing. Like save the current frame.
        gl::clear( Color( 0, 0, 0 ) );
        gl::color( 1, 0, 0, 1 );
        std::cout<<"key"<<std::endl;
    }
  

}

void FrameDifferencingApp::update()
{
    int l;
    int k;
    if(mCapture && mCapture->checkNewFrame()) //is there a new frame???? (& did camera get created?)
    {
        mSurface = mCapture->getSurface();

        if(! mTexture)
            mTexture = gl::Texture::create(*mSurface);
        else
            mTexture->update(*mSurface);
    }
    
    //do the frame-differencing
    frameDifference(mFrameDifference);
    
//    for( k=0;k<getWindowWidth();k++){    //cycle through thewebcam
//              for(l=0;l<getWindowHeight();l++){
//                  mFrameDifference.at<uint8_t>(l,k);    //find value for pixels at (k,l);
//
//   std:: cout << "r" <<  mFrameDifference.at<int>(l,k)<<std::endl;
//              }
      for( k=0;k<getWindowWidth();k++){    //cycle through thewebcam
             for(l=0;l<getWindowHeight();l++){
               mFrameDifference.at<uint8_t>(l,k);    //find value for pixels at (k,l);
//                  if(mFrameDifference.at<uint8_t>(l,k)==255.0){   //if the pixel  has a value of 255 (white)
                      //std:: cout << "l "<<pixel<<std::endl;
//                      int x=getWindowWidth()/n;
//                                              int y=getWindowHeight()/n;
//                                             for(int i=0;i<=n;i++){
//                                                   for(int j=0;j<=n;j++){
//                                                       if(x*i<l<x*(i+1)){ if(y*i<k<y*(i+1)){
                                                             // std:: cout << "works "  <<std::endl;
                                                           //rr.update();
                      
                  //}
                                                           //else
                      //std:: cout << "black "<<std::endl;
                                                       //}}}
                 if(mFrameDifference.data){    //if the matrix isntempty
                 
                      
                              std:: cout << "black "<< std::endl;
                       

                        }

                  }
                
  
                  }

    
    
//        if(mFrameDifference.at<uint8_t>(l,k)==255.0){   //if the pixel  has a value of 255 (white)
//                         std:: cout << "l,k "<<std::endl;
                         //turn rectangle white. find what rectangle pixel is located in
                      
                        
    
}


//find the difference between 2 frames + some useful image processing
void FrameDifferencingApp::frameDifference(cv::Mat &outputImg)
{
    
    outputImg.data = NULL;
    if(!mSurface) return;

    //the current surface or frame in cv::Mat format
    cv::Mat curFrame = toOcv(Channel(*mSurface));
    
    if(mPrevFrame.data){
        
        //blur --> this means that it will be resilient to a little movement
        //params are: cv::Mat Input1,
//                    cv::Mat Result,
//                    cv::Size - size of blur kernel (correlates to how blurred - must be positive & odd integers),
//                               the bigger the size, the more the blur & also the larger the sigmas the more the blur.
//                    double size of sigma X Gaussian kernel standard deviation in X direction
//                    double size of sigma Y Gaussian kernel standard deviation in Y direction (optional, not used)
//      More on Gaussian blurs here: https://homepages.inf.ed.ac.uk/rbf/HIPR2/gsmooth.htm
//      Interestingly, we can think of them as a low-pass filter in 2D -- (if you know them from audio dsp, sound)
        cv::GaussianBlur(curFrame, curFrame, cv::Size(3,3), 0);

        //find the difference
        //params are: cv::Mat Input1, cv::Mat Input2, cv::Mat Result
        cv::absdiff(curFrame, mPrevFrame, outputImg);
        
        //take threshhold values -- think of this as image segmentation, see notes above in desc. header
        //we will go further into image segmentation next week
//        https://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html?highlight=threshold#threshold
//    Parameters:
//        src – input array (single-channel, 8-bit or 32-bit floating point).
//        dst – output array of the same size and type as src.
//        thresh – threshold value.
//        maxval – maximum value to use with the THRESH_BINARY and THRESH_BINARY_INV thresholding types.
//        type – thresholding type (see the details below).
        cv::threshold(outputImg, outputImg, 25, 255, cv::THRESH_BINARY);

    }
    
    mPrevFrame = curFrame;
}

void FrameDifferencingApp::draw()
{
  


        
    gl::clear( Color( 0, 0, 0 ) );

    gl::color( 1, 1, 1, 1 );
    

    //if the frame difference isn't null, draw it.
    if( mFrameDifference.data )
    {
        gl::draw( gl::Texture::create(fromOcv(mFrameDifference) ) );
        int x=getWindowWidth()/n;
         int y=getWindowHeight()/n;
//
         for(int i=0;i<=n;i++){
             for(int j=0;j<=n;j++){

                 Rectangle rr(i*x,j*y,x*(i+1),y*(j+1));
                 //rr.display();
             }}
    }
    
}

CINDER_APP( FrameDifferencingApp, RendererGl )
