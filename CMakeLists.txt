cmake_minimum_required(VERSION 3.16)
project(spectrometer)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.h)

add_executable(spectrometer main.cpp ${sources} ${headers})
target_link_libraries(spectrometer ${Geant4_LIBRARIES})

