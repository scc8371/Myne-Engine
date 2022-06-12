#!/bin/bash
x86_64-w64-mingw32-g++ -o bearger.exe bearger.cpp -L ../../Myne -I ../../ -I ../../library -l Myne -l glfw3 -static-libgcc -static-libstdc++
