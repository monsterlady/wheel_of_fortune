cmake_minimum_required(VERSION 3.19)
project(wheel_of_fortune)

set(CMAKE_CXX_STANDARD 11)

add_executable(wheel_of_fortune main.cpp Cio.cpp Cio.h CWheelOfFortune.cpp CWheelOfFortune.h CPlayer.cpp CPlayer.h)