lp-log4cxx
=======

Repository that hosts our compiled apache log4cxx lib + headers
We have not modified this code, and all of this code belongs to the apache-log4cxx group

Currently tested on cinder 0.8.5 for Xcode 4.5 + Windows 7 Visual Studio 2010


USING THESE LIBRARIES:
======

OS X General Note:
- logstream creates undefined errors on OSX, but with the short circuited macros LOG4CXX_DEBUG(logger, "Hi " << name << "this is your debugger") it's fine for now.

OS X Xcode Usage:
- Click "Add Files to Project", where you place it in your XCode project browser doesn't really matter.
- Select the log4cxx_db.dylib (debug) or the log4cxx.lib lib.
- Select your project's "Build Phases", "Add Build Phase", "Copy Files".  Drag the dylib from the file browser on the left of XCode into the list of files for the "Copy Files" task.  Change the Destination to "Frameworks".  (Note: it may not have to be frameworks, I haven't tested).
- Select your project's "Build Settings", "Header Search Path", and add the path to the log4cxx/include directory

Windows Visual Studio 2012 Usage:

- To use the static link log4cxx library, the macro LOG4CXX_STATIC



COMPILING THESE LIBRARIES:
======

OS X COMPILATION:
- To get OS X C++11 compatability I merged some header changes in the current build branch (mainly including static_cast in places the compiler wanted it), then used the existing xcode project to compile (after upgrading the SDK etc)

WINDOWS COMPILATION:
- I checkout out the trunk from the github log4cxx
- I then downloaded the most recent visual studip project from: http://www.dreamcubes.com/b2/software-development/28/log4cxx-for-win32-with-vs2005/
- I then copied the log4cxx/src/main files into src/main of the project from dreamcubes.com
- I then had to upgrade the visual studio project file
- I then had to change the runtime types in the visual studio project to match what it was supposed to be
  * for static_debug, I changed.  project properties -> code generation -> runtime library -> multi-threaded deb ug (/MTd).  I guess during the upgrade process it lost which was a debug and which was a static.
  * This has to be done for all the projects (apr/aprutil/log4cxx/xml)

