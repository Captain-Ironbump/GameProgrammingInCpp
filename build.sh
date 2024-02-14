#!/bin/bash

libs="-luser32 -lopengl32 -lgdi32"
warnings="-Wno-writable-strings"
includes="-Ithird_party -Ithird_party/Include"

clang++ $includes -g src/main.cpp -omain.exe $libs $warnings