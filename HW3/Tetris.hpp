#ifndef TETRIS_HPP
#define TETRIS_HPP

#include <iostream>
#include <unistd.h>
#include <time.h>
#include "Tetromino.hpp"

using namespace std;
namespace Onur
{
    class Tetris
    {
        public:
            
            Tetris(int len_of_row, int len_of_clmn);
            ~Tetris();
            void draw() const;
            Tetromino &get_Tetro_Obj(){return ( tetro_obj);}
            inline char** getBoard() const {return (board);};
            int GetLenOfRow()const{return (row);};
            int GetLenOfClmn()const{return (clmn);};
            bool isvalid_place(const Tetromino& other, int i, int j);// tetrominodaki constları kaldırdım yav
            void add(const Tetromino& other, int i, int j);// tetrominodaki constları kaldırdım yav
            void lenght_of_object(int &len_of_vertical,const Tetromino& other);// tetrominodaki constları kaldırdım yav BİDE BUNU TETROMİNOYA ÇEVİR
            void operator += (const Tetromino& obj);
            void move(char move_direction, int move_count, const Tetris& temp);
            void animate(const Tetris& temp, int i=-1, int j=-1);

        private:
            Tetromino tetro_obj;
            int row, clmn;
            char** board;//BUNU DA ARRAYE ÇEVİRİCEM
    };
}
#endif