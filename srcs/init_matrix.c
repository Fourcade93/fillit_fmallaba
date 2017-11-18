#include "fillit.h"

void		init_matrix(int side)
{
	int i;
	int col;
	int row;

	col = 0;
	row = 0;
	i = -1;
	while (++i < (side * side))
	{
		if (col == side)
		{
			col = 0;
			row++;
		}
		matrix[i].field = '.';
		matrix[i].col = col;
		matrix[i].row = row;
		col++;
	}
}
