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

int		check_field(int num, int i, int total, t_sq sub[4])
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
		return (total - i);
	return (-1);
}

void	add_tetro(int num, int i, t_sq sub[4], char c)
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

int			put_tetro(int total, int num, t_sq sub[4], int len, int i)
{
	int	t_num;
	int	pos;

	t_num = pop_tetro(num);
	while (++i < total)
	{
		if (matrix[num][i].field == '.')
			if ((pos = check_field(num, i, total, sub)) != -1)
			{
				add_tetro(num, i, sub, t_num + 'A');
				put_marker(num, i, sub, len);
				return (i * 10 + pos);
			}
	}
	return (-10);
}

int 		fill_field(int side, int len, t_sq arr[26][4])
{
	int i;
	int t_num;
	int total;
	int	next;
	int pos;
	int	next_pos;

	i = 0;
	total = side * side;
	while (i < len)
	{
		t_num = pop_tetro(i);
		next = i + 1;
		pos = put_tetro(total, i, arr[t_num], len, -1);
		if (next < len)
			next_pos = put_tetro(total, next, arr[pop_tetro(next)], len, -1);
		else if (pos != -10)
			return (1);
		if (pos != -10 && next_pos == -10 && pos % 10 > 0)
		{
			delete_tetro(i, side, len);
			delete_tetro(next, side, len);
			if (put_tetro(total, i, arr[t_num], len, pos / 10) == -10)
				return (0);
			i++;
		}
		else if (pos != -10 && next_pos != -10)
		{
			delete_tetro(next, side, len);
			i++;
		}
		else
			return (0);
			
	}
	return (1);
}
