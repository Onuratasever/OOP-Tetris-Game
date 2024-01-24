#include "Tetris.hpp"

using namespace std;
namespace Onur
{

    Tetris::~Tetris()
    {
        for(int i=0; i<GetLenOfRow(); i++)
            delete[] board[i];
        delete[] board;
        board = nullptr;
    }
    void Tetris::move(char move_direction, int move_count, const Tetris& temp)
    {
        int row, clmn, move_count_temp = move_count, counter=0;
        lenght_of_object(row, tetro_obj);
        row = row -1;
        clmn = (GetLenOfClmn()-1) / 2;
        //move fonksiyonu kontrol etmeye orta noktadan başlıyor ve istediği yönde tek tek ilerliyor ta ki ilerleyemeyene kadar.
        if(move_direction == 'r' || move_direction == 'R')
        {
            for(int i=0; i<move_count && counter == 0; i++)
            {   
                if(getBoard()[row][clmn] == '*')
                {
                    if(!isvalid_place(get_Tetro_Obj(), row, clmn)) // sınır aşarsa false döndürüyor
                    {
                        clmn -= 1;// eğer herhangi bir taşma ya da üst üste binme olduysa bir birim geri gidiyor ve oraya yerleşiyor
                        counter = 1;
                    }
                    else
                        clmn += 1;
                }
                else
                {
                    clmn -= 1;
                    break;
                }
            }
        }
        else if(move_direction == 'l' || move_direction == 'L')
        {
            //clmn = clmn - move_count_temp;
            for(int i=0; i<move_count && counter == 0; i++)
            {
                if(getBoard()[row][clmn] == '*')
                {
                    if(!isvalid_place(get_Tetro_Obj(), row, clmn)) // isvalidda sınırları ve koyacağı yerin etrafı boş mu diye kontrol ediyor
                    {
                    // eğer herhangi bir taşma ya da üst üste binme olduysa bir birim geri gidiyor ve oraya yerleşiyor
                        clmn += 1;
                        counter = 1;
                    }
                    else// eğer koyacağı yer uygunsa hareket etmeye devam ediyor
                        clmn -= 1;
                }
                else
                {
                    clmn += 1;
                    break;
                }
            }
        }

        while(board[row][clmn] == '*')// bu da aşağı indirme kısmı. 
        {
            if(!isvalid_place(get_Tetro_Obj(), row, clmn))// eğer anlık konumda taşma ya da üst üste binme varsa bir önceki noktayı kabul ediyor.
                break;
            row += 1;
            if(row == GetLenOfRow()) break;
        }
        row -= 1;
        animate(temp, row, clmn);
    }

    void Tetris::operator += (const Tetromino& obj)
    {
        int vertical_len_of_tetromino;

        lenght_of_object(vertical_len_of_tetromino, obj);// en yukarı yazdırabilmek için objenin uzunluğuunu buldum
        //Koyacağı yerin uygunluğuna ve boşluk olup olmadığına bakıyor eğer değilse tetrominoyu koyacak yer yoktur yani oyun bitiyor.
        if(isvalid_place(obj, vertical_len_of_tetromino - 1, (GetLenOfClmn()-1) / 2) && board[vertical_len_of_tetromino - 1][(GetLenOfClmn()-1) / 2] == '*')
        {
            add(obj, vertical_len_of_tetromino - 1, (GetLenOfClmn()-1) / 2);
        }
        else // OYUN BURDA BİTİYO
        {
            cout << "Game over!";
            exit(1);
        }
    }

    void Tetris::animate(const Tetris& temp, int i, int j)
    {
        int len, a; 
        lenght_of_object(len, get_Tetro_Obj());// tetrominonun uzunluğuunu buluyor
        if(i >= 0 && j >= 0)// parametler negatifse hareket etmicek demektir sadece olduğu yeri printler
        {
            if(j > (GetLenOfClmn()-1)/2)// sağa gidiyor demek
            {
                for(int a=(GetLenOfClmn()-1)/2; a<=j; a++)
                {
                    cout << "\033[2J" << "\033[0;0f";// ekranı silip cursoru yukarı taşır
                    add(get_Tetro_Obj(), len-1, a);// tetrominoyu yazdırmaya başlayıp istediği yöne doğru kayar
                    draw();
                    for(int u=0; u<GetLenOfRow(); u++)// daha sonra tekrardan eski haline eşitler
                    {
                        for(int y=0; y<GetLenOfClmn(); y++)
                            board[u][y] = temp.getBoard()[u][y];
                    }
                    usleep(300000);
                }
            }
            else // sola gitme animasyonu
            {
                for(int a=(GetLenOfClmn()-1)/2; a>=j; a--)//sola gidiyor demek
                {
                    cout << "\033[2J" << "\033[0;0f";// ekranı silip cursoru yukarı taşır
                    add(get_Tetro_Obj(), len-1, a);// tetrominoyu yazdırmaya başlayıp istediği yöne doğru kayar
                    draw();
                    for(int u=0; u<GetLenOfRow(); u++)// daha sonra tekrardan eski haline eşitler
                    {
                        for(int y=0; y<GetLenOfClmn(); y++)
                            board[u][y] = temp.getBoard()[u][y];
                    }
                    usleep(300000);
                }
            }
            for(a=0 + len - 1; a < i; a++)// bu aşağı indirme animasyonu
            {
                cout << "\033[2J" << "\033[0;0f";// ekranı silip cursoru yukarı taşır
                add(get_Tetro_Obj(), a, j);
                draw();
                for(int u=0; u<GetLenOfRow(); u++)
                {
                    for(int y=0; y<GetLenOfClmn(); y++)
                        board[u][y] = temp.getBoard()[u][y];
                }
                usleep(300000);
            }
            cout << "\033[2J" << "\033[0;0f";
            add(get_Tetro_Obj(), i, j);
            draw();
            
        }
        else// sadece yazdırma.
        {
            cout << "\033[2J" << "\033[0;0f";
            draw();
            for(int u=0; u<GetLenOfRow(); u++)
            {
                for(int y=0; y<GetLenOfClmn(); y++)
                    board[u][y] = temp.getBoard()[u][y];
            }
            usleep(300000);
        }
    }

