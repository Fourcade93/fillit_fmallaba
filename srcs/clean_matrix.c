#include "fillit.h"

void		clean_matrix(int side)
{
	int i;

	i = -1;
	while (++i < side * side)
		matrix[i].field = '.';
}
