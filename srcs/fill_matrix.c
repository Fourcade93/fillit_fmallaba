/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:33:55 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/23 20:46:03 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		fill_g_matrix(int side, int len, t_sq arr[26][4], int num)
{
	int	i;
	int	total;

	if (num == len)
		return (1);
	i = 0;
	total = side * side;
	while (i < total)
	{
		if (g_matrix[num][i].field == '.')
			if (check_field(num, i, total, arr[num]))
			{
				add_tetro(num, i, arr[num], num + 'A');
				put_marker(num, i, arr[num], len);
				if (!(fill_g_matrix(side, len, arr, num + 1)))
					delete_tetro(num, side, len);
				else
					return (1);
			}
		i++;
	}
	return (0);
}
