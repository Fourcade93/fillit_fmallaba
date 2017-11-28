/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:34:31 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/28 15:22:11 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	get_tetro(int side, char (*square)[], int i)
{
	int	j;
	int	stop;
	int	k;

	j = 0;
	stop = 0;
	k = 0;
	while (j < side * side)
	{
		if (stop == side)
		{
			(*square)[k] = '\n';
			j--;
			stop = -1;
		}
		else if (ft_isalpha(g_matrix[i][j].field))
			(*square)[k] = g_matrix[i][j].field;
		k++;
		j++;
		stop++;
	}
	return (k);
}

void		print_square(int len, int side)
{
	char	square[side * side + side + 1];
	int		i;
	int		k;

	i = -1;
	ft_memset(square, 46, side * side + side);
	while (++i < len)
	{
		k = get_tetro(side, &square, i);
	}
	square[k] = '\n';
	square[k + 1] = '\0';
	write(1, &square, (side * side + side));
}
