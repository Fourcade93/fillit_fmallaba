/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:34:06 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/18 12:34:08 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		init_g_matrix(int side, int len)
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
			g_matrix[i][j].field = '.';
			g_matrix[i][j].col = col;
			g_matrix[i][j].row = row;
			col++;
		}
	}
}
