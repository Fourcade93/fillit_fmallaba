#include "libft.h"
#include "fillit.h"
#include <time.h>
#include <stdio.h>

#define MISS "Filename missing"
#define MANY "Too many arguments"

void	print_arr(t_sq arr[26][4], int len) //delete_me!!!
{
	int i;
	int	j;

	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < 4)
		{
			ft_putstr(ft_itoa((arr[j][i]).x));
			ft_putstr("<-col ");
			ft_putstr(ft_itoa((arr[j][i]).y));
			ft_putstr("<-row, ");
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

int		get_side(int square)
{
	int	side;

	while (!(side = ft_sqrt(square)))
		square++;
	return (side);
}

void    call_fill_matrix(int side, int len, t_sq arr[26][4])
{
    init_pos_arr(len);
    set_marker(len, arr);
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

	if (ac < 2)
	{
		ft_putendl(MISS);
		return (0);
	}
	else if (ac > 2)
	{
		ft_putendl(MANY);
		return (0);
	}
	else
		len = read_file(open(av[1], O_RDONLY), arr);
	if (len == -1)
		ft_putendl("Error");
	else
        ft_putendl(ft_itoa(get_side(len * 4)));
    // check_change_comb(len, arr);
    call_fill_matrix(get_side(len * 4), len, arr);
	clock_t stop = clock();
	double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("time of program work: %f", elapsed);
	return (0);
}
