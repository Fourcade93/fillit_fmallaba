#include "libft.h"
#include "fillit.h"
#include <time.h>
#include <stdio.h>

void	print_arr(int len, t_sq arr[26][4])//delete_me!!!
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putstr(ft_itoa(arr[i][j].x));
			ft_putstr(" <-col ");
			ft_putstr(ft_itoa(arr[i][j].y));
			ft_putstr(" <-row ");
		}
		ft_putchar('\n');
	}
}

int		get_side(int square)
{
	int	side;

	while (!(side = ft_sqrt(square)))
		square++;
	return (side);
}

void	call_fill_matrix(int side, int len, t_sq arr[26][4])
{
	while (1)
	{
		if (fill_matrix(side, len, arr))
			return ;
		else
			side++;
	}
}

int		main(int ac, char **av)
{
	clock_t	start = clock();
	t_sq	arr[26][4];
	int		len;

	if (ac != 2)
	{
		ft_putendl(USAGE);
		return (0);
	}
	else
		len = read_file(open(av[1], O_RDONLY), arr);
	if (len == -1)
		ft_putendl("error");
	else
		call_fill_matrix(get_side(len * 4), len, arr);
	// check_change_comb(len, arr);
	// print_arr(len, arr);
	clock_t stop = clock();
	double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("time of program work: %f", elapsed);
	return (0);
}
