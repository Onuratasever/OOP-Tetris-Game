#include "Tetris.hpp"

int main()
{
    int len;
    cout<< "This is 10X10 board\n";
    Tetris board_obj(10, 10);
    Tetris temp(10, 10);
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
            temp.getBoard()[i][j] = board_obj.getBoard()[i][j];
    }
    cout <<"I create tetromino j\n";
    board_obj.get_Tetro_Obj().setter(block_type::J);
    cout << "I will print tetromino\n";
    board_obj.get_Tetro_Obj().print();
    cout << "And now, i will print tetromino by using getShapeOfTetris func\n";
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            cout << board_obj.get_Tetro_Obj().getShapeOfTetris()[i][j];
        cout << endl;
    }
    cout << "And now, i will print type pf tetromino: ";
    cout << board_obj.get_Tetro_Obj().get_type() << endl;
    cout << "And now, i will rotate and print tetromino: \n";
    board_obj.get_Tetro_Obj().rotate('r');
    board_obj.get_Tetro_Obj().print();
    cout << "I will print vertical and horizontal length of board by using getters: \n";
    cout << "Number of row: " << board_obj.GetLenOfRow() << endl;
    cout << "Number of column: " << board_obj.GetLenOfClmn() << endl;
    cout << "I will calculate the vertical length of tetromino\n";
    board_obj.lenght_of_object(len, board_obj.get_Tetro_Obj());
    cout << "Vertical len of tetromino is: " << len << endl;
    cout << "I will add tetromino to the board by using += operator and i will print the board\n";
    cout << "Add function is already implemented inside of += operator.\n";
    board_obj += board_obj.get_Tetro_Obj();
    cout << "I will use move func and it will move 2 unit right. It will also animate. There is sleep because animate will delete terminal\n";
    sleep(3);
    for(int i=0; i<board_obj.GetLenOfRow(); i++)
    {
        for(int j=0; j<board_obj.GetLenOfClmn(); j++)
            board_obj.getBoard()[i][j] = temp.getBoard()[i][j];
    }
    board_obj.move('r', 2, temp);
    return 0;
}