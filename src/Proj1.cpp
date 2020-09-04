#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/tracking.hpp>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "CinderOpenCV.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Proj1 : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void Proj1::setup()
{
}

void Proj1::mouseDown( MouseEvent event )
{
}

void Proj1::update()
{
}

void Proj1::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( Proj1, RendererGl )
