#include "Tetris.hpp"

using namespace std;

int main()
{
    int i, random;
    int len_of_row, len_of_clmn;
    vector<char> type;
    char type_tet, selection = '.';
    srand(time(0));

    cout << "What is vertical size of board? \n";
    cin >> len_of_row;
    cout << "What is horizontal size of board? \n";
    cin >> len_of_clmn;

    Tetris board_obj(len_of_row, len_of_clmn); //I created an object
    i=0;
    board_obj.draw();
    Tetromino fit_board(len_of_row, len_of_clmn);
    while(selection != 'q')
    {
        cout << "What is shape of tetris? Please enter  ONE by ONE \n";
        cin >> selection;
        if(selection == 'r' || selection == 'R')
        {
            random = rand()%7 + 1;
            if(random == 1)
                type_tet = 'i';
            if(random == 2)
                type_tet = 'l';
            if(random == 3)
                type_tet = 's';
            if(random == 4)
                type_tet = 'j';
            if(random == 5)
                type_tet = 'z';
            if(random == 6)
                type_tet = 't';
            if(random == 7)
                type_tet = 'o';
        }
        else
            type_tet = selection;
        type.push_back(type_tet);

        if(type[i] == 'i' || type[i] == 'I')
            board_obj.get_Tetro_Obj().setter(block_type::I);
        else if(type[i] == 'l' || type[i] == 'L')
            board_obj.get_Tetro_Obj().setter(block_type::L);
        else if(type[i] == 's' || type[i] == 'S')
            board_obj.get_Tetro_Obj().setter(block_type::S);
        else if(type[i] == 'j' || type[i] == 'J')
            board_obj.get_Tetro_Obj().setter(block_type::J);
        else if(type[i] == 'z' || type[i] == 'Z')
            board_obj.get_Tetro_Obj().setter(block_type::Z);
        else if(type[i] == 't' || type[i] == 'T')
            board_obj.get_Tetro_Obj().setter(block_type::T);
        else if(type[i] == 'o' || type[i] == 'O')
            board_obj.get_Tetro_Obj().setter(block_type::O);
        else
        {
            if(type[i] != 'q')
                cout << "Invalid type!! I don't want to play game with you!\n";
            exit(1);
        }
        if(!(board_obj.Fit(board_obj.get_Tetro_Obj(), '-')))
        {
            cout << "IT İS END OF THE GAME\n";
            break;
        }
        
        i++;
    }
    return 0;
}