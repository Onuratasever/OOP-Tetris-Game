#include "Tetris.hpp"

using namespace std;
using namespace Onur;
int main()
{
    int i, k, random;
    int len_of_row, len_of_clmn;
    int rotation_count, move_count;
    char type_tet, selection = '.', move_direction, rotation_direction;
    srand(time(0));

    cout << "What is vertical size of board? \n";
    cin >> len_of_row;
    cout << "What is horizontal size of board? \n";
    cin >> len_of_clmn;

    Tetris board_obj(len_of_row, len_of_clmn); //I created an object
    Tetris temp(len_of_row, len_of_clmn);
    board_obj.animate(temp);

    while(selection != 'q')
    {
        for(int i=0; i<board_obj.GetLenOfRow(); i++)
        {
            for(int j=0; j<board_obj.GetLenOfClmn(); j++)
                temp.getBoard()[i][j] = board_obj.getBoard()[i][j];
        }
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

        if(type_tet == 'i' || type_tet == 'I')
            board_obj.get_Tetro_Obj().setter(block_type::I);
        else if(type_tet == 'l' || type_tet == 'L')
            board_obj.get_Tetro_Obj().setter(block_type::L);
        else if(type_tet == 's' || type_tet == 'S')
            board_obj.get_Tetro_Obj().setter(block_type::S);
        else if(type_tet == 'j' || type_tet == 'J')
            board_obj.get_Tetro_Obj().setter(block_type::J);
        else if(type_tet == 'z' || type_tet == 'Z')
            board_obj.get_Tetro_Obj().setter(block_type::Z);
        else if(type_tet == 't' || type_tet == 'T')
            board_obj.get_Tetro_Obj().setter(block_type::T);
        else if(type_tet == 'o' || type_tet == 'O')
            board_obj.get_Tetro_Obj().setter(block_type::O);
        else
        {
            if(type_tet != 'q')
                cout << "Invalid type!! I don't want to play game with you!\n";
            exit(1);
        }

        cout << "What is the rotation direction? (L for counter clockwise, R for clockwise)\n";
        cin >> rotation_direction;
        if(rotation_direction != 'L' && rotation_direction != 'l' && rotation_direction != 'r' && rotation_direction != 'R')
        {
            cerr << "Invalid rotation direction!";
            exit(1);
        }

        cout << "What is the rotation count?\n";
        cin >> rotation_count;

        cout << "What is the move direction? (L for left, R for right)\n";
        cin >> move_direction;
        if(move_direction != 'L' && move_direction != 'l' && move_direction != 'r' && move_direction != 'R')
        {
            cerr << "Invalid move direction!";
            exit(1);
        }

        cout << "What is the move count?\n";
        cin >> move_count;
        for(int i=0; i<board_obj.GetLenOfRow(); i++)
        {
            for(int j=0; j<board_obj.GetLenOfClmn(); j++)
                board_obj.getBoard()[i][j] = temp.getBoard()[i][j];
        }
        //board_obj += board_obj.get_Tetro_Obj();
        if(rotation_direction == 'L' || rotation_direction == 'l')
        {
            for(k=0; k<rotation_count%4; k++) // I rotated tetrominos as wanted
            {
                board_obj += board_obj.get_Tetro_Obj();// i add tetromino to the board
                board_obj.animate(temp);// and i printed
                board_obj.get_Tetro_Obj().rotate('l');
                board_obj.get_Tetro_Obj().print();
                for(int i=0; i<board_obj.GetLenOfRow(); i++)
                {
                    for(int j=0; j<board_obj.GetLenOfClmn(); j++)
                        board_obj.getBoard()[i][j] = temp.getBoard()[i][j];
                }
            }
            board_obj += board_obj.get_Tetro_Obj();
            board_obj.animate(temp);
            for(int i=0; i<board_obj.GetLenOfRow(); i++)
            {
                for(int j=0; j<board_obj.GetLenOfClmn(); j++)
                    board_obj.getBoard()[i][j] = temp.getBoard()[i][j];
            }
        }
        else if(rotation_direction == 'R' || rotation_direction == 'r')
        {
            for(k=0; k<rotation_count%4; k++)// I rotated tetrominos as wanted
            {
                board_obj += board_obj.get_Tetro_Obj();// i add tetromino to the board
                board_obj.animate(temp);// and i printed
                board_obj.get_Tetro_Obj().rotate('r');
                for(int i=0; i<board_obj.GetLenOfRow(); i++)
                {
                    for(int j=0; j<board_obj.GetLenOfClmn(); j++)
                        board_obj.getBoard()[i][j] = temp.getBoard()[i][j];
                }
            }
            board_obj += board_obj.get_Tetro_Obj();
            board_obj.animate(temp);
            for(int i=0; i<board_obj.GetLenOfRow(); i++)
            {
                for(int j=0; j<board_obj.GetLenOfClmn(); j++)
                    board_obj.getBoard()[i][j] = temp.getBoard()[i][j];
            }
        }

        board_obj.move(move_direction, move_count, temp);
    }
    return 0;
}