    void Tetris::draw() const
    {
        for(int u =clmn+2; u>0; u--) //Çerçeve için x yazdırdım
            cout<< 'X';
        cout << endl;
    for(int i=0; i<GetLenOfRow(); i++)
        {
            cout<< 'X';//Çerçeve için x yazdırdım

            for(int j=0; j<GetLenOfClmn(); j++)
            {
                if (board[i][j] != '*') // vektörleri yıldızla doldurmuştum. onları boşluk olarak yazdırıyorum
                    cout << board[i][j];
                else
                    cout << ' ';
            }
            cout<< 'X';//Çerçeve için x yazdırdım

            cout<<endl;
        }
        for(int u =clmn+2; u>0; u--)//Çerçeve için x yazdırdım
            cout<< 'X';
        cout << endl;
    }

    Tetris::Tetris(int len_of_row, int len_of_clmn)
    {
        //board = {};// Vector which is in Tetris object is initialized as empty.
        row = len_of_row;
        clmn = len_of_clmn;
        int i,j;
        char star = '*';
    //It resize array according to input.It is filled with star (actually space)
        board = new char*[len_of_row];
        for(i=0; i<len_of_row; i++)
            board[i] = new char[len_of_clmn];
        for(int i=0; i<len_of_row; i++)
        {
            for(int k=0; k<len_of_clmn; k++)
            {
                board[i][k] = '*';
            }
        }
    }

    void Tetris::add(const Tetromino& other, int i, int j)
    {
        int x, y, temp_x, temp_y, count = 0;
        for(x= 4 - 1; x>=0 ; x--)
        {
            for(y=0; y<4; y++)
            {
                if(other.getShapeOfTetris()[x][y] != '*') //Find first point which is not space
                {
                    /*It assign directly first coordinates. Then it controls changes between coordinates. Then it apply same changes main vector*/
                    if(count != 0)
                    {
                        /*I controlled the place that i want to write is whether empty or it exceed bounds*/
                        if(getBoard()[i + x - temp_x][j + y - temp_y] == '*' && (i + x - temp_x) >= 0 && (j + y - temp_y) >= 0 && (i + x - temp_x) < GetLenOfRow() && (j + y - temp_y) < GetLenOfClmn())
                        {
                            //boşluk olan yerlere yazdırdım
                            i = i + x - temp_x;
                            j = j + y - temp_y;
                            getBoard()[i][j] = other.getShapeOfTetris()[x][y];
                        }
                    }
                    else
                        getBoard()[i][j] = other.getShapeOfTetris()[x][y];
                    //I kept old coordinates to determine changes between two points.
                    temp_x = x;
                    temp_y = y;
                    count++;
                }
            }
        }
    }

    bool Tetris::isvalid_place(const Tetromino& other, int i, int j)
    {
        /*This function takes two coordinates of a point and objects that i want to write.*/
        /*It controls this point whether is valid to write*/
        /*If there is any exceeding or one of points that i want to not space it returns negative*/
        int x, y, temp_x, temp_y, count = 0, a;
        
        //int i = len - 1;
        //int j = (GetLenOfClmn() - 1) / 2; 
        if(i >= GetLenOfRow() || j >= GetLenOfClmn() || j<0 || i<0)
            return false;
        for(x= 4 - 1; x>=0 ; x--)
        {
            for(y=0; y<4; y++)
            {
                if(other.getShapeOfTetris()[x][y] != '*')
                {
                    if(count != 0)
                    {
                        a=GetLenOfClmn();
                        //cout << "a: " << a << endl;
                        if((j + y - temp_y) < a)//It controls boundry
                        {
                            if((i + x - temp_x) >= 0 && (j + y - temp_y) >= 0 && (i + x - temp_x) < GetLenOfRow())//It controls boundry
                            {
                                if(board[i + x - temp_x][j + y - temp_y] == '*') // It controls the is point valid (is there space).
                                {
                                    i = i + x - temp_x;
                                    j = j + y - temp_y;
                                }
                                else
                                    return false;
                            }
                            else
                                return false;
                        }
                        else
                            return false;
                    }
                    temp_x = x;
                    temp_y = y;
                    count++;
                }
            }
        }
        return true;
    }

    void Tetris::lenght_of_object(int &len_of_vertical, const Tetromino& other)
    {
        int i, j;
        len_of_vertical =0;
        //tüm vektörü gezerken ekeleyeceğim objenin dikey uzunluğunu bulur.

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
    }
}