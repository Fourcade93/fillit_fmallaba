#include "fillit.h"
#include "libft.h"

t_sq           pos_arr[26];

static void    swap_sq(t_sq *a, t_sq *b)
{
    t_sq    tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void          init_pos_arr(int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        pos_arr[i].x = i;
        pos_arr[i].y = -1;
        i++;
    }
}

static int    check_tetro(t_sq a[4], t_sq b[4])
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (a[i].x != b[i].x || a[i].y != b[i].y)
            return (0);
        i++;
    }
    return (1);
}

void           set_marker(int len, t_sq arr[26][4])
{
    int i;
    int j;

    i = 0;
    while (i < len)
    {
        j = i + 1;
        if (pos_arr[i].y == -1)
            while (j < len)
            {
                if (check_tetro(arr[i], arr[j]) && pos_arr[j].y == -1)
                {
                    pos_arr[i].y = pos_arr[i].x;
                    pos_arr[j].y = pos_arr[i].x;
                }
                j++;
            }
        i++;
    }
}

static void    sort_arr(int curr, int len)
{
    int next;

    next = 0;
    while (curr < len - 1)
    {
        next = curr + 1;
        while (next < len)
        {
            if (pos_arr[curr].x > pos_arr[next].x)
                swap_sq(&pos_arr[curr], &pos_arr[next]);
            next++;
        }
        curr++;
    }
}

static void    swap_next(curr, len)
{
    int min;
    int i;

    min = curr + 1;
    i = curr + 1;
    while (i < len)
    {
        if (pos_arr[i].x < pos_arr[min].x && pos_arr[i].x > pos_arr[curr].x)
            min = i;
        i++;
    }
    swap_sq(&pos_arr[curr], &pos_arr[min]);
}

void            change_comb(int len)
{
    int next;
    int curr;

    curr = len - 1;
    if (pos_arr[curr].x > pos_arr[curr - 1].x)
    {
        swap_sq(&pos_arr[curr], &pos_arr[curr - 1]);
        return ;
    }
    while (curr > 0)
    {
        next = curr - 1;
        if (pos_arr[curr].x > pos_arr[next].x)
        {
            swap_next(next, len);
            sort_arr(curr, len);
            return ;
        }
        curr--;
    }
}

int             check_pos_arr(int len)
{
    int i;
    int j;

    i = -1;
    while (++i < len)
    {
        if (pos_arr[i].y != -1)
        {
            j = i;
            while (++j < len)
            {
                if (pos_arr[i].y == pos_arr[j].y && \
                    pos_arr[i].x > pos_arr[j].x)
                    return (0);
            }
        }
    }
    return (1);
}

int             is_sort_arr(int len)
{
    int i;
    int j;

    i = -1;
    while (++i < len - 1)
    {
        j = i + 1;
        if (pos_arr[i].x < pos_arr[j].x)
            return (0);
    }
    return (1);
}

int             pop_tetro(int num)
{
    return (pos_arr[num].x);
}

void    check_change_comb(int len, t_sq arr[26][4]) //delete_me!!!
{
    int i;
    int j;

    init_pos_arr(len);
    set_marker(len, arr);
    i = ft_iterative_factorial(len);
    while (i)
    {
        j = 0;
        if (check_pos_arr(len))
        {
            while (j < len)
            {
                ft_putstr(ft_itoa(pos_arr[j].x));
                ft_putchar(' ');
                ft_putstr(ft_itoa(pos_arr[j].y));
                ft_putstr(", ");
                j++;
            }
            ft_putchar('\n');
        }
        change_comb(len);
        i--;
    }
}