#include "Tetromino.hpp"

using namespace std;

int Tetromino::how_many_rotate(Tetromino obj, vector<vector<char>> temp_fit)// This function find best position
{
    int i, j, k, hole, a=0, b=0;
    decltype(hole)  len_of_vertical;

    
    vector<int> tut= {-1, -1, -1, -1};
    vector<int> oyle;
    vector<vector<int>> coordinates (4, vector<int>(2, -1)); // objenin yüksekliği kadar son koordinatları tutucam
    for(k=0; k<4; k++)
    {
        hole = 0;
        lenght_of_object(len_of_vertical, oyle, obj);
        a=0;
        for(i=shape_of_tetris.size()-len_of_vertical; i<shape_of_tetris.size(); i++)// boşlukları aradığımız for
        {
            for(j=0; j< shape_of_tetris[i].size(); j++)
            {
                if(shape_of_tetris[i][j] != '*')
                {
                    coordinates[a][0] = i;
                    coordinates[a][1] = j;
                }
            }
            a++;
        }
        canfit(obj, '-');
        a=0;
        for(a=0; a<4; a++)// eklenecek tetris objesiyle arasında kaç tane boşluk olduğunu bulur
        {
            if(coordinates[a][0] >= 0 && coordinates[a][1] >= 0)
            {
                for(j=coordinates[a][1]+1; j< shape_of_tetris[i].size() && shape_of_tetris[coordinates[a][0]][j] == '*'; j++)
                {
                    if(shape_of_tetris[coordinates[a][0]][j] == '*')
                        hole += 1;
                }
            }
        }
        
        for(i=0; i<shape_of_tetris.size(); i++)// tabloyu tempi kullanarak eski haline çevirir
        {
            for(j=0; j< shape_of_tetris[i].size(); j++)
            {
                shape_of_tetris[i][j] =temp_fit[i][j];
            }
        }
        tut[k] = hole; // objenin rotate edilmiş her halinde kaç boşluk kaldığını bulur
        obj.rotate('r');

    }

    int min = tut[0];
    int index = 0;
    for(i=0; i<4; i++)
    {
        if(tut[i] >= 0)
        {
            min = tut[i];
            break;
        }
    }
    for(i=0; i<4; i++)
    {
        if(tut[i] < min && tut[i] >= 0)
        {
            min = tut[i];
            index = i;
        }
    }
    //Buradan en az boşluk kalan durumu seçer ve kaç kere rotate edilmesi gerekitğini return eder.
    return index;
}

void Tetromino::copy(vector<vector<char>> &vect)
{
    int i, j;
    //asıl boardı geçici vektöre yazdırır
    for(i=0; i<shape_of_tetris.size(); i++)
    {
        vector<char> full;
        for(j=0; j<shape_of_tetris[i].size(); j++)
        {
            full.push_back(shape_of_tetris[i][j]);
        }
        vect.insert(vect.begin() + i, full);
    }
}

void Tetromino::print() const
{
    //objenin vektörünü ekrana yazdırır
    for(auto row : shape_of_tetris)
    {
        for(auto element : row)
        {
            if (element != '*') // vektörleri yıldızla doldurmuştum. onları boşluk olarak yazdırıyorum
                cout << element;
            else
                cout << ' ';
        }
        cout<<endl;
    }
}

Tetromino::Tetromino(block_type shape)
{
    // verilen tipe göre objenin vektörünü başlatır ve doldurur
    if(shape == block_type::L)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', 'L', '*', '*'}};
    }
    if(shape == block_type::O)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'O', 'O', '*', '*'}, {'O', 'O', '*', '*'}};
    }
    if(shape == block_type::T)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*','*'}, {'T', 'T', 'T', '*'}, {'*', 'T', '*','*'}};
    }
    if(shape == block_type::J)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', 'J'}, {'*','*', '*', 'J'}, {'*','*', 'J', 'J'}};
    }
    if(shape == block_type::S)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*','S', 'S', '*'}, {'S', 'S', '*', '*'}};
    }
    if(shape == block_type::Z)
    {
        shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'Z', 'Z', '*', '*'}, {'*','Z', 'Z', '*'}};
    }
    if(shape == block_type::I)
    {
        shape_of_tetris = {{'I', 'I', 'I', 'I'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}};
    }
}

Tetromino::Tetromino()
{
    // bu constructor ise tipi belirlenmemiş objeleri başlatır ve doldurur
    shape_of_tetris = {{'*', '*', '*', '*'},{'*', '*', '*', '*'},{'*', '*', '*', '*'},{'*', '*', '*', '*'}};
}

void Tetromino::rotate(char direction)
{
    // bu rotate fonksiyonu vektörü çevirir
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

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            shape_of_tetris[i][j] = temp_shape[i][j];
    }
}

