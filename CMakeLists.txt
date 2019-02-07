cmake_minimum_required(VERSION 3.13)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

add_executable(TicTacToe main.cpp Player.hpp Player.cpp Board.hpp Board.cpp AutoPlayer.hpp AutoPlayer.cpp)