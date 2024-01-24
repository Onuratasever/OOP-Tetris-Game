#ifndef TETRISARRAY1D_HPP
#define TETRISARRAY1D_HPP

//#include "TetrisAdapter.cpp"
#include "AbstractTetris.hpp"
//#include "Tetromino.hpp"
using namespace std;

namespace onur
{class TetrisArray1D : public AbstractTetris// big three
{
    public:
        TetrisArray1D(int len_of_row, int len_of_clmn);
        TetrisArray1D();
        ~TetrisArray1D();
        void draw() const;
        inline int size() const {return _size;};
        int GetLenOfRow()const{return (row);};
        int GetLenOfClmn()const{return (clmn);};
        void writeToFile(string file_name);
        bool readFromFile(string fileName);
        TetrisArray1D& operator =(const TetrisArray1D& other);
        bool isvalid_place(const Tetromino& other, int i, int j);
        void add(const Tetromino& other, int i, int j);
        void move(char move_direction, int move_count, const TetrisArray1D& temp);
        void operator += (const Tetromino& obj);
        inline char* getBoard() const {return (board);};
        void animate(const TetrisArray1D& temp, int i=-1, int j=-1);
    private:
        char *board;
        int row, _size, clmn;
};}

#endif