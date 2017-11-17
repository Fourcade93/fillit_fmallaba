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

int		        fill_matrix(int side, int len, t_sq arr[26][4]);
void		    check_change_comb(int len, t_sq arr[26][4]);
void            change_comb(int len);
int             check_pos_arr(int len);
void            init_pos_arr(int len);
int             is_sort_arr(int len);
int             is_same(int len);
void            set_marker(int len, t_sq arr[26][4]);
int             pop_tetro(int num);
int			    read_file(int fd, t_sq arr[26][4]);

#endif
