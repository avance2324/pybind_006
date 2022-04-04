cmake_minimum_required(VERSION 3.10.2)
project(pybind_vid)

## store all header files in include/
include_directories(../Pet/include)
include(/home/fjxvn4/svn_client/my_tools/trunk/python/pybind/venv/lib/python3.7/site-packages/pybind11/share/cmake/pybind11/pybind11Config.cmake)

set( SRC_FILES
    ../Pet/src/Pet.cpp
    )
set( BIND pet_pybind.cpp)
pybind11_add_module(Pet_pybind ${SRC_FILES} ${BIND})
## can manually add the source files using set command
# set(SOURCES src/mainapp.cpp src/student.cpp)

## however, the file(GLOB...) allows for wildcard additions
#file(GLOB SOURCES "*.cpp")

set(CMAKE_BUILD_TYPE Debug)

#add_executable(test ${SOURCES})

