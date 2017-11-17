#include "libft.h"
#include "fillit.h"
#include <time.h>
#include <stdio.h>

#define USAGE "usage: fillit file-name"

int		get_side(int square)
{
	int	side;

	while (!(side = ft_sqrt(square)))
		square++;
	return (side);
}

void    call_fill_matrix(int side, int len, t_sq arr[26][4])
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
		ft_putendl("Error: incorrect file");
	else
        call_fill_matrix(get_side(len * 4), len, arr);
	clock_t stop = clock();
	double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("time of program work: %f", elapsed);
	return (0);
}
