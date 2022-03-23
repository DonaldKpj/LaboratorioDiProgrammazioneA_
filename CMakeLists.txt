cmake_minimum_required(VERSION 3.15)
project(LaboratorioDiProgrammazioneA_)

set(EXECUTABLE_NAME LaboratorioDiProgrammazioneA_)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MapSearchNode.cpp MapSearchNode.h Mappa.cpp Mappa.h Obbiettivo.cpp Obbiettivo.h Personaggio.cpp Personaggio.h Schermo.cpp Schermo.h fsa.h stlastar.h)
add_executable(LaboratorioDiProgrammazioneA_ ${SOURCE_FILES})

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(LaboratorioDiProgrammazioneA_ sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

add_subdirectory(test)
add_library(core ${SOURCE_FILES})
target_link_libraries(LaboratorioDiProgrammazioneA_ core)