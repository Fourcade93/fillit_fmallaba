#include "fillit.h"
#include "libft.h"

void		print_square(int side)
{
	int		i;
	int		col;

	i = 0;
	col = 0;
	while (i < side * side)
	{
		if (col == side)
		{
			ft_putchar('\n');
			col = 0;
		}
		else
		{
			ft_putchar(matrix[i].field);
			i++;
			col++;
		}
	}
	ft_putchar('\n');
}
