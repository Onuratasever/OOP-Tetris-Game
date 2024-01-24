#ifndef TETRISVECTOR_HPP
#define TETRISVECTOR_HPP

//#include "TetrisArray1D.hpp"
#include "AbstractTetris.hpp"
using namespace std;

namespace onur
{class TetrisVector : public AbstractTetris // destructor???? big three
{
    public:
        TetrisVector(int len_of_row, int len_of_clmn);
        TetrisVector();
        void draw()const;
        int GetLenOfRow()const{return (row);};
        int GetLenOfClmn()const{return (clmn);};
        bool isvalid_place(const Tetromino& other, int i, int j);
        void add(const Tetromino& other, int i, int j);
        void writeToFile(string file_name);
        bool readFromFile(string fileName);
        inline vector<vector<char>> getBoard() const {return board;};
        void operator += (const Tetromino& obj);
        void move(char move_direction, int move_count, const TetrisVector& temp);
        void animate(const TetrisVector& temp, int i=-1, int j=-1);
        TetrisVector& operator =(const TetrisVector& other);

    private:
        vector<vector<char>> board;
        int row, clmn;
};}

#endif