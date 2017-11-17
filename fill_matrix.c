#include "fillit.h"
#include "libft.h"

t_matrix    matrix[26][200];

void    init_matrix(int side, int len)
{
    int i;
    int j;
    int col;
    int row;

    i = -1;
    while (++i < len)
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

void    put_marker(int side, int num, int i, t_sq sub[4], int len)
{
    while (++num < len)
        add_tetro(num, i, side, sub, '-');
}

int    put_tetro(int side, int num, t_sq sub[4], char c, int len)
{
    int i;

    i = -1;
    while (++i < (side * side))
    {
        if (matrix[num][i].field == '.' && check_field(num, i, side, sub))
        {
            add_tetro(num, i, side, sub, c);
            put_marker(len, num, i, sub, len);
            return (1);
        }
    }
    return (0);
}

void   delete_tetro(int num, int side)
{
    int i;

    i = -1;
    while (++i < (side * side))
        matrix[num][i].field = '.';
}

void   clean_matrix(int len, int side)
{
    int i;

    i = -1;
    while (++i < len)
        delete_tetro(i, side);
}

int    fill_field(int side, int len, t_sq arr[26][4])
{
    int i;
    int t_num;

    i = -1;
    while (++i < len)
    {
        t_num = pop_tetro(i);
        if (!(put_tetro(side, i, arr[t_num], t_num + 'A', len)))
            return (0);
    }
    return (1);
}

int    fill_matrix(int side, int len, t_sq arr[26][4])
{
    int i;
    int j;

    init_pos_arr(len);
    set_marker(len, arr);
    init_matrix(side, len);
    // check_change_comb(len, arr);
    // init_pos_arr(len);
    i = 1;
    while (i)
    {
        if (fill_field(side, len, arr))
            i = 0;
        else
        {
            change_comb(len);
            while (!(check_pos_arr(len)))
            {
                change_comb(len);
                if (is_sort_arr(len))
                    return (0);
            }
            clean_matrix(len, side);
        }
    }
    i = -1;
    while (++i < len)
    {
        j = -1;
        while (++j < (side * side))
        {
            ft_putchar(matrix[i][j].field);
            // ft_putnbr(matrix[i][j].col);
            // ft_putstr(" ");
            // ft_putnbr(matrix[i][j].row);
            // ft_putstr(", ");
        }
        ft_putchar('\n');
    }
    print_square(len, side);
    return (1);
}
