#!/bin/bash

libs=-luser32
warnings=-Wno-writable-strings

clang src/main.cpp -omain.exe $libs $warnings