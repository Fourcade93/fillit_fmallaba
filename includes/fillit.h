#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# define USAGE "usage: fillit file-name"

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

t_sq			pos_arr[26];
t_matrix		matrix[26][200];

void			add_tetro(int num, int i, t_sq sub[4], char c);
void			clean_matrix(int len, int side);
void			print_square(int len, int side);
void			init_matrix(int side, int len);
int				put_tetro(int total, int num, t_sq sub[4], int len, int i);
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

int				check_field(int num, int i, int total, t_sq sub[4]);
int 			fill_field(int side, int len, t_sq arr[26][4]);
void 			delete_tetro(int num, int side, int len);

#endif
