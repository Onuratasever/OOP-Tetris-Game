package ben;

/**
 * Tetris
 */
public class Tetris {

    private Tetromino tetro_obj;
    private int row, clmn;
    private char[][] board;
    
    /**
     * Constructor it arranges size of board and it generates Tetromino
     * @param len_of_row It is height of board
     * @param len_of_clmn It is width of board
     * @author onuratasever
     */
    public Tetris(int len_of_row, int len_of_clmn)
    {
        row = len_of_row;
        clmn = len_of_clmn;
        board = new char[len_of_row][len_of_clmn];
        tetro_obj = new Tetromino();
        
        for(int i=0; i<len_of_row; i++)
        {
            for(int k=0; k<len_of_clmn; k++)
            {
                board[i][k] = '*';
            }
        }
    }

   /**
    * It copy Tetris parameter to main Tetris object
    * @param temp It is the Tetris board we want to copy
    * @author onuratasever
    */
    public void clone_board(Tetris temp)
    {
        row = temp.GetLenOfRow();
        clmn = temp.GetLenOfClmn();

        board = new char[row][clmn];
        for(int i=0; i<row; i++)
        {
            for(int k=0; k<clmn; k++)
            {
                board[i][k] = temp.board[i][k];
            }
        }
    }
    
    /**
     * It prints the board with X frame.
     * @author onuratasever
     */
    public void draw()
    {
        for(int u =clmn+2; u>0; u--) 
            System.out.printf("X");
        System.out.printf("\n");
        for(int i=0; i<GetLenOfRow(); i++)
        {
            System.out.printf("X");


            for(int j=0; j<GetLenOfClmn(); j++)
            {
                if (board[i][j] != '*')
                    System.out.printf("%c",  board[i][j]);
                else
                    System.out.printf(" ");
            }
            System.out.printf("X");
            System.out.printf("\n");
        }
        for(int u =clmn+2; u>0; u--)
            System.out.printf("X");
        System.out.printf("\n");
    }

    /**
     * It get Tetromino object
     * @return It returns Tetromino object which is in Tetris class.
     * @author onuratasever
     */
    public Tetromino get_Tetro_Obj()
    {
        return (tetro_obj);
    }

    /**
     * It get Tetris board
     * @return It returns board
     * @author onuratasever
     */
    public char[][] getBoard() {return (board);}

    /**
     * It get height of board
     * @return It returns row
     * @author onuratasever
     */
    public int GetLenOfRow(){return (row);};
    
    /**
     * It get width of board
     * @return It returns column
     * @author onuratasever
     */
    public int GetLenOfClmn(){return (clmn);};

    /**
     * It controls the if places is empty.
     * @param other It is the Tetromino we want to add
     * @param i It is the row number of coordinates that we want to add tetromino
     * @param j It is the column number of coordinates that we want to add tetromino
     * @return If all places are empty for Tetromino, it returns true else false
     * @author onuratasever
     */
    public boolean isvalid_place(Tetromino other, int i, int j)
    {
        int x, y, temp_x=0, temp_y=0, count = 0, a;
        
        if(i >= GetLenOfRow() || j >= GetLenOfClmn() || j<0 || i<0)
            return false;
        for(x= 4 - 1; x>=0 ; x--)
        {
            for(y=0; y<4; y++)
            {
                if(other.getShapeOfTetris()[x][y] != '*')
                {
                    if(count != 0)
                    {
                        a=GetLenOfClmn();
                        if((j + y - temp_y) < a)
                        {
                            if((i + x - temp_x) >= 0 && (j + y - temp_y) >= 0 && (i + x - temp_x) < GetLenOfRow())
                            {
                                if(board[i + x - temp_x][j + y - temp_y] == '*')
                                {
                                    i = i + x - temp_x;
                                    j = j + y - temp_y;
                                }
                                else
                                    return false;
                            }
                            else
                                return false;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    temp_x = x;
                    temp_y = y;
                    count++;
                }
            }
        }
        return true;
    }

    /**
     * It add Tetromino if coordinates are valid
     * @param other  It is the Tetromino we want to add
     * @param i It is the row number of coordinates that we want to add tetromino
     * @param j It is the column number of coordinates that we want to add tetromino
     * @author onuratasever
     */
    public void add(Tetromino other, int i, int j)
    {
        int x, y, temp_x=0, temp_y=0, count = 0;
        for(x= 4 - 1; x>=0 ; x--)
        {
            for(y=0; y<4; y++)
            {
                if(other.getShapeOfTetris()[x][y] != '*')
                {
                    if(count != 0)
                    {
                        if((i + x - temp_x) >= 0 && (j + y - temp_y) >= 0 && (i + x - temp_x) < GetLenOfRow() && (j + y - temp_y) < GetLenOfClmn() && getBoard()[i + x - temp_x][j + y - temp_y] == '*' )
                        {
                            i = i + x - temp_x;
                            j = j + y - temp_y;
                            board[i][j] = other.getShapeOfTetris()[x][y];
                        }
                    }
                    else
                        board[i][j] = other.getShapeOfTetris()[x][y];
                    temp_x = x;
                    temp_y = y;
                    count++;
                }
            }
        }
    }

    /**
     * It finds height of object
     * @param len_of_vertical It is the lenght of Tetromino in vertical.
     * @param other It is the Tetromino we want to learn it's height.
     * @return It returns height
     * @author onuratasever
     */
    public int lenght_of_object(int len_of_vertical, Tetromino other)
    {
        int i, j;
        len_of_vertical =0;

        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                if(other.getShapeOfTetris()[i][j] != '*')
                {
                    len_of_vertical = len_of_vertical + 1;
                    break;
                }
            }
        }
        return len_of_vertical;
    }

