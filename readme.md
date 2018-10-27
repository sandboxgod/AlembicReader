# Alembic Reader

In order to build you will need to download CMake to compile the tests and game code. This project has the following dependencies:

* [Alembic](http://www.alembic.io/) (File import), which in turn depends on ILMBase from OpenEXR. Note: I compile with ILMBase 2.2.0
* [CMake](https://cmake.org/), which allows this project to compile on different platforms. 

## Building this Project

Below is the following command I used to generate the Makefiles on Windows (note for Linux/Unix, use "Unix Makefiles"):

```
mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" -DALEMBIC_INCLUDE_DIR=C:/Projects/OpenGL/alembic/build/local/include -DILMBASE_INCLUDE_DIR=C:/Projects/OpenGL/ilmbase-2.2.0/build/local/include/OpenEXR -DALEMBIC_LIBRARIES=C:/Projects/OpenGL/alembic/build/local/lib/Alembic.lib -DILMBASE_LIB_DIR=C:/Projects/OpenGL/ilmbase-2.2.0/build/local/lib ..

```

Argument to load the file should be absolute path like so:
```
C:/Projects/OpenGL/Engine/assets/cube.abc
```

### Building Alembic & Ilmbase

Building these libraries may or may not be trivial depending upon your experience with CMake and various libraries. What I personally did was build everything statically (rather than as dynamic libs). Also, I set the target folder (via -DCMAKE_INSTALL_PREFIX=local) argument to CMake so that all of my compiled sources and libs are saved into the same folder.
