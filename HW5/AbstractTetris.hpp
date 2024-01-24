#ifndef ABSTRACTTETRIS_HPP
#define ABSTRACTTETRIS_HPP

//#include "TetrisVector.hpp"
#include "Tetromino.hpp"
using namespace std;
namespace onur
{class AbstractTetris
{
    public:
        AbstractTetris();
        int numberOfMoves()const{return number_of_moves;};
        void increment_of_moves(){++number_of_moves;};
        virtual void draw() const = 0;
        Tetromino &get_Tetro_Obj(){return ( tetro_obj);}
        void setlastMove();
        string& set_lastmove(){return _lastmove;};
        void lastMove() const;
        virtual void writeToFile(string file_name)=0;
        virtual int GetLenOfRow() const = 0;
        virtual int GetLenOfClmn() const = 0;
        virtual bool readFromFile(string fileName)=0;
        virtual bool isvalid_place(const Tetromino& other, int i, int j) = 0;
        virtual void add(const Tetromino& other, int i, int j) = 0;
        void lenght_of_object(int &len_of_vertical,const Tetromino& other);
        virtual void operator += (const Tetromino& obj) = 0;

    protected:
        Tetromino tetro_obj;
        string _lastmove;
        int number_of_moves;
};}

#endif