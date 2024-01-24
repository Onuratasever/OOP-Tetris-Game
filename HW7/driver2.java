import ben.Tetromino;
import ben.Tetris;
import ben.block_type;

import java.util.Scanner;

/**
 * Test driver2
 */
public class driver2{
    public static void main(String[] args) throws InterruptedException {
        char a;
        System.out.printf("------------CONSTRUCTORS---------\n");
        System.out.println("I will create a Tetris board 10X10\n");
        Tetris board = new Tetris(10,10);
        Tetris board_temp = new Tetris(10,10);

        board.get_Tetro_Obj().setter(block_type.Z);
        System.out.println("\nI will set Tetromino with Z");
        board.get_Tetro_Obj().print();

        System.out.println("\n--------Rotate And Print Function---------");
        board.get_Tetro_Obj().rotate('r');
        board.get_Tetro_Obj().print();

        System.out.println("------------Draw Function --------------\n");
        board.draw();

        System.out.println("---------------Size Functions----------------\n");
        System.out.printf("Number of row: %d\n", board.GetLenOfRow());
        System.out.printf("Number of column: %d\n", board.GetLenOfClmn());

        System.out.println("----------Add Function With Is game over function----------------\n");
        System.out.println("I will add Z tetromino to top");
        board.is_game_over(board.get_Tetro_Obj());
        board.draw();

        System.out.println("---------Validity And Add Functions -------------");
        System.out.println("T tetromino will be added at point 7, 5 if this point is valid for Tetromino\n");
        board.get_Tetro_Obj().setter(block_type.T);
        if(board.isvalid_place(board.get_Tetro_Obj(), 7, 5))
            board.add(board.get_Tetro_Obj(), 7, 5);
        board.draw();

        System.out.println("\n\nI will clean the board by using clone function");
        board.clone_board(board_temp);
        board.draw();

        System.out.println("\n---------------Move And Animate Functions-----------");
        System.out.println("T tetromino will go right 3 times and it will be animated\n");
        System.out.println("Enter a to continue and see animate\n");

        Scanner sc = new Scanner(System.in);
        a = sc.next().charAt(0);

        board.move('r', 3, board_temp);


    }
}