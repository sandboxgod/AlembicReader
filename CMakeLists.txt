
cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 14)
project(AlembicReader)
include(CTest)

set (PROJECT_SOURCE_DIR src)

set(engine_source ${PROJECT_SOURCE_DIR}/AlembicFileReader.cpp
			${PROJECT_SOURCE_DIR}/AlembicFileReader.h
			${PROJECT_SOURCE_DIR}/Engine.cpp
			${PROJECT_SOURCE_DIR}/Logger.h
			${PROJECT_SOURCE_DIR}/Logger.cpp
              )

add_executable(AlembicReader ${engine_source})
find_package(OpenGL REQUIRED)

target_include_directories(AlembicReader PRIVATE ${PROJECT_SOURCE_DIR}/include ${OPENGL_INCLUDE_DIRS} ${ALEMBIC_INCLUDE_DIR} ${ILMBASE_INCLUDE_DIR} )

target_link_libraries(AlembicReader ${OPENGL_LIBRARIES} ${ALEMBIC_LIBRARIES} ${ILMBASE_LIB_DIR}/Half.lib )

