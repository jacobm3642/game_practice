#!/bin/bash

# makes sure the build doesnt just power thought errors
set -e

export LD_LIBRARY_PATH=./libs:$LD_LIBRARY_PATH

extra_paths="-L./libs/ -I./include/"
librarys="-lraylib -lcontainers -lm"

warnings="-Wno-error=implicit-fallthrough -Wno-implicit-fallthrough -Wextra -Wall -Werror"

build_options="-std=c99 -m64"

optimized="-flto -O2 -s"
debug="-g -O0 -DDEBUG"

files=$(find ./src -name '*.c' -type f -printf "%p\n")

gcc $files $extra_paths $librarys $warnings $build_options $debug -o ./build/main
./build/main
