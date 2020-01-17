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

add_library(VitaEngine SHARED ${ENGINEFILES})

file (GLOB RENDFILES
    shared/include/rend/*.cpp
    shared/include/rend/*.h)
    
add_library(rend SHARED ${RENDFILES})
    
if(MSVC)
  target_link_libraries(rend SDL2 glew32 OpenGL32 OpenAL32)
else()
  target_link_libraries(rend SDL2 GLEW GL openal)
endif()

target_link_libraries(VitaEngine rend)

add_executable(afos2
        src/game/main.cpp
)

target_link_libraries(afos2 VitaEngine)
