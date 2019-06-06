cmake_minimum_required (VERSION 2.6)

project (FuncLang)
set (CMAKE_CXX_STANDART 11)
add_executable(FuncLang sources/Main.cpp sources/StrParser.cpp headers/StrParser.h sources/Evaluator.cpp headers/Evaluator.h)
