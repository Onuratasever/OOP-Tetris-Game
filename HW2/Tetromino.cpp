#include "Tetromino.hpp"

using namespace std;

void Tetromino::setter(block_type shape)
{
    //Vector board is filled with necessary shape according to shape which is taken with input from user.
    //Object type is determined
    if(shape == block_type::L)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', 'L', '*', '*'}};
        type = 'L';
    }
    if(shape == block_type::O)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'O', 'O', '*', '*'}, {'O', 'O', '*', '*'}};
        type = 'O';
    }
    if(shape == block_type::T)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*','*'}, {'T', 'T', 'T', '*'}, {'*', 'T', '*','*'}};
        type = 'T';
    }
    if(shape == block_type::J)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', 'J'}, {'*','*', '*', 'J'}, {'*','*', 'J', 'J'}};
        type = 'J';
    }
    if(shape == block_type::S)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*','S', 'S', '*'}, {'S', 'S', '*', '*'}};
        type = 'S';
    }
    if(shape == block_type::Z)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'Z', 'Z', '*', '*'}, {'*','Z', 'Z', '*'}};
        type = 'Z';
    }
    if(shape == block_type::I)
    {
        shape_of_tetris = {{'I', 'I', 'I', 'I'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}};
        type = 'I';
    }
}



void Tetromino::print() const
{
    for(auto row : shape_of_tetris)
    {
        for(auto element : row)
        { // vektörleri yıldızla doldurmuştum. onları boşluk olarak yazdırıyorum
                cout << element;
        }
        cout<<endl;
    }
}

Tetromino::Tetromino(block_type shape)
{
    // according to given type it initialize vector and assign type
    if(shape == block_type::L)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', 'L', '*', '*'}};
        type = 'L';
    }
    if(shape == block_type::O)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'O', 'O', '*', '*'}, {'O', 'O', '*', '*'}};
        type = 'O';
    }
    if(shape == block_type::T)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*','*'}, {'T', 'T', 'T', '*'}, {'*', 'T', '*','*'}};
        type = 'T';
    }
    if(shape == block_type::J)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', 'J'}, {'*','*', '*', 'J'}, {'*','*', 'J', 'J'}};
        type = 'J';
    }
    if(shape == block_type::S)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*','S', 'S', '*'}, {'S', 'S', '*', '*'}};
        type = 'S';
    }
    if(shape == block_type::Z)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'Z', 'Z', '*', '*'}, {'*','Z', 'Z', '*'}};
        type = 'Z';
    }
    if(shape == block_type::I)
    {
        shape_of_tetris = {{'I', 'I', 'I', 'I'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}};
        type = 'I';
    }
}

Tetromino::Tetromino()
{
    // This constructor initialize untyped objects and fill vector.
    shape_of_tetris = {{'*', '*', '*', '*'},{'*', '*', '*', '*'},{'*', '*', '*', '*'},{'*', '*', '*', '*'}};
}

Tetromino::Tetromino(int len_of_row, int len_of_clmn)
{
    shape_of_tetris = {};// Vector which is in Tetromino object is initialized as empty.
    char star = '*';
    shape_of_tetris.resize(len_of_row, vector<char>(len_of_clmn, star));//It resize vector according to input. It is filled with star (actually space)
}

void Tetromino::rotate(char direction) // array unutmuium
{
    //This rotate function rotates object array according to input as right or left
    int i, j, a=1, count=0, k;
    char temp_shape[4][4];
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            temp_shape[i][j] = shape_of_tetris[j][i];
    }
    // fonksiyonun tersini alıp onun da simetrisini aldım böylece 90 derece dönmüş oldu
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            shape_of_tetris[i][j] = temp_shape[i][j] ;
    }

    if(direction == 'r' || direction == 'R')
    {
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                if(j < 2)
                    temp_shape[i][j] = shape_of_tetris[i][3-j];
                if(j >= 2)
                {
                    temp_shape[i][j] = shape_of_tetris[i][j-a];
                    a = a + 2;
                }
            }
            a=1;
        }
    }

    if(direction == 'l' || direction == 'L') // right fonksiyonunu 3 kere yapar ve 1 sol eder
    {
       for(k=0; k<3; k++)
       {
            for(i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(j < 2)
                        temp_shape[i][j] = shape_of_tetris[i][3-j];
                    if(j >= 2)
                    {
                        temp_shape[i][j] = shape_of_tetris[i][j-a];
                        a = a + 2;
                    }
                }
                a=1;
            }
       }
    }

    for(i=0; i<4; i++)// rotate edilmiş vektörü asıl objedeki vektöre atar.
    {
        for(j=0; j<4; j++)
            shape_of_tetris[i][j] = temp_shape[i][j];
    }
}