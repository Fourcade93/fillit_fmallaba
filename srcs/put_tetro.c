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
#include "libft.h"

static int	check_field(int num, int i, int total, t_sq sub[4])
{
	int row_pos;
	int col_pos;
	int j;

	j = 0;
	col_pos = t_matrix[num][i].col - sub[j].x;
	row_pos = t_matrix[num][i].row - sub[j].y;
	while (i < total && j < 4)
	{
		if (t_matrix[num][i].field == '.' && \
		t_matrix[num][i].col - sub[j].x == col_pos && \
		t_matrix[num][i].row - sub[j].y == row_pos)
			j++;
		i++;
	}
	if (j == 4)
		return (total - i);
	return (-1);
}

static void	add_tetro(int num, int i, t_sq sub[4], char c)
{
	int row_pos;
	int col_pos;
	int j;

	j = 0;
	col_pos = t_matrix[num][i].col - sub[j].x;
	row_pos = t_matrix[num][i].row - sub[j].y;
	while (j < 4)
	{
		if (t_matrix[num][i].field == '.' && \
		t_matrix[num][i].col - sub[j].x == col_pos && \
		t_matrix[num][i].row - sub[j].y == row_pos)
		{
			t_matrix[num][i].field = c;
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

static t_sq	put_tetro(int side, int num, t_sq sub[4], int i)
{
	int		t_num;
	int		pos;
	int		total;
	t_sq	check;

	t_num = pop_tetro(num);
	total = side * side;
	while (++i < total)
	{
		if (t_matrix[num][i].field == '.')
			if ((pos = check_field(num, i, total, sub)) != -1)
			{
				add_tetro(num, i, sub, t_num + 'A');
				check.x = i;
				check.y = pos;
				return (check);
			}
	}
	check.x = -10;
	return (check);
}

int			fill_field_help(int side, int i, t_sq arr[26][4], int len)
{
	t_sq	pos;
	t_sq	next_pos;

	pos = put_tetro(side, i, arr[pop_tetro(i)], -1);
	if (pos.x != -10)
		put_marker(i, pos.x, arr[pop_tetro(i)], len);
	if (i + 1 < len)
		next_pos = put_tetro(side, i + 1, arr[pop_tetro(i + 1)], -1);
	else if (pos.x != -10)
		return (1);
	if (pos.x != -10 && next_pos.x == -10 && pos.y > 0)
	{
		delete_tetro(i, side, len);
		delete_tetro(i + 1, side, len);
		if ((pos = put_tetro(side, i, arr[pop_tetro(i)], pos.x)).x == -10)
			return (0);
		put_marker(i, pos.x, arr[pop_tetro(i)], len);
		return (2);
	}
	else if (pos.x != -10 && next_pos.x != -10)
	{
		delete_tetro(i + 1, side, len);
		return (2);
	}
	return (0);
}
