#include "fillit.h"
#include "libft.h"

int     *pos_arr;

void    init_pos_arr(int len)
{
    int i;

    pos_arr = (int*)malloc(sizeof(int) * len);
    i = 0;
    if (pos_arr)
        while (i < len)
        {
            pos_arr[i] = i;
            i++;
        }
}

void    sort_arr(int curr, int len)
{
    int next;

    next = 0;
    while (curr < len - 1)
    {
        next = curr + 1;
        while (next < len)
        {
            if (pos_arr[curr] > pos_arr[next])
                ft_swap(&pos_arr[curr], &pos_arr[next]);
            next++;
        }
        curr++;
    }
}

void    swap_next(curr, len)
{
    int min;
    int i;

    min = curr + 1;
    i = curr + 1;
    while (i < len)
    {
        if (pos_arr[i] < pos_arr[min] && pos_arr[i] > pos_arr[curr])
            min = i;
        i++;
    }
    ft_swap(&pos_arr[curr], &pos_arr[min]);
}

void    change_comb(int len)
{
    int next;
    int curr;

    curr = len - 1;
    if (pos_arr[curr] > pos_arr[curr - 1])
    {
        ft_swap(&pos_arr[curr], &pos_arr[curr - 1]);
        return ;
    }
    while (curr > 0)
    {
        next = curr - 1;
        if (pos_arr[curr] > pos_arr[next])
        {
            swap_next(next, len);
            sort_arr(curr, len);
            return ;
        }
        curr--;
    }
}

void    check_change_comb(int len)
{
    int i;
    int j;

    init_pos_arr(len);
    i = ft_iterative_factorial(len);
    while (i)
    {
        j = 0;
        while (j < len)
        {
            ft_putstr(ft_itoa(pos_arr[j]));
            ft_putstr(", ");
            j++;
        }
        ft_putchar('\n');
        change_comb(len);
        i--;
    }
}