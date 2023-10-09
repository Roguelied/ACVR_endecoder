cmake_minimum_required(VERSION 3.26)
project(ACVR_endecoder)

set(CMAKE_CXX_STANDARD 17)

add_executable(ACVR_endecoder main.cpp
        ACVR.h
        src/Atbash.cpp
        src/Caesar.cpp
        src/Vigenere.cpp
        src/RSA.cpp
        ACVR.cpp
)
