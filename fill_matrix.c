#include "fillit.h"
#include "libft.h"

t_matrix    matrix[26][200];

void    init_matrix(int side)
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

int     check_field(int num, int i, int side, t_sq sub[4])
{
    int row_pos;
    int col_pos;
    int j;

    j = 0;
    col_pos = matrix[num][i].col - sub[j].x;
    row_pos = matrix[num][i].row - sub[j].y;
    while (i < (side * side) && j < 4)
    {
        if (matrix[num][i].field == '.' && \
        matrix[num][i].col - sub[j].x == col_pos && \
        matrix[num][i].row - sub[j].y == row_pos)
            j++;
        i++;
    }
    if (j == 4)
        return (1);
    return (0);
}

void    add_tetro(int num, int i, int side, t_sq sub[4], char c)
{
    int row_pos;
    int col_pos;
    int j;

    j = 0;
    col_pos = matrix[num][i].col - sub[j].x;
    row_pos = matrix[num][i].row - sub[j].y;
    while (i < (side * side) && j < 4)
    {
        if (matrix[num][i].field == '.' && \
        matrix[num][i].col - sub[j].x == col_pos && \
        matrix[num][i].row - sub[j].y == row_pos)
        {
            matrix[num][i].field = c;
            j++;
        }
        i++;
    }
}

void    put_tetro(int side, int num, t_sq sub[4])
{
    int i;

    i = -1;
    while (++i < (side * side))
    {
        if (matrix[num][i].field == '.' && check_field(num, i, side, sub))
            add_tetro(num, i, side, sub, num + 'A');
    }
}

void    fill_matrix(int side, int len, t_sq arr[26][4])
{
    int i;
    int j;

    init_matrix(side);
    // check_change_comb(len, arr);
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
