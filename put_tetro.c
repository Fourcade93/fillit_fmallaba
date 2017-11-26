/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:34:38 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/26 17:02:25 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_field(int num, int i, int total, t_sq sub[4])
{
	int row_pos;
	int col_pos;
	int j;

	j = 0;
	col_pos = g_matrix[num][i].col - sub[j].x;
	row_pos = g_matrix[num][i].row - sub[j].y;
	while (i < total && j < 4)
	{
		if (g_matrix[num][i].field == '.' && \
		g_matrix[num][i].col - sub[j].x == col_pos && \
		g_matrix[num][i].row - sub[j].y == row_pos)
			j++;
		i++;
	}
	if (j == 4)
		return (1);
	return (0);
}

void	add_tetro(int num, int i, t_sq sub[4], char c)
{
	int row_pos;
	int col_pos;
	int j;

	j = 0;
	col_pos = g_matrix[num][i].col - sub[j].x;
	row_pos = g_matrix[num][i].row - sub[j].y;
	while (j < 4)
	{
		if (g_matrix[num][i].field == '.' && \
		g_matrix[num][i].col - sub[j].x == col_pos && \
		g_matrix[num][i].row - sub[j].y == row_pos)
		{
			g_matrix[num][i].field = c;
			j++;
		}
		i++;
	}
}

void	put_marker(int num, int i, t_sq sub[4], int len)
{
	while (++num < len)
		add_tetro(num, i, sub, '-');
}
