#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <iostream>
#include <unistd.h>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
//#include "AbstractTetris.hpp"
using namespace std;

namespace onur
{enum class block_type
{
    I, O, L, S, Z, T, J
};

class Tetromino
{

    public:
        Tetromino(const block_type);
        Tetromino();
        Tetromino(int, int);
        ~Tetromino();
        void setter(const block_type);
        void rotate(const char);
        void print() const;
        inline char** getShapeOfTetris() const {return (shape_of_tetris);}; // modifiye ediyo muyum ever :(
        char get_type()const {return (type);}; // silincek
    private:
        char type;
        char** shape_of_tetris;

};
}

#endif