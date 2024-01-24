package ben;
/**
 * Tetromino class
 */
public class Tetromino {
    
    private char type;
    private char[][] shape_of_tetris;

    /**
     * Constructor Of tetromino, It fill with *
     * @author onuratasever
     */
    public Tetromino()
    {
        int i,j;
        shape_of_tetris = new char[4][4];
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                shape_of_tetris[i][j] = '*';
            }
        }
    }

    /**
     * Block type parameter constructor
     * @param shape It takes shape of tetromino
     * @author onuratasever
     */
    public Tetromino(block_type shape)
    {
        int j;
        shape_of_tetris = new char[4][4];
        if(shape == block_type.L)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', 'L', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>0 && j == 0)
                        shape_of_tetris[i][j] = 'L';
                    else if(i==3 && j == 1)
                        shape_of_tetris[i][j] = 'L';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'L';
        }
        if(shape == block_type.O)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'O', 'O', '*', '*'}, {'O', 'O', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>1 && j == 0)
                        shape_of_tetris[i][j] = 'O';
                    else if(i>1 && j == 1)
                        shape_of_tetris[i][j] = 'O';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'O';
        }
        if(shape == block_type.T)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*','*'}, {'T', 'T', 'T', '*'}, {'*', 'T', '*','*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && j != 3)
                        shape_of_tetris[i][j] = 'T';
                    else if(i==3 && j == 1)
                        shape_of_tetris[i][j] = 'T';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'T';
        }
        if(shape == block_type.J)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', 'J'}, {'*','*', '*', 'J'}, {'*','*', 'J', 'J'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>0 && j == 3)
                        shape_of_tetris[i][j] = 'J';
                    else if(i==3 && j == 2)
                        shape_of_tetris[i][j] = 'J';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'J';
        }
        if(shape == block_type.S)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*','S', 'S', '*'}, {'S', 'S', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && (j == 1 || j == 2))
                        shape_of_tetris[i][j] = 'S';
                    else if(i==3 && (j == 0 || j == 1))
                        shape_of_tetris[i][j] = 'S';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'S';
        }
        if(shape == block_type.Z)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'Z', 'Z', '*', '*'}, {'*','Z', 'Z', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && (j == 0 || j == 1))
                        shape_of_tetris[i][j] = 'Z';
                    else if(i==3 && (j == 1 || j== 2))
                        shape_of_tetris[i][j] = 'Z';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'Z';
        }
        if(shape == block_type.I)
        {
            //shape_of_tetris = {{'I', 'I', 'I', 'I'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i == 0)
                        shape_of_tetris[i][j] = 'I';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'I';
        }
    }

    /**
     * It sets empty Tetromino according to shape
     * @param shape It takes shape of tetromino
     * @author onuratasever
     */
    public void setter(block_type shape)
    {
        int j;
        if(shape == block_type.L)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', '*', '*', '*'}, {'L', 'L', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>0 && j == 0)
                        shape_of_tetris[i][j] = 'L';
                    else if(i==3 && j == 1)
                        shape_of_tetris[i][j] = 'L';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'L';
        }
        if(shape == block_type.O)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'O', 'O', '*', '*'}, {'O', 'O', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>1 && j == 0)
                        shape_of_tetris[i][j] = 'O';
                    else if(i>1 && j == 1)
                        shape_of_tetris[i][j] = 'O';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'O';
        }
        if(shape == block_type.T)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*','*'}, {'T', 'T', 'T', '*'}, {'*', 'T', '*','*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && j != 3)
                        shape_of_tetris[i][j] = 'T';
                    else if(i==3 && j == 1)
                        shape_of_tetris[i][j] = 'T';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'T';
        }
        if(shape == block_type.J)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', 'J'}, {'*','*', '*', 'J'}, {'*','*', 'J', 'J'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i>0 && j == 3)
                        shape_of_tetris[i][j] = 'J';
                    else if(i==3 && j == 2)
                        shape_of_tetris[i][j] = 'J';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'J';
        }
        if(shape == block_type.S)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*','S', 'S', '*'}, {'S', 'S', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && (j == 1 || j == 2))
                        shape_of_tetris[i][j] = 'S';
                    else if(i==3 && (j == 0 || j == 1))
                        shape_of_tetris[i][j] = 'S';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'S';
        }
        if(shape == block_type.Z)
        {
            //shape_of_tetris = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'Z', 'Z', '*', '*'}, {'*','Z', 'Z', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i==2 && (j == 0 || j == 1))
                        shape_of_tetris[i][j] = 'Z';
                    else if(i==3 && (j == 1 || j== 2))
                        shape_of_tetris[i][j] = 'Z';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'Z';
        }
        if(shape == block_type.I)
        {
            //shape_of_tetris = {{'I', 'I', 'I', 'I'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}};
            for(int i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(i == 0)
                        shape_of_tetris[i][j] = 'I';
                    else
                        shape_of_tetris[i][j] = '*';
                }
            }
            type = 'I';
        }
    }

    /**
     * It rotates Tetromino according to direction
     * @param direction Direction to rotate
     * @author onuratasever
     */
    public void rotate(char direction)
    {
        int i, j, a=1, count=0, k;
        char[][] temp_shape = new char[4][4];

        if(direction == 'r' || direction == 'R')
        {
            for(i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                    temp_shape[i][j] = shape_of_tetris[j][i];
            }
            for(i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                    shape_of_tetris[i][j] = temp_shape[i][j] ;
            }
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
            for(i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                    shape_of_tetris[i][j] = temp_shape[i][j];
            }
        }

        if(direction == 'l' || direction == 'L')
        {
            for(k=0; k<3; k++)
            {
                for(i=0; i<4; i++)
                {
                    for(j=0; j<4; j++)
                        temp_shape[i][j] = shape_of_tetris[j][i];
                }
                for(i=0; i<4; i++)
                {
                    for(j=0; j<4; j++)
                        shape_of_tetris[i][j] = temp_shape[i][j] ;
                }
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
                for(i=0; i<4; i++)
                {
                    for(j=0; j<4; j++)
                        shape_of_tetris[i][j] = temp_shape[i][j];
                } 
            }
        }
    }

    /**
     * It prints Tetromino
     * @author onuratasever
     */
    public void print()
    {
        int i,j;
        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                System.out.printf("%c", shape_of_tetris[i][j]);
            }
            System.out.printf("\n");
        }
    }

    /**
     * It get shape of Tetromino
     * @return It returns Tetromino array
     */
    public char[][] getShapeOfTetris()
    {
        return (shape_of_tetris);
    }
}
