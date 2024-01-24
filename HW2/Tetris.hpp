#ifndef TETRIS_HPP
#define TETRIS_HPP

#include <iostream>
#include <vector>
#include <unistd.h>
#include <time.h>
#include "Tetromino.hpp"

using namespace std;

class Tetris
{
    public:
        
        Tetris(int len_of_row, int len_of_clmn);
        bool Fit(Tetromino other, char increase);
        void draw() const;
        Tetromino &get_Tetro_Obj(){return ( tetro_obj);}
        inline vector<vector<char>> getBoard() const {return (board);};
        int GetLenOfRow()const{return (row);};
        int GetLenOfClmn()const{return (clmn);};
        int isvalid_place(vector<vector<char>> matrix, const Tetromino other, int i, int j);
        void add(vector<vector<char>> & matrix, const Tetromino other, int i, int j);
        int how_many_rotate(Tetromino obj, int rotate_number, int coordinat1, int coordinat2, vector<vector<char>> matrix);
        void lenght_of_object(int &len_of_vertical, const Tetromino& other);

    private:
        Tetromino tetro_obj;
        int row, clmn;
        vector<vector<char>> board;
};

#endif