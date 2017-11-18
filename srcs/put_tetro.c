/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:34:38 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/18 12:34:41 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_field(int num, int i, int total, t_sq sub[4])
{
	int row_pos;
	int col_pos;
	int j;

	j = 0;
	col_pos = matrix[num][i].col - sub[j].x;
	row_pos = matrix[num][i].row - sub[j].y;
	while (i < total && j < 4)
	{
		if (matrix[num][i].field == '.' && \
		matrix[num][i].col - sub[j].x == col_pos && \
		matrix[num][i].row - sub[j].y == row_pos)
			j++;
		i++;
	}
	if (j == 4)
		return (1);
	return (0);
}

static void	add_tetro(int num, int i, t_sq sub[4], char c)
{
	int row_pos;
	int col_pos;
	int j;

	j = 0;
	col_pos = matrix[num][i].col - sub[j].x;
	row_pos = matrix[num][i].row - sub[j].y;
	while (j < 4)
	{
		if (matrix[num][i].field == '.' && \
		matrix[num][i].col - sub[j].x == col_pos && \
		matrix[num][i].row - sub[j].y == row_pos)
		{
			matrix[num][i].field = c;
			j++;
		}
		i++;
	}
}

static void	put_marker(int num, int i, t_sq sub[4], int len)
{
	while (++num < len)
		add_tetro(num, i, sub, '-');
}

int			put_tetro(int total, int num, t_sq sub[4], int len)
{
	int i;
	int	t_num;

	i = -1;
	t_num = pop_tetro(num);
	while (++i < total)
	{
		if (matrix[num][i].field == '.' && check_field(num, i, total, sub))
		{
			add_tetro(num, i, sub, t_num + 'A');
			put_marker(num, i, sub, len);
			return (1);
		}
	}
	return (0);
}
