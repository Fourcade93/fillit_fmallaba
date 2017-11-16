#include "fillit.h"
#include "libft.h"

t_matrix    matrix[26][200];

void    init_square(int side)
{
    int i;
    int j;
    int col;
    int row;

    i = -1;
    while (++i < side)
    {
        j = -1;
        col = 0;
        row = 0;
        while (++j < (side * side))
        {
            if (col == side)
            {
                col = 0;
                row++;
            }
            matrix[i][j].field = '.';
            matrix[i][j].col = col;
            matrix[i][j].row = row;
            col++;
        }
    }
}

// void    put_tetro()

void    fill_square(int side, int len, t_sq arr[26][4])
{
    int i;
    int j;

    init_square(side);
    len = arr[3][1].x;
    // init_pos_arr(len);
    i = -1;
    while (++i < side)
    {
        j = -1;
        while (++j < (side * side))
        {
            ft_putnbr(matrix[i][j].col);
            ft_putstr(" ");
            ft_putnbr(matrix[i][j].row);
            ft_putstr(", ");
        }
        ft_putchar('\n');
    }
}
