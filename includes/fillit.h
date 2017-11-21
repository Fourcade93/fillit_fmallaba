/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:08:07 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/20 21:08:10 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# define USAGE "usage: fillit file-name"

typedef struct	s_sq
{
	int			x;
	int			y;
}				t_sq;

typedef struct	s_matrix
{
	int			col;
	int			row;
	char		field;
}				t_matrx;

t_sq			g_arr[26];
t_matrx			g_matrix[26][200];

void			delete_tetro(int num, int side, int len);
int				fill_field_help(int	side, int i, t_sq arr[26][4], int len);
void			clean_g_matrix(int len, int side);
void			print_square(int len, int side);
void			init_g_matrix(int side, int len);
int				fill_g_matrix(int side, int len, t_sq arr[26][4]);
void			change_comb(int len);
int				check_g_arr(int len);
void			init_g_arr(int len);
int				is_sort_arr(int len);
int				is_same(int len);
void			set_marker(int len, t_sq arr[26][4]);
int				pop_tetro(int num);
int				read_file(int fd, t_sq arr[26][4]);

#endif
