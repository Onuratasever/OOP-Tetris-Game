#include "Tetromino.hpp"

using namespace std;
namespace Onur
{
    void Tetromino::setter(block_type shape)
    {
        //Vector board is filled with necessary shape according to shape which is taken with input from user.
        //Object type is determined
        int j;
        if(shape == block_type::L)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', 'L', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>0 && j == 0)
                        shape_of_tetris[i][j] = 'L';
                    else if(i==3 && j == 1)
                        shape_of_tetris[i][j] = 'L';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'L';
        }
        if(shape == block_type::O)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'O', 'O', '*', '*'}, {'O', 'O', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>1 && j == 0)
                        shape_of_tetris[i][j] = 'O';
                    else if(i>1 && j == 1)
                        shape_of_tetris[i][j] = 'O';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'O';
        }
        if(shape == block_type::T)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*','*'}, {'T', 'T', 'T', '*'}, {'*', 'T', '*','*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && j != 3)
                        shape_of_tetris[i][j] = 'T';
                    else if(i==3 && j == 1)
                        shape_of_tetris[i][j] = 'T';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'T';
        }
        if(shape == block_type::J)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', 'J'}, {'*','*', '*', 'J'}, {'*','*', 'J', 'J'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>0 && j == 3)
                        shape_of_tetris[i][j] = 'J';
                    else if(i==3 && j == 2)
                        shape_of_tetris[i][j] = 'J';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'J';
        }
        if(shape == block_type::S)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*','S', 'S', '*'}, {'S', 'S', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && (j == 1 || j == 2))
                        shape_of_tetris[i][j] = 'S';
                    else if(i==3 && (j == 0 || j == 1))
                        shape_of_tetris[i][j] = 'S';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'S';
        }
        if(shape == block_type::Z)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'Z', 'Z', '*', '*'}, {'*','Z', 'Z', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && (j == 0 || j == 1))
                        shape_of_tetris[i][j] = 'Z';
                    else if(i==3 && (j == 1 || j== 2))
                        shape_of_tetris[i][j] = 'Z';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'Z';
        }
        if(shape == block_type::I)
        {
            //shape_of_tetris = {{'I', 'I', 'I', 'I'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i == 0)
                        shape_of_tetris[i][j] = 'I';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'I';
        }
    }



    /*void Tetromino::print() const
    {
        for(auto row : shape_of_tetris)
        {
            for(auto element : row)
            { // vektörleri yıldızla doldurmuştum. onları boşluk olarak yazdırıyorum
                    cout << element;
            }
            cout<<endl;
        }
    }*/

    Tetromino::Tetromino(block_type shape)
    {
        int j;
        // according to given type it initialize vector and assign type
        if(shape == block_type::L)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', 'L', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>0 && j == 0)
                        shape_of_tetris[i][j] = 'L';
                    else if(i==3 && j == 1)
                        shape_of_tetris[i][j] = 'L';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'L';
        }
        if(shape == block_type::O)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'O', 'O', '*', '*'}, {'O', 'O', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>1 && j == 0)
                        shape_of_tetris[i][j] = 'O';
                    else if(i>1 && j == 1)
                        shape_of_tetris[i][j] = 'O';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'O';
        }
        if(shape == block_type::T)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*','*'}, {'T', 'T', 'T', '*'}, {'*', 'T', '*','*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && j != 3)
                        shape_of_tetris[i][j] = 'T';
                    else if(i==3 && j == 1)
                        shape_of_tetris[i][j] = 'T';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'T';
        }
        if(shape == block_type::J)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', 'J'}, {'*','*', '*', 'J'}, {'*','*', 'J', 'J'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>0 && j == 3)
                        shape_of_tetris[i][j] = 'J';
                    else if(i==3 && j == 2)
                        shape_of_tetris[i][j] = 'J';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'J';
        }
        if(shape == block_type::S)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*','S', 'S', '*'}, {'S', 'S', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && (j == 1 || j == 2))
                        shape_of_tetris[i][j] = 'S';
                    else if(i==3 && (j == 0 || j == 1))
                        shape_of_tetris[i][j] = 'S';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'S';
        }
        if(shape == block_type::Z)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'Z', 'Z', '*', '*'}, {'*','Z', 'Z', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && (j == 0 || j == 1))
                        shape_of_tetris[i][j] = 'Z';
                    else if(i==3 && (j == 1 || j== 2))
                        shape_of_tetris[i][j] = 'Z';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'Z';
        }
        if(shape == block_type::I)
        {
            //shape_of_tetris = {{'I', 'I', 'I', 'I'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i == 0)
                        shape_of_tetris[i][j] = 'I';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'I';
        }
    }

    Tetromino::Tetromino()
    {
        // This constructor initialize untyped objects and fill vector.
        //shape_of_tetris = {{'*', '*', '*', '*'},{'*', '*', '*', '*'},{'*', '*', '*', '*'},{'*', '*', '*', '*'}};
        shape_of_tetris = new char*[4];
        for(int i=0; i<4; i++)
            shape_of_tetris[i] = new char[4];
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                shape_of_tetris[i][j] = '*';
            }
        }
    }

    Tetromino::Tetromino(int len_of_row, int len_of_clmn)
    {
    // shape_of_tetris = {};// Vector which is in Tetromino object is initialized as empty.
        //char star = '*';
        //shape_of_tetris.resize(len_of_row, vector<char>(len_of_clmn, star));//It resize vector according to input. It is filled with star (actually space)
        shape_of_tetris = new char*[len_of_row];
        for(int i=0; i<len_of_row; i++)
            shape_of_tetris[i] = new char[len_of_clmn];
        for(int i=0; i<len_of_row; i++)
        {
            for(int k=0; k<len_of_clmn; k++)
            {
                shape_of_tetris[i][k] = '*';
            }
        }
    }

    void Tetromino::print()const
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                cout << shape_of_tetris[i][j];
            }
            cout << endl;
        }
    }
    void Tetromino::rotate(char direction) // array unutmuium
    {
        //This rotate function rotates object array according to input as right or left
        int i, j, a=1, count=0, k;
        char** temp_shape;
        temp_shape = new char*[4];
        for(i=0; i<4; i++)
            temp_shape[i] = new char[4];

        if(direction == 'r' || direction == 'R')
        {
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
            for(i=0; i<4; i++)// rotate edilmiş vektörü asıl objedeki vektöre atar.
            {
                for(j=0; j<4; j++)
                    shape_of_tetris[i][j] = temp_shape[i][j];
            }
        }

        if(direction == 'l' || direction == 'L') // right fonksiyonunu 3 kere yapar ve 1 sol eder
        {
        for(k=0; k<3; k++)
        {
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
                for(i=0; i<4; i++)// rotate edilmiş vektörü asıl objedeki vektöre atar.
                {
                    //cout << "12keremi\n";
                    for(j=0; j<4; j++)
                        shape_of_tetris[i][j] = temp_shape[i][j];
                } 
        }
        }
        for(i=0; i<4; i++)
            delete[] temp_shape[i];
        delete[] temp_shape;
        temp_shape = nullptr;
    }
    Tetromino:: ~Tetromino()
    {
        for(int i=0; i<4; i++)
            delete[] shape_of_tetris[i];
        delete[] shape_of_tetris;
        shape_of_tetris = nullptr;
    }
}