# Notes

1. KaleidoscopeJIT.h copied from llvm 18.1.7 source tree: examples/Kaleidoscope/include/KaleidoscopeJIT.h
   (I'm attempting to build with 18.1.5, maybe inviting trouble here).
2. Using xo-cmake cmake macros.  To install:
   ```
   $ cd ~/proj
   $ git clone https://github.com/Rconybea/xo-cmake.git  # creates xo-cmake
   $ cd xo-cmake
   $ PREFIX=/usr/local                                   # ..or desired install location;  want PREFIX/bin in PATH
   $ cmake -DCMAKE_INSTALL_PREFIX=${PREFIX} -B .build -S .
   $ cmake --install -B .build
   ```

# Chapters

1. See `kaleidoscope1.cpp`.  Language and lexer.
2. See `kaleidoscope2.cpp`.  Parser and AST (abstract syntax tree)
3. See `kaleidoscope3.cpp`.  [accidentally merged into kaleidoscope4.cpp] Code generation to LLVM IR
4. See `kaleidoscope4.cpp`.  Adds JIT and optimizer support
5. See `kaleidoscope5.cpp`.  Adds if-then-else and for loops
6. See `kaleidoscope6.cpp`.  Adds user-defined operators.
7. See `kaleidoscope7.cpp`.  Mutable Variables
8. See `kaleidoscope8.cpp`.  Compiling to object code
