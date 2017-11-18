#include "fillit.h"
#include "libft.h"

void		init_pos_arr(int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		pos_arr[i].x = i;
		pos_arr[i].y = -1;
		i++;
	}
}

static int	check_tetro(t_sq a[4], t_sq b[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (a[i].x != b[i].x || a[i].y != b[i].y)
			return (0);
		i++;
	}
	return (1);
}

void		set_marker(int len, t_sq arr[26][4])
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		if (pos_arr[i].y == -1)
			while (j < len)
			{
				if (check_tetro(arr[i], arr[j]) && pos_arr[j].y == -1)
				{
					pos_arr[i].y = pos_arr[i].x;
					pos_arr[j].y = pos_arr[i].x;
				}
				j++;
			}
		i++;
	}
}
