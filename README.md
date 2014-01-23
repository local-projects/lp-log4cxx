lp-log4cxx
=======

Repository that hosts our compiled apache log4cxx binaries + headers

We have not modified this code, and all of this code belongs to the apache-log4cxx group



OS X:
- logstream creates undefined errors on OSX, but with the short circuited macros LOG4CXX_DEBUG(logger, "Hi " << name << "this is your debugger") it's fine for now.

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

Windows:
- To use the static link log4cxx library, the macro LOG4CXX_STATIC