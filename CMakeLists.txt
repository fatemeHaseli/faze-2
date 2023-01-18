cmake_minimum_required(VERSION 3.0)
project (FATEME)
set (CMAKE_CXX_STANDARD 11)
add_executable (app 
src/main.cpp 
src/room.cpp 
src/bathroom.cpp 
src/operatingRoom.cpp 
src/hospitalMorgue.cpp
src/game.cpp
src/patient.cpp
src/block.cpp
src/ExtraSlut.cpp
src/reception.cpp
src/restSlut.cpp
src/ICU.cpp
)
include_directories (include) 
target_link_libraries(app sfml-system sfml-window sfml-graphics)