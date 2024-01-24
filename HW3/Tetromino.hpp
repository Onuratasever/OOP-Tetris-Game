#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <iostream>
#include <unistd.h>
#include <time.h>

using namespace std;

enum class block_type
{
    I, O, L, S, Z, T, J
};
namespace Onur
{
    class Tetromino{

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