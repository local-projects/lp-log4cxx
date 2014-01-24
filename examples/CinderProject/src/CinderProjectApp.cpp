#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

//log4cxx
#include <log4cxx/logger.h>
#include "log4cxx/propertyconfigurator.h"
#include <log4cxx/basicconfigurator.h>


using namespace ci;
using namespace ci::app;
using namespace std;

using namespace log4cxx;
using namespace log4cxx::helpers;

class CinderProjectApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    LoggerPtr logger;
};

void CinderProjectApp::setup()
{
    
    string logFile = getAssetPath("log4j.properties").string();
    
    if( ! logFile.empty() ) {
        PropertyConfigurator::configure(logFile);
    } else {
        BasicConfigurator::configure();
    }
    
    logger = Logger::getLogger("lp.logger");
    
    LOG4CXX_INFO(logger, "LP Logger initialized." );
    int var = 10;
    LOG4CXX_INFO(logger, "This is an example of short circuited output, the var = " << var );
    
}

void CinderProjectApp::mouseDown( MouseEvent event )
{
}

void CinderProjectApp::update()
{
    LOG4CXX_TRACE(logger, "This is how you flood your console, if you enable TRACE.");    
}

void CinderProjectApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( CinderProjectApp, RendererGl )
