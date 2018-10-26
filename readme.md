# RNO Engine

In order to build you will need to download CMake to compile the tests and game code. This project has the following dependencies:
* Open GL
* Alembic (File import), which in turn depends on ILMBase from OpenEXR

Below is the following command I used to generate the Makefiles on Windows (note for Linux/Unix, use "Unix Makefiles"):

```
mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" -DALEMBIC_COMPILED_INCLUDE_DIR=C:/Projects/OpenGL/alembic/vsbuild/lib -DALEMBIC_INCLUDE_DIR=C:/Projects/OpenGL/alembic/lib -DILMBASE_INCLUDE_DIR=C:/Projects/OpenGL/ilmbase-2.2.0/vsbuild/local/include/OpenEXR -DALEMBIC_LIBRARIES=C:/Projects/OpenGL/alembic/vsbuild/lib/Alembic/Release/Alembic.lib ..



```