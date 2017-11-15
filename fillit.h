#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

typedef struct	s_sq
{
	int			x;
	int			y;
}				t_sq;

void		check_change_comb(int len);
int			read_file(int fd, t_sq arr[26][4]);

#endif
