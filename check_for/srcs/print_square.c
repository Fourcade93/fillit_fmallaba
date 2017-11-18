/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:34:31 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/18 12:34:33 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

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
		else if (ft_isalpha(matrix[i][j].field))
			(*square)[k] = matrix[i][j].field;
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
	ft_putstr(square);
}
