#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <iostream>
#include <vector>
#include <unistd.h>
#include <time.h>


using namespace std;

enum class block_type
{
    I, O, L, S, Z, T, J
};

class Tetromino{

    public:
        Tetromino(const block_type);
        Tetromino();
        Tetromino(int, int);
        void setter(const block_type);
        void rotate(const char);
        void print() const;
        inline vector<vector<char>> getShapeOfTetris() const {return (shape_of_tetris);}; //Buraya ampersant???????????**
        char get_type()const {return (type);};
    private:
        char type;
        vector<vector<char>> shape_of_tetris;

};

#endif