void Tetromino::lenght_of_object(int &len_of_vertical, vector<int> &len_of_horizontal, const Tetromino& other)
{
    int i, j;
    vector <int> asd;
    len_of_vertical =0;
    for(i=0; i < other.getShapeOfTetris().size(); i++)
    {
        len_of_horizontal.push_back(0);
        asd.push_back(0);
    }
    //tüm vektörü gezerken ekeleyeceğim objenin dikey uzunluğunu ve tek tek her satırda kaç elemanı olduğuunu bulur.
    for(i=0; i<other.getShapeOfTetris().size(); i++)
    {
        for(j=0; j<other.getShapeOfTetris()[i].size(); j++)
        {
            if(other.getShapeOfTetris()[i][j] != '*') 
                len_of_horizontal[i] = len_of_horizontal[i] + 1; // her satırında kaç tane harf olduğu yazıyor artık.
            if(other.getShapeOfTetris()[i][j] != '*')
            {
                asd[j] = asd[j] + 1; // her sütunda kaç tane harf olduğu yazıyor artık;
                len_of_vertical = len_of_vertical + 1;
                break;
            }
        }
    }
}

void Tetromino::add(vector<vector<char>> & matrix, const Tetromino other, int i, int j)
{
    int x, y, temp_x, temp_y, count = 0;
    for(x=0; x<other.getShapeOfTetris().size(); x++)
    {
        for(y=0; y<other.getShapeOfTetris()[x].size(); y++)
        {
            if(other.getShapeOfTetris()[x][y] != '*')
            {
                if(count != 0)
                {
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
                temp_x = x;
                temp_y = y;
                count++;
            }
        }
    }
}

bool Tetromino::isvalid_place(vector<vector<char>> matrix, const Tetromino other, int i, int j)
{
    int x, y, temp_x, temp_y, count = 0;
    
    for(x=0; x<other.getShapeOfTetris().size(); x++)
    {
        for(y=0; y<other.getShapeOfTetris()[x].size(); y++)
        {
            // objenin harflerinin nasıl hareket ettiğini bulur ve onu matrixte uygular. çakışma varsa false yoksa true return eder
            if(other.getShapeOfTetris()[x][y] != '*')
            {
                if(count != 0)
                {
                    // vektörün sınırlarını ve boşluk olup olmadığını kotnrol ettim
                    if(matrix[i + x - temp_x][j + y - temp_y] == '*' && (i + x - temp_x) >= 0 && (j + y - temp_y) >= 0 && (i + x - temp_x) < matrix.size() && (j + y - temp_y) < matrix[0].size())
                    {
                        i = i + x - temp_x;
                        j = j + y - temp_y;
                    }
                    else
                    {
                        return false;
                    }
                }
                // objenin harflerinin nasıl değiştiğini anlamak için eski ve yeni verileri karşılaştırdım.
                temp_x = x;
                temp_y = y;
                count++;
            }
        }
    }
    return true;
}

bool Tetromino::canfit(const Tetromino& other, char increase)
{
    int len_of_vertical, i, j, location_x, location_y,x,y, count=0;
    vector<int> len_of_horizontal;
    vector<char> temp;
    vector<vector<char>> temp_shape;
    lenght_of_object(len_of_vertical, len_of_horizontal, other); // objenin yatay ve dikey uzunluğunuu bulur
    for(i=0; i<shape_of_tetris.size(); i++)
    {
        vector<char> temp;
        for(j=0; j<shape_of_tetris[i].size(); j++)
        {
            temp.push_back(shape_of_tetris[i][j]);
        }
        temp_shape.push_back(temp);
    }
    // tempe atama yapar

    location_y= temp_shape.size()-len_of_vertical; // objenin en alta dayalı olması için hangi satırdan başlaması gerekitğini bulur
    x=0;
    y=0;
    for(i=location_y, x=0; i<temp_shape.size() && x<other.getShapeOfTetris().size() && count== 0; i++)
    {
        for(j=0, y=0; j<temp_shape[i].size() && y<other.getShapeOfTetris()[x].size() && count == 0; j++)
        {
            if(temp_shape[i][j] == '*') // bulduğu ilk boşluğa bakar ve kalan kısımların çakışıp çakışmadığını kontrol eder doğru yeri bulana kadar devam eder
            {
                if(isvalid_place(temp_shape, other, i, j))
                {
                    add(temp_shape, other, i, j); // eğer çakışmıyorsa vektörleri biribirine ekler
                    count++;
                }
            }      
        }
    }

    for(i=0; i<shape_of_tetris.size(); i++)// değiştirlen tempi asıl objenin vektörüne atar
    {
        for(j=0; j<shape_of_tetris[i].size(); j++)
        {
            shape_of_tetris[i][j] = temp_shape[i][j];
        }
    }
    
    if(increase == '+') // vektörün boyutunu birleştirmeden sonra tekrar ayarlar
    {
        for(int i = 0; i < shape_of_tetris.size(); i++)
        {
            for(int j = 0; j < 4; j++)
            {
                shape_of_tetris[i].push_back('*');
            }
        }
    }
    return true;
}