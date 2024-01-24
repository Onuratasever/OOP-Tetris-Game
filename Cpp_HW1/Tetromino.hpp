#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <iostream>
#include <vector>

using namespace std;

enum class block_type
{
    I, O, L, S, Z, T, J
};

class Tetromino{

    public:
    Tetromino(const block_type);
    Tetromino();
    void rotate(const char);
    void print() const;
    inline vector<vector<char>> getShapeOfTetris() const {return (shape_of_tetris);};
    void copy(vector<vector<char>> &vect);
    int how_many_rotate(Tetromino obj, vector<vector<char>> temp_fit);
    bool canfit(const Tetromino& other, char increase);
    void lenght_of_object(int &len_of_vertical, vector<int> &len_of_horizontal, const Tetromino& other);
    void add(vector<vector<char>> & matrix, const Tetromino other, int i, int j);
    bool isvalid_place(vector<vector<char>> matrix, const Tetromino other, int i, int j);
    private:
        vector<vector<char>> shape_of_tetris;

};

#endif
