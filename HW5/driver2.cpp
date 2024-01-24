#include "Tetromino.hpp"
#include "AbstractTetris.hpp"
#include "TetrisArray1D.hpp"
#include "TetrisVector.hpp"
#include "TetrisAdapter.cpp"
using namespace std;
using namespace onur;

int main()
{
    int i, k, random;
    int len_of_row, len_of_clmn;
    int rotation_count, move_count, continu = 1;
    char type_tet, selection = '.', move_direction, rotation_direction, class_type;
    string number;
    srand(time(0));

    ifstream save_file;
    cout << "Which class type do you want to use? 'V' for TetrisVector, 'A' for TetrisAdapter, 'D' for TetrisArray1D\n";
    cin >> class_type;
    save_file.open("save.txt", ios::in);
    
    //TetrisArray1D board_obj_temp;

    if (class_type == 'V' || class_type == 'v')
    {    
        TetrisVector board_obj_temp;
        if(save_file.good() == true)
        {
            cout << "There is a saved file do you want to continue with it?\nIf you want enter 1 else 0\n";
            cin >> i;
            if(i ==1)
            {
                board_obj_temp.readFromFile("save");
                len_of_row = board_obj_temp.GetLenOfRow();
                len_of_clmn = board_obj_temp.GetLenOfClmn();
            }
            else if(i == 0)
            {
                cout << "What is vertical size of board? \n";
                cin >> number;
                for(k=0; number[k] != '\0'; k++)
                {
                    if(!(number[k] >= '0' &&  number[k] <= '9'))
                    {
                        cerr << "Invalid size!";
                        exit(1);
                    }
                }
                len_of_row = stoi(number);
                cout << "What is horizontal size of board? \n";
                cin >> number;
                for(k=0; number[k] != '\0'; k++)
                {
                    if(!(number[k] >= '0' &&  number[k] <= '9'))
                    {
                        cerr << "Invalid size!";
                        exit(1);
                    }
                }
                len_of_clmn = stoi(number);
            }

        }
        else
        {
            cout << "What is vertical size of board? \n";
            cin >> number;
            for(k=0; number[k] != '\0'; k++)
            {
                if(!(number[k] >= '0' &&  number[k] <= '9'))
                {
                    cerr << "Invalid size!";
                    exit(1);
                }
            }
            len_of_row = stoi(number);
            cout << "What is horizontal size of board? \n";
            cin >> number;
            for(k=0; number[k] != '\0'; k++)
            {
                if(!(number[k] >= '0' &&  number[k] <= '9'))
                {
                    cerr << "Invalid size!";
                    exit(1);
                }
            }
            len_of_clmn = stoi(number);
        }
        TetrisVector board_obj(len_of_row, len_of_clmn); //I created an object
        TetrisVector temp(len_of_row, len_of_clmn);
        if(i == 1)
        {
            board_obj.readFromFile("save");
            temp.readFromFile("save");
        }
        save_file.close();
        
        board_obj.animate(temp);

        while(selection != 'q')
        {
            temp = board_obj;
            cout << "What is shape of tetris? Please enter  ONE by ONE \n";
            board_obj.set_lastmove() = "";
            cin >> selection;
            if(selection == 'q')
            {
                board_obj.writeToFile("save");
                break;
            }
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
                if(rotation_direction == 'q' || rotation_direction == 'Q')
                    board_obj.writeToFile("save");
                cerr << "Invalid rotation direction!";
                exit(1);
            }

            cout << "What is the rotation count?\n";
            cin >> rotation_count;
            
            cout << "What is the move direction? (L for left, R for right)\n";
            cin >> move_direction;
            if(move_direction != 'L' && move_direction != 'l' && move_direction != 'r' && move_direction != 'R')
            {
                if(rotation_direction == 'q' || rotation_direction == 'Q')
                    board_obj.writeToFile("save");
                cerr << "Invalid move direction!";
                exit(1);
            }

            cout << "What is the move count?\n";
            cin >> move_count;
            
            board_obj = temp;
            board_obj.setlastMove();
            board_obj.set_lastmove() += "has rotated " + to_string(rotation_count%4) + " times";
            if(rotation_direction == 'L' || rotation_direction == 'l')
            {
                for(k=0; k<rotation_count%4; k++) // I rotated tetrominos as wanted
                {
                    board_obj.increment_of_moves();
                    board_obj += board_obj.get_Tetro_Obj();// i add tetromino to the board
                    board_obj.animate(temp);// and i printed
                    board_obj.get_Tetro_Obj().rotate('l');
                    
                    board_obj = temp;
                }
                board_obj += board_obj.get_Tetro_Obj();
                board_obj.animate(temp);
                
                board_obj = temp;
            }
            else if(rotation_direction == 'R' || rotation_direction == 'r')
            {
                for(k=0; k<rotation_count%4; k++)// I rotated tetrominos as wanted
                {
                    board_obj.increment_of_moves();
                    board_obj += board_obj.get_Tetro_Obj();// i add tetromino to the board
                    board_obj.animate(temp);// and i printed
                    board_obj.get_Tetro_Obj().rotate('r');
                
                    board_obj = temp;
                }
                board_obj += board_obj.get_Tetro_Obj();
                board_obj.animate(temp);
                
                board_obj = temp;
            }

            board_obj.move(move_direction, move_count, temp);
        }
    }
    if (class_type == 'A' || class_type == 'a') 
    {    
        TetrisAdapter<vector> board_obj_temp;
        
        if(save_file.good() == true)
        {
            cout << "There is a saved file do you want to continue with it?\nIf you want enter 1 else 0\n";
            cin >> i;
            if(i ==1)
            {
                board_obj_temp.readFromFile("save");
                len_of_row = board_obj_temp.GetLenOfRow();
                len_of_clmn = board_obj_temp.GetLenOfClmn();
            }
            else if(i == 0)
            {
                cout << "What is vertical size of board? \n";
                cin >> number;
                for(k=0; number[k] != '\0'; k++)
                {
                    if(!(number[k] >= '0' &&  number[k] <= '9'))
                    {
                        cerr << "Invalid size!";
                        exit(1);
                    }
                }
                len_of_row = stoi(number);
                cout << "What is horizontal size of board? \n";
                cin >> number;
                for(k=0; number[k] != '\0'; k++)
                {
                    if(!(number[k] >= '0' &&  number[k] <= '9'))
                    {
                        cerr << "Invalid size!";
                        exit(1);
                    }
                }
                len_of_clmn = stoi(number);
            }

        }
        else
        {
            cout << "What is vertical size of board? \n";
            cin >> number;
            for(k=0; number[k] != '\0'; k++)
            {
                if(!(number[k] >= '0' &&  number[k] <= '9'))
                {
                    cerr << "Invalid size!";
                    exit(1);
                }
            }
            len_of_row = stoi(number);
            cout << "What is horizontal size of board? \n";
            cin >> number;
            for(k=0; number[k] != '\0'; k++)
            {
                if(!(number[k] >= '0' &&  number[k] <= '9'))
                {
                    cerr << "Invalid size!";
                    exit(1);
                }
            }
            len_of_clmn = stoi(number);
        }
        TetrisAdapter<vector> board_obj(len_of_row, len_of_clmn);
        TetrisAdapter<vector> temp(len_of_row, len_of_clmn);
    
        if(i == 1)
        {
            board_obj.readFromFile("save");
            temp.readFromFile("save");
        }
        save_file.close();
        
        board_obj.animate(temp);

        while(selection != 'q')
        {
            temp = board_obj;
            cout << "What is shape of tetris? Please enter  ONE by ONE \n";
            board_obj.set_lastmove() = "";
            cin >> selection;
            if(selection == 'q')
            {
                board_obj.writeToFile("save");
                break;
            }
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
                if(rotation_direction == 'q' || rotation_direction == 'Q')
                    board_obj.writeToFile("save");
                cerr << "Invalid rotation direction!";
                exit(1);
            }

            cout << "What is the rotation count?\n";
            cin >> rotation_count;
            
            cout << "What is the move direction? (L for left, R for right)\n";
            cin >> move_direction;
            if(move_direction != 'L' && move_direction != 'l' && move_direction != 'r' && move_direction != 'R')
            {
                if(rotation_direction == 'q' || rotation_direction == 'Q')
                    board_obj.writeToFile("save");
                cerr << "Invalid move direction!";
                exit(1);
            }

            cout << "What is the move count?\n";
            cin >> move_count;
            
            board_obj = temp;
            board_obj.setlastMove();
            board_obj.set_lastmove() += "has rotated " + to_string(rotation_count%4) + " times";
            if(rotation_direction == 'L' || rotation_direction == 'l')
            {
                for(k=0; k<rotation_count%4; k++) // I rotated tetrominos as wanted
                {
                    board_obj.increment_of_moves();
                    board_obj += board_obj.get_Tetro_Obj();// i add tetromino to the board
                    board_obj.animate(temp);// and i printed
                    board_obj.get_Tetro_Obj().rotate('l');
                    
                    board_obj = temp;
                }
                board_obj += board_obj.get_Tetro_Obj();
                board_obj.animate(temp);
                
                board_obj = temp;
            }
            else if(rotation_direction == 'R' || rotation_direction == 'r')
            {
                for(k=0; k<rotation_count%4; k++)// I rotated tetrominos as wanted
                {
                    board_obj.increment_of_moves();
                    board_obj += board_obj.get_Tetro_Obj();// i add tetromino to the board
                    board_obj.animate(temp);// and i printed
                    board_obj.get_Tetro_Obj().rotate('r');
                
                    board_obj = temp;
                }
                board_obj += board_obj.get_Tetro_Obj();
                board_obj.animate(temp);
                
                board_obj = temp;
            }

            board_obj.move(move_direction, move_count, temp);
        }
    }

    if (class_type == 'D' || class_type == 'd')
    {    
        TetrisArray1D board_obj_temp;
        if(save_file.good() == true)
        {
            cout << "There is a saved file do you want to continue with it?\nIf you want enter 1 else 0\n";
            cin >> i;
            if(i ==1)
            {
                board_obj_temp.readFromFile("save");
                len_of_row = board_obj_temp.GetLenOfRow();
                len_of_clmn = board_obj_temp.GetLenOfClmn();
            }
            else if(i == 0)
            {
                cout << "What is vertical size of board? \n";
                cin >> number;
                for(k=0; number[k] != '\0'; k++)
                {
                    if(!(number[k] >= '0' &&  number[k] <= '9'))
                    {
                        cerr << "Invalid size!";
                        exit(1);
                    }
                }
                len_of_row = stoi(number);
                cout << "What is horizontal size of board? \n";
                cin >> number;
                for(k=0; number[k] != '\0'; k++)
                {
                    if(!(number[k] >= '0' &&  number[k] <= '9'))
                    {
                        cerr << "Invalid size!";
                        exit(1);
                    }
                }
                len_of_clmn = stoi(number);
            }

        }
        else
        {
            cout << "What is vertical size of board? \n";
            cin >> number;
            for(k=0; number[k] != '\0'; k++)
            {
                if(!(number[k] >= '0' &&  number[k] <= '9'))
                {
                    cerr << "Invalid size!";
                    exit(1);
                }
            }
            len_of_row = stoi(number);
            cout << "What is horizontal size of board? \n";
            cin >> number;
            for(k=0; number[k] != '\0'; k++)
            {
                if(!(number[k] >= '0' &&  number[k] <= '9'))
                {
                    cerr << "Invalid size!";
                    exit(1);
                }
            }
            len_of_clmn = stoi(number);
        }
        //TetrisAdapter<vector> board_obj(len_of_row, len_of_clmn);
        //TetrisAdapter<vector> temp(len_of_row, len_of_clmn);
        TetrisArray1D board_obj(len_of_row, len_of_clmn); //I created an object
        TetrisArray1D temp(len_of_row, len_of_clmn);
        //TetrisVector board_obj(len_of_row, len_of_clmn); //I created an object
        //TetrisVector temp(len_of_row, len_of_clmn);
        if(i == 1)
        {
            board_obj.readFromFile("save");
            temp.readFromFile("save");
        }
        save_file.close();
        
        board_obj.animate(temp);

        while(selection != 'q')
        {
            temp = board_obj;
            cout << "What is shape of tetris? Please enter  ONE by ONE \n";
            board_obj.set_lastmove() = "";
            cin >> selection;
            if(selection == 'q')
            {
                board_obj.writeToFile("save");
                break;
            }
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
                if(rotation_direction == 'q' || rotation_direction == 'Q')
                    board_obj.writeToFile("save");
                cerr << "Invalid rotation direction!";
                exit(1);
            }

            cout << "What is the rotation count?\n";
            cin >> rotation_count;
            
            cout << "What is the move direction? (L for left, R for right)\n";
            cin >> move_direction;
            if(move_direction != 'L' && move_direction != 'l' && move_direction != 'r' && move_direction != 'R')
            {
                if(rotation_direction == 'q' || rotation_direction == 'Q')
                    board_obj.writeToFile("save");
                cerr << "Invalid move direction!";
                exit(1);
            }

            cout << "What is the move count?\n";
            cin >> move_count;
            
            board_obj = temp;
            board_obj.setlastMove();
            board_obj.set_lastmove() += "has rotated " + to_string(rotation_count%4) + " times";
            if(rotation_direction == 'L' || rotation_direction == 'l')
            {
                for(k=0; k<rotation_count%4; k++) // I rotated tetrominos as wanted
                {
                    board_obj.increment_of_moves();
                    board_obj += board_obj.get_Tetro_Obj();// i add tetromino to the board
                    board_obj.animate(temp);// and i printed
                    board_obj.get_Tetro_Obj().rotate('l');
                    
                    board_obj = temp;
                }
                board_obj += board_obj.get_Tetro_Obj();
                board_obj.animate(temp);
                
                board_obj = temp;
            }
            else if(rotation_direction == 'R' || rotation_direction == 'r')
            {
                for(k=0; k<rotation_count%4; k++)// I rotated tetrominos as wanted
                {
                    board_obj.increment_of_moves();
                    board_obj += board_obj.get_Tetro_Obj();// i add tetromino to the board
                    board_obj.animate(temp);// and i printed
                    board_obj.get_Tetro_Obj().rotate('r');
                
                    board_obj = temp;
                }
                board_obj += board_obj.get_Tetro_Obj();
                board_obj.animate(temp);
                
                board_obj = temp;
            }

            board_obj.move(move_direction, move_count, temp);
        }
    }
    
    return 0;
}