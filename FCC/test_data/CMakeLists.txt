cmake_minimum_required(VERSION 3.10)

project(FCC VERSION 1.0 DESCRIPTION "Friendly Communication Checker")
add_executable(fcc main.cpp fcc.cpp)
set_property(TARGET fcc PROPERTY CXX_STANDARD 20)
