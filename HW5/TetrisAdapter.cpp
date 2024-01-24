#include "Tetromino.hpp"
#include "AbstractTetris.hpp"


using namespace std;

namespace onur
{template <template <class...>class T>
class TetrisAdapter : public AbstractTetris
{
    public:
        TetrisAdapter(int len_of_row, int len_of_clmn);
        TetrisAdapter();
        void draw()const;
        int GetLenOfRow()const{return (row);};
        int GetLenOfClmn()const{return (clmn);};
        bool isvalid_place(const Tetromino& other, int i, int j);
        void add(const Tetromino& other, int i, int j);
        void writeToFile(string file_name);
        bool readFromFile(string fileName);
        void operator += (const Tetromino& obj);
        void move(char move_direction, int move_count, const TetrisAdapter& temp);
        inline vector<vector<char>> getBoard() const {return (board);};
        void animate(const TetrisAdapter& temp, int i=-1, int j=-1);
        TetrisAdapter& operator =(const TetrisAdapter& other);
        
    private:
        T<T<char>> board;
        int row, clmn;
};

template <template <class...>class T>
TetrisAdapter<T>::TetrisAdapter(int len_of_row, int len_of_clmn)
{
    board = {};// Vector which is in Tetris object is initialized as empty.
    row = len_of_row;
    clmn = len_of_clmn;
    char star = '*';
    board.resize(row, T<char>(clmn, star));
}

template <template <class...>class T>
TetrisAdapter<T>::TetrisAdapter()
{
    board = {};// Vector which is in Tetris object is initialized as empty.
    row = 0;
    clmn = 0;
}

//It prints the board to screen with frames.
template <template <class...>class T>
void TetrisAdapter<T>::draw()const
{
    for(int u =clmn+2; u>0; u--) 
            cout<< 'X';
        cout << endl;
    for(int i=0; i<GetLenOfRow(); i++)
    {
        cout<< 'X';

        for(int j=0; j<GetLenOfClmn(); j++)
        {
            if (board[i][j] != '*')
                cout << board[i][j];
            else
                cout << ' ';
        }
        cout<< 'X';

        cout<<endl;
    }
    for(int u =clmn+2; u>0; u--)
        cout<< 'X';
    cout << endl;
}



template <template <class...>class T>
bool TetrisAdapter<T>::isvalid_place(const Tetromino& other, int i, int j)
{
    /*This function takes two coordinates of a point and objects that i want to write.*/
    /*It controls this point whether is valid to write*/
    /*If there is any exceeding or one of points that i want to not space it returns negative*/
    int x, y, temp_x, temp_y, count = 0, a;
    
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
                    {
                        return false;
                    }
                }
                temp_x = x;
                temp_y = y;
                count++;
            }
        }
    }
    return true;
}

template <template <class...>class T>
void TetrisAdapter<T>::add(const Tetromino& other, int i, int j)
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
                        board[i][j] = other.getShapeOfTetris()[x][y];
                    }
                }
                else
                    board[i][j] = other.getShapeOfTetris()[x][y];
                //I kept old coordinates to determine changes between two points.
                temp_x = x;
                temp_y = y;
                count++;
            }
        }
    }
}

//IT reads file and takes row, clmn, number of moves informations and it copy board which is in file to main board
template <template <class...>class T>
bool TetrisAdapter<T>::readFromFile(string fileName)
{
    ifstream save_file;


    save_file.open(fileName +".txt", ios::in);

    if(save_file.good() == false)
    {
        cerr << "\nFile does not exist!\n";
        return false;
    }
                    
    int row_temp, clmn_temp;
    save_file >> row_temp;
    save_file >> clmn_temp;
    save_file >> this->number_of_moves;


    string read;
    if(row_temp == this->row && this->clmn == clmn_temp)
    {
        for(int i= 0; i < this->row; i++)
        {
            for(int j= 0; j < this->clmn; j++)
            {
                save_file >> read;
                if(read == "*")
                    board[i][j] = '*';
                else
                    board[i][j] = read[0];
            }
        }
    }
    else
    {
       this->row = row_temp;
       this->clmn = clmn_temp;
    }

    save_file.close();
    cout << "\nThe game data has been loaded successfully\n";

    return true;
}

