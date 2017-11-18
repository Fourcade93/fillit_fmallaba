#include "fillit.h"
#include "libft.h"

static int	check_field(int i, int total, t_sq sub[4])
{
	int row_pos;
	int col_pos;
	int j;

	j = 0;
	col_pos = matrix[i].col - sub[j].x;
	row_pos = matrix[i].row - sub[j].y;
	while (i < total && j < 4)
	{
		if (matrix[i].field == '.' && \
		matrix[i].col - sub[j].x == col_pos && \
		matrix[i].row - sub[j].y == row_pos)
			j++;
		i++;
	}
	if (j == 4 && i < total)
		return (1);
	else if (j == 4 && i == total)
		return (2);
	return (0);
}

static void	add_tetro(int i, t_sq sub[4], char c)
{
	int row_pos;
	int col_pos;
	int j;

	j = 0;
	col_pos = matrix[i].col - sub[j].x;
	row_pos = matrix[i].row - sub[j].y;
	while (j < 4)
	{
		if (matrix[i].field == '.' && \
		matrix[i].col - sub[j].x == col_pos && \
		matrix[i].row - sub[j].y == row_pos)
		{
			matrix[i].field = c;
			j++;
		}
		i++;
	}
}

int			put_tetro(int num, int total, t_sq sub[4])
{
	int i;
	int	t_num;

	i = -1;
	t_num = pop_tetro(num);
	while (++i < total)
	{
		if (matrix[i].field == '.')
		{
			if (check_field(i, total, sub))
			{
				add_tetro(i, sub, t_num + 'A');
				return (1);
			}
		}
	}
	return (0);
}
