#include "fillit.h"
#include "libft.h"

int				check_pos_arr(int len)
{
	int i;
	int j;

	i = -1;
	while (++i < len)
	{
		if (pos_arr[i].y != -1)
		{
			j = i;
			while (++j < len)
			{
				if (pos_arr[i].y == pos_arr[j].y && \
					pos_arr[i].x > pos_arr[j].x)
					return (0);
			}
		}
	}
	return (1);
}

int			is_sort_arr(int len)
{
	int i;
	int j;

	i = -1;
	while (++i < len - 1)
	{
		j = i + 1;
		if (pos_arr[i].x < pos_arr[j].x)
			return (0);
	}
	return (1);
}

int			is_same(int len)
{
	int i;
	int same;

	i = 0;
	if (pos_arr[i].y == -1)
		return (0);
	same = pos_arr[i].y;
	while (i++ < len)
		if (pos_arr[i].y != same)
			return (0);
	return (1);
}
