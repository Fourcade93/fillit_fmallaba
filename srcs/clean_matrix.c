/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:50:43 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/20 16:50:45 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void		delete_tetro(int num, int side, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < side * side)
		if (ft_isalpha(matrix[num][i].field))
		{
			matrix[num][i].field = '.';
			j = num;
			while (++j < len)
				matrix[j][i].field = '.';
		}
}

static void	clean_matrix_help(int num, int side)
{
	int i;

	i = -1;
	while (++i < (side * side))
		matrix[num][i].field = '.';
}

void		clean_matrix(int len, int side)
{
	int i;

	i = -1;
	while (++i < len)
		clean_matrix_help(i, side);
}
