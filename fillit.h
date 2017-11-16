#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

typedef struct	s_sq
{
	int			x;
	int			y;
}				t_sq;

typedef struct  s_matrix
{
    int         col;
    int         row;
    char        field;
}               t_matrix;

void		fill_matrix(int side, int len, t_sq arr[26][4]);
void		check_change_comb(int len, t_sq arr[26][4]);
int			read_file(int fd, t_sq arr[26][4]);

#endif
