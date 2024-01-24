#include "AbstractTetris.hpp"
using namespace std;

namespace onur
{//it controls lastmove string data and if it is empty it throws.
void AbstractTetris::lastMove() const
{
    try
    {
        if (_lastmove == "")
        {
            throw(123);
        }
        else
            cout << _lastmove<<endl;
    }
    catch(...)
    {
        cerr << "There is no last move!\n";
    }        
}

//no parameter constructor 
AbstractTetris::AbstractTetris()
{
    number_of_moves = 0;
}

// This is to fill _lastmove
void AbstractTetris::setlastMove()
{
    if(get_Tetro_Obj().get_type() == 'L' || get_Tetro_Obj().get_type() == 'l')
    {
        _lastmove = "L object";
    }
    if(get_Tetro_Obj().get_type() == 'J' || get_Tetro_Obj().get_type() == 'j')
    {
        _lastmove = "J object";
    }
    if(get_Tetro_Obj().get_type() == 'Z' || get_Tetro_Obj().get_type() == 'z')
    {
        _lastmove = "Z object";
    }
    if(get_Tetro_Obj().get_type() == 'I' || get_Tetro_Obj().get_type() == 'i')
    {
        _lastmove = "I object";
    }
    if(get_Tetro_Obj().get_type() == 'S' || get_Tetro_Obj().get_type() == 's')
    {
        _lastmove = "S object";
    }
    if(get_Tetro_Obj().get_type() == 'T' || get_Tetro_Obj().get_type() == 't')
    {
        _lastmove = "T object";
    }
    if(get_Tetro_Obj().get_type() == 'O' || get_Tetro_Obj().get_type() == 'o')
    {
        _lastmove = "O object";
    }
}

//It finds the vertical length of object
void AbstractTetris::lenght_of_object(int &len_of_vertical, const Tetromino& other)
{
    int i, j;
    len_of_vertical =0;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(other.getShapeOfTetris()[i][j] != '*')
            {
                len_of_vertical = len_of_vertical + 1;
                break;
            }
        }
    }
}}