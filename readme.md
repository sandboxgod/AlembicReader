# RNO Engine

In order to build you will need to download CMake to compile the tests and game code. This project has the following dependencies:
* Open GL
* Alembic (File import), which in turn depends on ILMBase from OpenEXR. Note: I compile with ILMBase 2.2.0

Below is the following command I used to generate the Makefiles on Windows (note for Linux/Unix, use "Unix Makefiles"):

```
mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" -DALEMBIC_INCLUDE_DIR=C:/Projects/OpenGL/alembic/build/local/include -DILMBASE_INCLUDE_DIR=C:/Projects/OpenGL/ilmbase-2.2.0/build/local/include/OpenEXR -DALEMBIC_LIBRARIES=C:/Projects/OpenGL/alembic/build/local/lib/Alembic.lib -DILMBASE_LIB_DIR_=C:/Projects/OpenGL/ilmbase-2.2.0/build/local/lib ..

```

Argument to load the file should be absolute path like so
```
C:/Projects/OpenGL/Engine/assets/cube.abc
```
