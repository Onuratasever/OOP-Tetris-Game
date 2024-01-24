#include "Tetromino.hpp"

using namespace std;

int main()
{
    int num_of_tetrominos, i, j, a;
    vector<char> type;
    char type_tet;
    cout << "How many tetrominos? ";
    cin >> num_of_tetrominos;
    cout << "What are the types ?\n";
    
    for(i=0; i<num_of_tetrominos; i++)
    {
        cout << i+1 << ". type: ";
        cin >> type_tet;
        type.push_back(type_tet);
    }
    cout << "\n";

    vector<Tetromino> tetromino_vector;

    for(i=0; i<num_of_tetrominos; i++)
    {
        if(type[i] == 'i' || type[i] == 'I')
            tetromino_vector.push_back(Tetromino(block_type::I));
        if(type[i] == 'l' || type[i] == 'L')
            tetromino_vector.push_back(Tetromino(block_type::L));
        if(type[i] == 's' || type[i] == 'S')
            tetromino_vector.push_back(Tetromino(block_type::S));
        if(type[i] == 'j' || type[i] == 'J')
            tetromino_vector.push_back(Tetromino(block_type::J));
        if(type[i] == 'z' || type[i] == 'Z')
            tetromino_vector.push_back(Tetromino(block_type::Z));
        if(type[i] == 't' || type[i] == 'T')
            tetromino_vector.push_back(Tetromino(block_type::T));
        if(type[i] == 'o' || type[i] == 'O')
            tetromino_vector.push_back(Tetromino(block_type::O));
    }
        
    
    Tetromino fit_board;
    vector<vector<char>> temp_fit;
    for(i=0; i<num_of_tetrominos; i++)
    {
        tetromino_vector[i].print();
        cout << endl;
    }

    for(i=0; i<num_of_tetrominos; i++)
    {
        if(i != 0)
        {
            a = fit_board.how_many_rotate(tetromino_vector[i], temp_fit);
            for(j=0; j<a; j++)
                tetromino_vector[i].rotate('r');  
        }
        fit_board.canfit(tetromino_vector[i], '+');
        
        fit_board.copy(temp_fit);
    }
    fit_board.print();
    
    return 0;
}