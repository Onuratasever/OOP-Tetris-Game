#include "Tetromino.hpp"
#include "AbstractTetris.hpp"
#include "TetrisArray1D.hpp"
#include "TetrisVector.hpp"
#include "TetrisAdapter.cpp"
#include <fstream>
using namespace std;
using namespace onur;

void global_function(const AbstractTetris& other)
{
    other.draw();
}

int main()
{
     char wait;
    int rotation_count = 0, len_of_row, len_of_clmn, i;

    ifstream save_file;

    save_file.open("save.txt", ios::in);
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
            len_of_row=10;
            len_of_clmn=10;
        }

    }

    cout << "-----------CONSTRUCTORS---------\n";
    cout << "I created an object with size "<<len_of_row <<" X "<< len_of_clmn <<".\nAnd another object with no parameter constructor so it is empty totally\n";
    TetrisArray1D obj1D_array(len_of_row, len_of_clmn);
    TetrisArray1D obj1D_array_temp;

    if(i == 1)
    {
        obj1D_array.readFromFile("save");
    }

    cout << "\n-----------Draw Function---------\n";
    cout << "I will print board of the object\n";
    obj1D_array.draw();


    cout << "\n-----------Size functions---------\n";
    cout << "Number of row: " << obj1D_array.GetLenOfRow();
    cout << "\nNumber of column: " << obj1D_array.GetLenOfClmn();
    cout << "\nSize of 1D array: " << obj1D_array.size();
    

    cout << "\n\n-----------Copy Assignment operator---------\n";
    cout << "I will assign obj board to empty one\n";
    obj1D_array_temp = obj1D_array;
    cout << "Assigned object will printed\n";
    obj1D_array_temp.draw();
    
    obj1D_array.get_Tetro_Obj().setter(block_type::Z);
    cout << "\n\n-----------operator+= funcitons---------\n";
    cout << "Z tetromino will be added to top of the board\n";
    obj1D_array += obj1D_array.get_Tetro_Obj();
    obj1D_array.draw();

    cout << "\n\n-----------Validity and Add funcitons---------\n";
    cout << "T tetromino will be added at point 7, 5 if this point is valid for Tetromino\n";
    obj1D_array.get_Tetro_Obj().setter(block_type::T);
    if(obj1D_array.isvalid_place(obj1D_array.get_Tetro_Obj(), 7, 5))
        obj1D_array.add(obj1D_array.get_Tetro_Obj(), 7, 5);
    obj1D_array.draw();

    
    cout << "\n\nI will clean the board by assigning temp object\n";
    obj1D_array = obj1D_array_temp;


    cout << "\n\n-----------Move and Animate funcitons---------\n";
    cout << "T tetromino will go right 3 times and it will be animated\n";
    cout << "Enter a to continue and see animate\n";
    cin >> wait;
    obj1D_array.get_Tetro_Obj().setter(block_type::T);
    obj1D_array.setlastMove();
    obj1D_array.set_lastmove() += " has rotated " + to_string(rotation_count%4) + " times";
    
    obj1D_array.move('r', 3, obj1D_array_temp);
    cout << "Enter 'a' to continue and to see lastMove function\n";
    cin >> wait;
    
    cout <<"I will print the board with global function\n";
    AbstractTetris &tut = obj1D_array;
    global_function(tut);
    cout << "\n\n-----------LastMove funcitons---------\n";
    obj1D_array.lastMove();
    cout << "\n\n-----------NumberOfMoves funcitons---------\n";
    cout << "Number of moves: " << obj1D_array.numberOfMoves()<<endl;

    cout << "Enter 'a' to see test of TetrisVector class\n";
    cin >> wait;
    
    
    
    
    cout << "\n\n\n\n--------Tetris vector control time--------------\n";

    i=3;
    TetrisVector board_obj_tem;
    if(save_file.good() == true)
    {
        cout << "There is a saved file do you want to continue with it?\nIf you want enter 1 else 0\n";
        cin >> i;
        if(i ==1)
        {
            board_obj_tem.readFromFile("save");
            len_of_row = board_obj_tem.GetLenOfRow();
            len_of_clmn = board_obj_tem.GetLenOfClmn();
        }
        else if(i == 0)
        {
            len_of_row=10;
            len_of_clmn=10;
        }

    }
    cout << "-----------CONSTRUCTORS---------\n";
    cout << "I created an object with size "<<len_of_row <<" X "<< len_of_clmn <<".And another object with no parameter constructor so it is empty totally\n";
    TetrisVector obj_vector(len_of_row, len_of_clmn);
    TetrisVector obj_vector_temp;

    if(i == 1)
    {
        obj_vector.readFromFile("save");
    }


    cout << "\n-----------Draw Function---------\n";
    cout << "I will print board of the object\n";
    obj_vector.draw();


    cout << "\n-----------Size functions---------\n";
    cout << "Number of row: " << obj_vector.GetLenOfRow();
    cout << "\nNumber of column: " << obj_vector.GetLenOfClmn();
    

    cout << "\n\n-----------Copy Assignment operator---------\n";
    cout << "I will assign obj board to empty one\n";
    obj_vector_temp = obj_vector;
    cout << "Assigned object will printed\n";
    obj_vector_temp.draw();
    
    obj_vector.get_Tetro_Obj().setter(block_type::J);
    cout << "\n\n-----------operator+= funcitons---------\n";
    cout << "J tetromino will be added to top of the board\n";
    obj_vector += obj_vector.get_Tetro_Obj();
    obj_vector.draw();

    cout << "\n\n-----------Validity and Add funcitons---------\n";
    cout << "S tetromino will be added at point 7, 5 if this point is valid for Tetromino\n";
    obj_vector.get_Tetro_Obj().setter(block_type::S);
    if(obj_vector.isvalid_place(obj_vector.get_Tetro_Obj(), 7, 5))
        obj_vector.add(obj_vector.get_Tetro_Obj(), 7, 5);
    obj_vector.draw();

    cout << "I will clean the board by assigning temp object\n";
    obj_vector = obj_vector_temp;


    cout << "\n\n-----------Move and Animate funcitons---------\n";
    cout << "S tetromino will go left 4 times and it will be animated\n";
    cout << "Enter a to continue and see animation\n";
    cin >> wait;
    cout << "Enter 'a' to continue\n";

    obj_vector.get_Tetro_Obj().setter(block_type::S);
    obj_vector.setlastMove();
    obj_vector.set_lastmove() += "has rotated " + to_string(rotation_count%4) + " times";


    obj_vector.move('l', 4, obj_vector_temp);
    cout << "Enter 'a' to see LastMove function\n";
    cin >> wait;
    cout <<"I will print the board with global function\n";
    AbstractTetris &ut = obj_vector;
    global_function(ut);

    cout << "\n\n-----------LastMove funcitons---------\n";
    obj_vector.lastMove();
    cout << "\n\n-----------NumberOfMoves funcitons---------\n";
    cout << "Number of moves: " << obj_vector.numberOfMoves()<<endl;
    
    cout << "Enter a to see test of TetrisAdapter class\n";
    cin >> wait;


    



    cout << "\n\n\n\n--------Tetris Adapter control time--------------\n";

    TetrisAdapter<vector> board_obj_te;
    if(save_file.good() == true)
    {
        cout << "There is a saved file do you want to continue with it?\nIf you want enter 1 else 0\n";
        cin >> i;
        if(i ==1)
        {
            board_obj_te.readFromFile("save");
            len_of_row = board_obj_te.GetLenOfRow();
            len_of_clmn = board_obj_te.GetLenOfClmn();
        }
        else if(i == 0)
        {
            len_of_row=10;
            len_of_clmn=10;
        }

    }

    cout << "-----------CONSTRUCTORS---------\n";
    cout << "I created an object with size "<<len_of_row <<" X "<< len_of_clmn <<".\nAnd another object with no parameter constructor so it is empty totally\n";
    TetrisAdapter<vector> obj_adapter(len_of_row, len_of_clmn);
    TetrisAdapter<vector> obj_adapter_temp;

    if(i == 1)
    {
        obj_adapter.readFromFile("save");
    }

    cout << "\n-----------Draw Function---------\n";
    cout << "I will print board of the object\n";
    obj_adapter.draw();


    cout << "\n-----------Size functions---------\n";
    cout << "Number of row: " << obj_adapter.GetLenOfRow();
    cout << "\nNumber of column: " << obj_adapter.GetLenOfClmn();
    

    cout << "\n\n-----------Copy Assignment operator---------\n";
    cout << "I will assign obj board to empty one\n";
    obj_adapter_temp = obj_adapter;
    cout << "Assigned object will printed\n";
    obj_adapter_temp.draw();
    
    obj_adapter.get_Tetro_Obj().setter(block_type::J);
    cout << "\n\n-----------operator+= funcitons---------\n";
    cout << "J tetromino will be added to top of the board\n";
    obj_adapter += obj_adapter.get_Tetro_Obj();
    obj_adapter.draw();

    cout << "\n\n-----------Validity and Add funcitons---------\n";
    cout << "S tetromino will be added at point 7, 5 if this point is valid for Tetromino\n";
    obj_adapter.get_Tetro_Obj().setter(block_type::S);
    if(obj_adapter.isvalid_place(obj_adapter.get_Tetro_Obj(), 7, 5))
        obj_adapter.add(obj_adapter.get_Tetro_Obj(), 7, 5);
    obj_adapter.draw();

    cout << "I will clean the board by assigning temp object\n";
    obj_adapter = obj_adapter_temp;


    cout << "\n\n-----------Move and Animate funcitons---------\n";
    cout << "S tetromino will go right 1 times and it will be animated\n";
    cout << "Enter a to continue and see animation\n";
    cin >> wait;
    obj_adapter.get_Tetro_Obj().setter(block_type::S);
    obj_adapter.setlastMove();
    obj_adapter.set_lastmove() += "has rotated " + to_string(rotation_count%4) + " times";

    obj_adapter.move('r', 1, obj_adapter_temp);
    cout << "Enter 'a' to see LastMove\n";
    cin >> wait;

    cout << "\n\n-----------LastMove funcitons---------\n";
    obj_adapter.lastMove();
    cout << "\n\n-----------NumberOfMoves funcitons---------\n";
    cout << "Number of moves: " << obj_adapter.numberOfMoves()<<endl;
    
    save_file.close();
    return 0;
}