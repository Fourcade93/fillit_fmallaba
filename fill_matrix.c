/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:33:55 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/26 17:01:07 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_tetro(t_sq a[4], t_sq b[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (a[i].x != b[i].x || a[i].y != b[i].y)
			return (0);
		i++;
	}
	return (1);
}

int			fill_g_matrix(int side, int len, t_sq arr[26][4], int num)
{
	int	i;
	int	total;

	i = 0;
	total = side * side;
	while (i < side * side)
	{
		if (g_matrix[num][i].field == '.')
			if (check_field(num, i, total, arr[num]))
			{
				add_tetro(num, i, arr[num], num + 'A');
				put_marker(num, i, arr[num], len);
				if (num + 1 < len && !(fill_g_matrix(side, len, arr, num + 1)))
				{
					delete_tetro(num, side, len);
					if (check_tetro(arr[num], arr[num + 1]))
						return (0);
				}
				else
					return (1);
			}
		i++;
	}
	return (0);
}
