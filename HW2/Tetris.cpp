#include "Tetris.hpp"

using namespace std;

void Tetris::draw() const
{
    for(int u =clmn+2; u>0; u--) //Çerçeve için x yazdırdım
        cout<< 'X';
    cout << endl;
   for(auto row : board)
    {
        cout<< 'X';//Çerçeve için x yazdırdım

        for(auto element : row)
        {
            if (element != '*') // vektörleri yıldızla doldurmuştum. onları boşluk olarak yazdırıyorum
                cout << element;
            else
                cout << ' ';
        }
        cout<< 'X';//Çerçeve için x yazdırdım

        cout<<endl;
    }
    for(int u =clmn+2; u>0; u--)//Çerçeve için x yazdırdım
        cout<< 'X';
    cout << endl;
    //(cout << "Selam kızlaaaarr\n";
}

Tetris::Tetris(int len_of_row, int len_of_clmn)
{
    board = {};// Vector which is in Tetris object is initialized as empty.
    row = len_of_row;
    clmn = len_of_clmn;
    int i,j;
    char star = '*';
    board.resize(row, vector<char>(clmn, star));//It resize vector according to input.It is filled with star (actually space)
}

int Tetris::how_many_rotate(Tetromino obj, int rotate_number, int coordinat1, int coordinat2, vector<vector<char>> matrix)// This function find best position
{
    int i, j, k, hole, a=0, b=0, num_of_cannotfit=0, temp_i, temp_j;
    decltype(hole)  count=0;

    
    vector<int> tut= {-1, -1, -1, -1};
    vector<int> canfit_Return_value= {-1, -1, -1, -1};
    hole = 0;
    vector<vector<int>> coordinates (4, vector<int>(2, -1)); // objenin yüksekliği kadar son koordinatları tutucam
    a=0;

    for(i= obj.getShapeOfTetris().size() - 1; i>=0 ; i--)
    {
        for(j=0; j<obj.getShapeOfTetris()[i].size(); j++)
        {
            if(obj.getShapeOfTetris()[i][j] != '*')
            {
                if(count != 0)
                {
                    if(matrix[coordinat1 + i - temp_i][coordinat2 + j - temp_j] == obj.get_type())
                    {
                        coordinat1 = coordinat1 + i - temp_i;
                        coordinat2 = coordinat2 + j - temp_j;
                    }
                }
                /*ekleyeceğim vektörü takip ediyorum ve değişimleri boardda da takip ederek eklediğim vektörün ilk koordinatlarini aldım*/
                coordinates[a][0] = coordinat1;
                coordinates[a][1] = coordinat2;
                temp_i = i;
                temp_j = j;
                count++;
                a++;
                break;
            }
        }
    }

    /*Aldığım koordinatlardan geriye doğru giderek kaç tane boşluk olduğunu saydım*/
    for(a=0; a<4; a++)
    {
        b=0;
        //cout << "Type: "<< obj.get_type()<<"\nSON coordinates: " << coordinates[a][0] << " " << coordinates[a][1] << endl;
        if(coordinates[a][0] >= 0 && coordinates[a][1] >= 0)
        {
            for(i=coordinates[a][1]-1; i>= 0; i--)
            {
                if(matrix[coordinates[a][0]][i] != '*')
                    b += 1;
            }
            for(j=coordinates[a][1]-1; j>=0 && matrix[coordinates[a][0]][j] == '*'; j--)
            {
                //kendinden önce herhangi bir teteromino objesinin char karateri var mı diye bakamsıgerekiyor eğer herhangi bir tane varsa boşluk saymalı

                if(b == 0)//eğer kendisinden önce boşluktan başka bir şey yoksa boşluk saymadım
                    break;
                if(matrix[coordinates[a][0]][j] == '*')
                    hole += 1;
            }
        }
    }
    return hole;
}
bool Tetris::Fit(Tetromino other, char increase)
{
    int i, j, location_x, x,y, count=0, rotate_counter=0, is_it_end=0, len_of_vertical;
    vector<int> which_rotate= {-1,-1,-1,-1}; /*This vector holds number of holes for each rotate(if it is valid) according to least hole it finds best fit*/
    vector<int> validate;/*It holds valid rotates. If it's 0. index is negative it means with 0 rotate it can not fit. If it's 1. index is positive it means 1 times rotate can fit*/
    vector<char> temp;/*This is to fill temp shape*/
    vector<vector<char>> temp_shape;/*It is copy of shape of tetris*/
   
    for(i=0; i<board.size(); i++)
    {
        vector<char> temp;
        for(j=0; j<board[i].size(); j++)
        {
            temp.push_back(board[i][j]);
        }
        temp_shape.push_back(temp);
    }
    // tempe atama yapar

    x=0;
    y=0;
    for(i=temp_shape.size()-1; i>=0 && count== 0; i--)
    {
        for(j=0; j<temp_shape[i].size()&& count == 0; j++)
        {
            if(temp_shape[i][j] == '*') // bulduğu ilk boşluğa bakar ve kalan kısımların çakışıp çakışmadığını kontrol eder doğru yeri bulana kadar devam eder
            {
                validate = {};
                for(rotate_counter=0; rotate_counter<4; rotate_counter++)
                {
                    validate.push_back(isvalid_place(temp_shape, other, i, j)); // hangi rotate'in iyi olacağını bulur
                    if(validate[rotate_counter] >= 0)
                    {
                        add(temp_shape, other, i, j);// iyi rotate'i matrixe ekler
                        
                        which_rotate[rotate_counter] = how_many_rotate(other, rotate_counter, i, j, temp_shape);// her rotate'ten kalan boşlukları bulur ve vektöre yazar
                        
                        for(x=0; x<board.size(); x++)// değiştirlen tempi asıl objenin vektörüne atar
                        {
                            for(y=0; y<board[x].size(); y++)
                            {
                                temp_shape[x][y] = board[x][y];
                            }
                        }
                    }
                    other.rotate('r');
                }

                int min = which_rotate[0];
                int index = -1;
                /*vektördeki en küçük boşluk sayısını bulur ve onu en iyi fit kabul eder. (index numarası rotate sayısıdır)*/
                for(rotate_counter=0; rotate_counter<4; rotate_counter++)
                {
                    if(which_rotate[rotate_counter] >= 0)
                    {
                        min = which_rotate[rotate_counter];
                        index = rotate_counter;
                        break;
                    }
                }

                for(rotate_counter=0; rotate_counter<4; rotate_counter++)
                {
                    if(which_rotate[rotate_counter] < min && which_rotate[rotate_counter] >= 0)
                    {
                        min = which_rotate[rotate_counter];
                        index = rotate_counter;
                    }
                }
                /*index rotate edilmesi gereken sayıdır en az boşluğu sağlayan rotate sayısıdır*/
                for(x=0; x<index; x++)
                {
                    other.rotate('r');
                }
                if(index != -1)
                {

                    int a;

                    lenght_of_object(len_of_vertical, other);
                    cout << "len: " << len_of_vertical<< endl;
                    if(j>clmn/2)// Tetrominoyu sağa doğru hareket ettireiblmek için
                    {
                        for(a=clmn/2; a<=j; a++)
                        {
                            cout << "\033[2J" << "\033[0;0f";
                            add(temp_shape, other, len_of_vertical-1, a);
                            for(int u =clmn+2; u>0; u--)// çerçeve için x yazdırır
                            cout<< 'X';
                            cout << endl;
                            for(auto k : temp_shape)
                            {
                                cout<< 'X';// çerçeve için x yazdırır
                                for(auto l : k)
                                {
                                    if(l == '*')    
                                        cout << ' ';
                                    else
                                        cout <<l;
                                }
                                cout<< 'X';// çerçeve için x yazdırır
                                cout << endl;
                            }
                            for(int u =clmn+2; u>0; u--)// çerçeve için x yazdırır
                                cout<< 'X';
                            cout << endl;
                            usleep(30000);
                            temp_shape = board;//boardın güncellenmiş halini tempe atıyorum çünkü add fonksiyonu temp üstünden çalışıyor
                        }
                    }
                    else
                    {
                        /*Bu da üstteki if in aynısı sadece tetrominoyu sola doğru kaydırıyor*/
                       for(a=clmn/2; a>=j; a--)
                        {
                            cout << "\033[2J" << "\033[0;0f";
                            add(temp_shape, other, len_of_vertical-1, a);
                            for(int u =clmn+2; u>0; u--)
                            cout<< 'X';
                            cout << endl;
                            for(auto k : temp_shape)
                            {
                                cout<< 'X';
                                for(auto l : k)
                                {
                                    if(l == '*')    
                                        cout << ' ';
                                    else
                                        cout <<l;
                                }
                                cout<< 'X';
                                cout << endl;
                            }
                            for(int u =clmn+2; u>0; u--)
                                cout<< 'X';
                            cout << endl;
                            usleep(30000);
                            temp_shape = board;
                        } 
                    }
                    for(a = 0 + len_of_vertical - 1; a < i; a++)//boarddan taşma olmasın diye yüksekliği kadar eksiğinden yazdırıyor yazdırılması gereken koordinata kadar gidiyor
                    {
                		cout << "\033[2J" << "\033[0;0f";
                        add(temp_shape, other, a, j); // eğer çakışmıyorsa vektörleri biribirine ekler
                        for(int u =clmn+2; u>0; u--)
                            cout<< 'X';
                        cout << endl;
                        for(auto k : temp_shape)
                        {
                            cout<< 'X';
                            for(auto l : k)
                            {
                                if(l == '*')    
                                    cout << ' ';
                                else
                                    cout <<l;
                            }
                            cout<< 'X';
                            cout << endl;
                        }
                        for(int u =clmn+2; u>0; u--)
                            cout<< 'X';
                        cout << endl;
                        usleep(30000);
                        temp_shape = board;
                    }
                    cout << "\033[2J" << "\033[0;0f";
                    add(temp_shape, other, i, j); // eğer çakışmıyorsa vektörleri biribirine ekler
                    count++;

                }
            }
            else
                validate = {-1, -1, -1, -1};  // eğer dört rotate ile hiçbiri boş noktalardan birine uygun değilse doldurur   
        }
    }

    for(i=0; i<validate.size(); i++)//eğer validate'in hepsi negatifse oyun biter. çünkü tetromino objesini koyacak yer kalmamıştır
    {
        if(validate[i] < 0)
            is_it_end += 1;
    }
    if(is_it_end == 4)
      return false;// eğer validetin hepsi -1 ise hiç uygun yer bulamamıştır ve oyun biter

    for(i=0; i<board.size(); i++)// değiştirlen tempi asıl objenin vektörüne atar
    {
        for(j=0; j<board[i].size(); j++)
        {
            board[i][j] = temp_shape[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    cout << "\033[2J" << "\033[0;0f";
    draw();
    return true;
}

void Tetris::add(vector<vector<char>> & matrix, const Tetromino other, int i, int j)
{
    int x, y, temp_x, temp_y, count = 0;
    for(x= other.getShapeOfTetris().size() - 1; x>=0 ; x--)
    {
        for(y=0; y<other.getShapeOfTetris()[x].size(); y++)
        {
            if(other.getShapeOfTetris()[x][y] != '*') //Find first point which is not space
            {
                /*It assign directly first coordinates. Then it controls changes between coordinates. Then it apply same changes main vector*/
                if(count != 0)
                {
                    /*I controlled the place that i want to write is whether empty or it exceed bounds*/
                    if(matrix[i + x - temp_x][j + y - temp_y] == '*' && (i + x - temp_x) >= 0 && (j + y - temp_y) >= 0 && (i + x - temp_x) < matrix.size() && (j + y - temp_y) < matrix[0].size())
                    {
                        //boşluk olan yerlere yazdırdım
                        i = i + x - temp_x;
                        j = j + y - temp_y;
                        matrix[i][j] = other.getShapeOfTetris()[x][y];
                    }
                }
                else
                    matrix[i][j] = other.getShapeOfTetris()[x][y];
                //I kept old coordinates to determine changes between two points.
                temp_x = x;
                temp_y = y;
                count++;
            }
        }
    }
}

int Tetris::isvalid_place(vector<vector<char>> matrix, const Tetromino other, int i, int j)
{
    /*This function takes two coordinates of a point and objects that i want to write.*/
    /*It controls this point whether is valid to write*/
    /*If there is any exceeding or one of points that i want to not space it returns negative*/
    int x, y, temp_x, temp_y, count = 0, a;
    
    for(x= other.getShapeOfTetris().size() - 1; x>=0 ; x--)
    {
        for(y=0; y<other.getShapeOfTetris()[x].size(); y++)
        {
            if(other.getShapeOfTetris()[x][y] != '*')
            {
                if(count != 0)
                {
                    a=matrix[0].size();
                    //cout << "a: " << a << endl;
                    if((j + y - temp_y) < a)//It controls boundry
                    {
                        if((i + x - temp_x) >= 0 && (j + y - temp_y) >= 0 && (i + x - temp_x) < matrix.size())//It controls boundry
                        {
                            if(matrix[i + x - temp_x][j + y - temp_y] == '*') // It controls the is point valid (is there space).
                            {
                                i = i + x - temp_x;
                                j = j + y - temp_y;
                            }
                            else
                                return -1;
                        }
                        else
                            return -1;
                    }
                    else
                        return -2;  //cout << "isvalid fonk sağa doğru sınır taştı -2 return etti\n";
                }
                temp_x = x;
                temp_y = y;
                count++;
            }
        }
    }
    return 1;
}

void Tetris::lenght_of_object(int &len_of_vertical, const Tetromino& other)
{
    int i, j;
    len_of_vertical =0;
    //tüm vektörü gezerken ekeleyeceğim objenin dikey uzunluğunu bulur.
    for(i=0; i<other.getShapeOfTetris().size(); i++)
    {
        for(j=0; j<other.getShapeOfTetris()[i].size(); j++)
        {
            if(other.getShapeOfTetris()[i][j] != '*')
            {
                len_of_vertical = len_of_vertical + 1;
                break;
            }
        }
    }
}