//It opens file and records row, clmn, number of moves and last shape of tetris board.
template <template <class...>class T>
void TetrisAdapter<T>::writeToFile(string file_name)
{
    int height = row;
    int width = clmn;

    ofstream save_file;
    save_file.open(file_name +".txt", ios::out);

    save_file << height << " " << width << "\n";
    save_file << number_of_moves << "\n";

    for(int i= 0; i < row; ++i)
    {
        for(int j= 0; j < clmn; ++j)
        {
            if(board[i][j] == '*')
                save_file << "* ";
            else
                save_file << board[i][j] << " ";
        }
        save_file << "\n";
    }

    save_file.close();
    cout << "\nGame data has been saved successfully\n";
}


// IT adds tetromino to the board by using add function
template <template <class...>class T>
void TetrisAdapter<T>::operator += (const Tetromino& obj)
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
        cout << "number moves: " << numberOfMoves() <<endl;
        cout << "Game over!";
        exit(1);
    }
}

// It takes three parameter. First one move direction second one how many it will go and last one temp pf object to send animate function
//Tetromino print top-middle of the board and it goes until encounter with an obstacle. In the end it sends coordinates to animate.
template <template <class...>class T>
void TetrisAdapter<T>::move(char move_direction, int move_count, const TetrisAdapter<T>& temp)
{
    int row, clmn, move_count_temp = move_count, counter=0, temp_row,i;
    lenght_of_object(row, get_Tetro_Obj());
    row = row -1;
    temp_row = row;
    clmn = (GetLenOfClmn()-1) / 2;
    //move fonksiyonu kontrol etmeye orta noktadan başlıyor ve istediği yönde tek tek ilerliyor ta ki ilerleyemeyene kadar.
    if(move_direction == 'r' || move_direction == 'R')
    {
        for(i=0; i<move_count && counter == 0; i++)
        {   
            if(getBoard()[row][clmn] == '*')
            {
                if(!isvalid_place(get_Tetro_Obj(), row, clmn+1)) // sınır aşarsa false döndürüyor
                {
                    break;
                }
                else
                {
                    this->increment_of_moves();
                    clmn += 1;
                }
            }
            else
            {
                clmn -= 1;
                break;
            }
        }
        set_lastmove() += ". And went right side " + to_string(i) + " times.";
    }   
    else if(move_direction == 'l' || move_direction == 'L')
    {
        //clmn = clmn - move_count_temp;
        for(i=0; i<move_count && counter == 0; i++)
        {
            if(getBoard()[row][clmn] == '*')
            {
                if(!isvalid_place(get_Tetro_Obj(), row, clmn-1)) // isvalidda sınırları ve koyacağı yerin etrafı boş mu diye kontrol ediyor
                {
                // eğer herhangi bir taşma ya da üst üste binme olduysa bir birim geri gidiyor ve oraya yerleşiyor
                    break;
                }
                else// eğer koyacağı yer uygunsa hareket etmeye devam ediyor
                {
                    this->increment_of_moves(); 
                    clmn -= 1;
                }
            }
            else
            {
                clmn += 1;
                break;
            }
        }
        set_lastmove() += "And went left side " + to_string(i) + " times.";
    }
    while(board[row][clmn] == '*')// bu da aşağı indirme kısmı. 
    {
        if(!isvalid_place(get_Tetro_Obj(), row, clmn))// eğer anlık konumda taşma ya da üst üste binme varsa bir önceki noktayı kabul ediyor.
            break;
        row += 1;
        if(row == GetLenOfRow()) break;
        this->increment_of_moves();
    }
    row -= 1;
    set_lastmove() += ". And went down side " + to_string(row - temp_row);
    animate(temp, row, clmn);
}
template <template <class...>class T>
void TetrisAdapter<T>::animate(const TetrisAdapter<T>& temp, int i, int j)
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
                usleep(100000);
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
                usleep(100000);
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
            usleep(100000);
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
        usleep(100000);
    }
}

// It assign a tetrisvector object to another one one by one
template <template <class...>class T>
TetrisAdapter<T>& TetrisAdapter<T>::operator =(const TetrisAdapter<T> &other)// copy assignment operator
{
    int i, j;
    if (this == &other)
        return *this;
    else
    {
        board.resize(other.row, vector<char>(other.clmn, '*'));
        for(i=0; i<other.board.size(); i++)
        {
            for(j=0; j<other.board[i].size(); j++)
            {
                board[i][j] = other.board[i][j];
            }
        }
    }
    row = other.row;
    clmn = other.clmn;
    return *this;
} }