    /**
     * It controls the top of board coordinates which we want to add Tetromino on top of board.
     * @param obj It is the Tetromino we want to add on top of the board
     * @author onuratasever
     */
    public void is_game_over(Tetromino obj)
    {
        int vertical_len_of_tetromino=0;

        vertical_len_of_tetromino=lenght_of_object(vertical_len_of_tetromino, obj);

        if(isvalid_place(obj, vertical_len_of_tetromino - 1, (GetLenOfClmn()-1) / 2) && board[vertical_len_of_tetromino - 1][(GetLenOfClmn()-1) / 2] == '*')
        {
            add(obj, vertical_len_of_tetromino - 1, (GetLenOfClmn()-1) / 2);
        }
        else
        {
            System.out.printf("Game OVER!\n\n");
            System.exit(1);
        }
    }

    /**
     * It moves Tetromino from top to coordinates.
     * @param move_direction It is the direction that Tetromino move
     * @param move_count It is the count of moving
     * @param temp It is to keep old version of board.
     * @throws InterruptedException It is for sleep function
     * @author onuratasever
     */
    public void move(char move_direction, int move_count, Tetris temp) throws InterruptedException
    {
        int row=0, clmn, counter=0, i;
        row = lenght_of_object(row, get_Tetro_Obj());
        row = row -1;
        clmn = (GetLenOfClmn()-1) / 2;
        if(move_direction == 'r' || move_direction == 'R')
        {
            for(i=0; i<move_count && counter == 0; i++)
            {   
                if(getBoard()[row][clmn] == '*')
                {
                    if(!isvalid_place(get_Tetro_Obj(), row, clmn+1))
                    {
                        break;
                    }
                    else
                    {
                        clmn += 1;
                    }
                }
                else
                {
                    clmn -= 1;
                    break;
                }
            }
        }   
        else if(move_direction == 'l' || move_direction == 'L')
        {
            for(i=0; i<move_count && counter == 0; i++)
            {
                if(getBoard()[row][clmn] == '*')
                {
                    if(!isvalid_place(get_Tetro_Obj(), row, clmn-1))
                    {
                        break;
                    }
                    else
                    {
                        clmn -= 1;
                    }
                }
                else
                {
                    clmn += 1;
                    break;
                }
            }
        }
        while(board[row][clmn] == '*') 
        {
            if(!isvalid_place(get_Tetro_Obj(), row, clmn))
                break;
            row += 1;
            if(row == GetLenOfRow()) break;
        }
        row -= 1;
        animate(temp, row, clmn);
    }

    /**
     * This is overloaded function. It does not move, just rotated animate.
     * @param temp It is to keep old version of board.
     * @throws InterruptedException It is for sleep function
     * @author onuratasever
     */
    public void animate(Tetris temp) throws InterruptedException
    {
    
        System.out.printf("\033[2J" + "\033[0;0f");
        draw();
        for(int u=0; u<GetLenOfRow(); u++)
        {
            for(int y=0; y<GetLenOfClmn(); y++)
                board[u][y] = temp.getBoard()[u][y];
        }
            Thread.sleep(50);
    }

    /**
     * This is overloaded function. It animates moving.
     * @param temp It is to keep old version of board.
     * @param i It is the row number of coordinates that we want to add tetromino
     * @param j It is the column number of coordinates that we want to add tetromino
     * @throws InterruptedException It is for sleep function
     * @author onuratasever
     */
    public void animate(Tetris temp, int i, int j) throws InterruptedException
    {
        int len=0, a; 
        len= lenght_of_object(len, get_Tetro_Obj());
        if(i >= 0 && j >= 0)
        {
            if(j > (GetLenOfClmn()-1)/2)
            {
                for(a=(GetLenOfClmn()-1)/2; a<=j; a++)
                {
                    System.out.printf("\033[2J" + "\033[0;0f");
                    add(get_Tetro_Obj(), len-1, a);
                    draw();
                    for(int u=0; u<GetLenOfRow(); u++)
                    {
                        for(int y=0; y<GetLenOfClmn(); y++)
                            board[u][y] = temp.getBoard()[u][y];
                    }
                Thread.sleep(50);
                }
            }
            else
            {
                for(a=(GetLenOfClmn()-1)/2; a>=j; a--)
                {
                    System.out.printf("\033[2J" + "\033[0;0f");
                    add(get_Tetro_Obj(), len-1, a);
                    draw();
                    for(int u=0; u<GetLenOfRow(); u++)
                    {
                        for(int y=0; y<GetLenOfClmn(); y++)
                            board[u][y] = temp.getBoard()[u][y];
                    }
                Thread.sleep(50);
                }
            }
            for(a=0 + len - 1; a < i; a++)
            {
                System.out.printf("\033[2J" + "\033[0;0f");
                add(get_Tetro_Obj(), a, j);
                draw();
                for(int u=0; u<GetLenOfRow(); u++)
                {
                    for(int y=0; y<GetLenOfClmn(); y++)
                        board[u][y] = temp.getBoard()[u][y];
                }
            Thread.sleep(50);
            }
            System.out.print("\033[2J" + "\033[0;0f");
            add(get_Tetro_Obj(), i, j);
            draw();
            
        }
    }
}
