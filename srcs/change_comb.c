/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_comb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:33:21 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/18 12:33:28 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            if (t_arr[curr].x > t_arr[next].x)
                swap_sq(&t_arr[curr], &t_arr[next]);
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
        if (t_arr[i].x < t_arr[min].x && t_arr[i].x > t_arr[curr].x)
            min = i;
        i++;
    }
    swap_sq(&t_arr[curr], &t_arr[min]);
}

void            change_comb(int len)
{
    int next;
    int curr;

    curr = len - 1;
    if (t_arr[curr].x > t_arr[curr - 1].x)
    {
        swap_sq(&t_arr[curr], &t_arr[curr - 1]);
        return ;
    }
    while (curr > 0)
    {
        next = curr - 1;
        if (t_arr[curr].x > t_arr[next].x)
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
    return (t_arr[num].x);
}
