#include "fillit.h"
#include "libft.h"


static void    swap_sq(t_sq *a, t_sq *b)
{
    t_sq    tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
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
		if (pos_arr[i].x < pos_arr[min].x && pos_arr[i].x > pos_arr[curr].x && \
			pos_arr[i].y != pos_arr[curr].y)
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
	if (pos_arr[curr].x > pos_arr[curr - 1].x && \
		pos_arr[curr].y != pos_arr[curr - 1].y)
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
		while (j < len)
		{
			ft_putstr(ft_itoa(pos_arr[j].x));
			ft_putchar(' ');
			ft_putstr(ft_itoa(pos_arr[j].y));
			ft_putstr(", ");
			j++;
		}
		ft_putchar('\n');
        change_comb(len);
        i--;
    }
}