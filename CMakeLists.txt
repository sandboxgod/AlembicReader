
cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 14)
project(RNOEngine)
include(CTest)

file(GLOB engine_SRC
    "src/*.h"
    "src/*.cpp"
)
add_executable(RNOEngine ${engine_SRC})
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} ${ALEMBIC_INCLUDE_DIR} ${ALEMBIC_COMPILED_INCLUDE_DIR} ${ILMBASE_INCLUDE_DIR} )

target_link_libraries(RNOEngine ${OPENGL_LIBRARIES} ${ALEMBIC_LIBRARIES} ${ILMBASE_LIBRARIES} )

