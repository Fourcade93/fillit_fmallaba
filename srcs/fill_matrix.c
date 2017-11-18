#include "fillit.h"
#include "libft.h"

void print_matrix(int side) //delete_me!!!
{
	int i;

	i = -1;
	while (++i < side * side)
		// ft_putnbr(matrix[i].row);
		ft_putchar(matrix[i].field);
	ft_putchar('\n');
}

static int	fill_field(int side, int len, t_sq arr[26][4])
{
	int i;
	int t_num;
	int	total;

	i = -1;
	total = side * side;
	while (++i < len)
	{
		t_num = pop_tetro(i);
		if (!(put_tetro(i, total, arr[t_num])))
			return (0);
	}
	return (1);
}

int			fill_matrix(int side, int len, t_sq arr[26][4])
{
	int i;
	// int j;
	int change;//delete_me!!!
	int clean;//delete_me!!!

	init_pos_arr(len);
	set_marker(len, arr);
	init_matrix(side);
	// ft_putendl(ft_itoa(side));
	// print_matrix(side);
	i = 1;
	change = 0;//delete_me!!!
	clean = 0;//delete_me!!!
	while (i)
	{
		if (fill_field(side, len, arr))
		{
			i = 0;
			ft_putendl(ft_itoa(change));
			ft_putendl(ft_itoa(clean));
		}
		else
		{
			// print_matrix(len, side);
			if (is_sort_arr(len))
				return (0);
			change_comb(len);
			while (!(check_pos_arr(len)))
			{
				change++;//delete_me!!!
				if (is_sort_arr(len) || is_same(len))
				{
					// ft_putendl(ft_itoa(change));//delete_me!!!
					// ft_putendl(ft_itoa(clean));//delete_me!!!
					return (0);
				}
				change_comb(len);
			}
			clean_matrix(side);
			clean++;//delete_me!!!
		}
	}
	// i = -1;
	// while (++i < len)//delete_me!!!
	// {
	// 	j = -1;
	// 	while (++j < (side * side))
	// 	{
	// 		ft_putchar(matrix[j].field);
	// 		// ft_putnbr(matrix[i][j].col);
	// 		// ft_putstr(" ");
	// 		// ft_putnbr(matrix[i][j].row);
	// 		// ft_putstr(", ");
	// 	}
	// 	ft_putchar('\n');
	// }
	print_matrix(side);
	print_square(side);
	return (1);
}
