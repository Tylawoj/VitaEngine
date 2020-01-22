cmake_minimum_required(VERSION 2.6)

project(VitaEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#uncomment below line for debugging
#add_definitions(-DSTD_SR1_DEBUG)

include_directories(
        shared/include
	src
)

file(GLOB ENGINEFILES
        src/engine/*.cpp
        src/engine/*.h)

if(MSVC)
  add_library(VitaEngine STATIC ${ENGINEFILES})
else()
  add_library(VitaEngine SHARED ${ENGINEFILES})
endif()

file (GLOB RENDFILES
    shared/include/rend/*.cpp
    shared/include/rend/*.h)

if(MSVC)
  add_library(rend STATIC ${RENDFILES})
else()
  add_library(rend SHARED ${RENDFILES})
endif()  

if(MSVC)
  target_link_libraries(rend SDL2 glew32 OpenGL32 OpenAL32)
else()
  target_link_libraries(rend SDL2 GLEW GL openal)
endif()

target_link_libraries(VitaEngine rend)

add_executable(dontfall
        src/game/main.cpp
        src/game/Player.cpp
        src/game/Player.h
)

target_link_libraries(dontfall VitaEngine)
