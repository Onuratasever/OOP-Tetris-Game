import ben.Tetromino;
import ben.Tetris;
import ben.block_type;

import java.util.Random;
import java.util.Scanner;
/**
 * Test Driver1
 */
public class driver1{

    public static void main(String[] args) throws InterruptedException
    {
        int i, k,j, random;
        int len_of_row, len_of_clmn;
        int rotation_count, move_count;
        char type_tet='.', selection = '.', move_direction='.', rotation_direction='.';
        Scanner sc = new Scanner(System.in);

        System.out.printf("What is vertical size of board? \n");
        char[] number;
        number =sc.next().toCharArray();
        for(k=0; k<number.length; k++)
        {
            if(!(number[k] >= '0' &&  number[k] <= '9'))
            {
                System.out.printf("Invalid size!\n");
                System.exit(1);
            }
        }
        len_of_row = Integer.parseInt(String.valueOf(number));
        System.out.printf( "What is horizontal size of board? \n");
        number =sc.next().toCharArray();
        for(k=0; k<number.length; k++)
        {
            if(!(number[k] >= '0' &&  number[k] <= '9'))
            {
                System.out.printf("Invalid size!\n");
                System.exit(1);
            }
        }
        len_of_clmn = Integer.parseInt(String.valueOf(number));;
        
        Tetris board_obj = new Tetris(len_of_row, len_of_clmn); //I created an object
        Tetris temp = new Tetris(len_of_row, len_of_clmn);
        board_obj.animate(temp);

        while(selection != 'q')
        {
            Random rand = new Random();
            for(i=0; i<board_obj.GetLenOfRow(); i++)
            {
                for(j=0; j<board_obj.GetLenOfClmn(); j++)
                    temp.getBoard()[i][j] = board_obj.getBoard()[i][j];
            }
            System.out.printf("What is shape of tetris? Please enter  ONE by ONE \n");
            selection = sc.next().charAt(0);
            if(selection == 'r' || selection == 'R')
            {
                random = rand.nextInt(8);
                random = (random % 7) + 1;
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
                board_obj.get_Tetro_Obj().setter(block_type.I);
            else if(type_tet == 'l' || type_tet == 'L')
                board_obj.get_Tetro_Obj().setter(block_type.L);
            else if(type_tet == 's' || type_tet == 'S')
                board_obj.get_Tetro_Obj().setter(block_type.S);
            else if(type_tet == 'j' || type_tet == 'J')
                board_obj.get_Tetro_Obj().setter(block_type.J);
            else if(type_tet == 'z' || type_tet == 'Z')
                board_obj.get_Tetro_Obj().setter(block_type.Z);
            else if(type_tet == 't' || type_tet == 'T')
                board_obj.get_Tetro_Obj().setter(block_type.T);
            else if(type_tet == 'o' || type_tet == 'O')
                board_obj.get_Tetro_Obj().setter(block_type.O);
            else
            {
                if(type_tet != 'q')
                {
                    System.out.printf("Invalid type!! I don't want to play game with you!\n");
                }
                System.exit(1);
            }

            random = rand.nextInt(7);
            if(random % 2 == 1)
                rotation_direction = 'r';
            else if (random % 2 == 0)
                rotation_direction = 'l';

            rotation_count = rand.nextInt(5);

            random = rand.nextInt(7);
            if(random % 2 == 1)
                move_direction = 'r';
            else if (random % 2 == 0)
                move_direction = 'l';
                
            move_count = rand.nextInt(len_of_clmn/2 + 2);

            for(i=0; i<board_obj.GetLenOfRow(); i++)
            {
                for(j=0; j<board_obj.GetLenOfClmn(); j++)
                    board_obj.getBoard()[i][j] = temp.getBoard()[i][j];
            }
            if(rotation_direction == 'L' || rotation_direction == 'l')
            {
                for(k=0; k<rotation_count%4; k++) // I rotated tetrominos as wanted
                {
                    board_obj.is_game_over( board_obj.get_Tetro_Obj());// i add tetromino to the board
                    board_obj.animate(temp);// and i printed
                    board_obj.get_Tetro_Obj().rotate('l');
                   // board_obj.get_Tetro_Obj().print();
                    for(i=0; i<board_obj.GetLenOfRow(); i++)
                    {
                        for(j=0; j<board_obj.GetLenOfClmn(); j++)
                            board_obj.getBoard()[i][j] = temp.getBoard()[i][j];
                    }
                }
                board_obj.is_game_over( board_obj.get_Tetro_Obj());
                board_obj.animate(temp);
                for(i=0; i<board_obj.GetLenOfRow(); i++)
                {
                    for(j=0; j<board_obj.GetLenOfClmn(); j++)
                        board_obj.getBoard()[i][j] = temp.getBoard()[i][j];
                }
            }
            else if(rotation_direction == 'R' || rotation_direction == 'r')
            {
                for(k=0; k<rotation_count%4; k++)// I rotated tetrominos as wanted
                {
                    board_obj.is_game_over( board_obj.get_Tetro_Obj());// i add tetromino to the board
                    board_obj.animate(temp);// and i printed
                    board_obj.get_Tetro_Obj().rotate('r');
                    for(i=0; i<board_obj.GetLenOfRow(); i++)
                    {
                        for(j=0; j<board_obj.GetLenOfClmn(); j++)
                            board_obj.getBoard()[i][j] = temp.getBoard()[i][j];
                    }
                }
                board_obj.is_game_over( board_obj.get_Tetro_Obj());
                board_obj.animate(temp);
                for(i=0; i<board_obj.GetLenOfRow(); i++)
                {
                    for(j=0; j<board_obj.GetLenOfClmn(); j++)
                        board_obj.getBoard()[i][j] = temp.getBoard()[i][j];
                }
            }

            board_obj.move(move_direction, move_count, temp);
        }
    }
}
