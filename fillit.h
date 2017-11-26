/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:08:07 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/26 17:38:57 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# define USAGE "usage: fillit file-name\n"

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

t_matrx			g_matrix[26][200];

void			delete_tetro(int num, int side, int len);
void			clean_g_matrix(int len, int side);
void			print_square(int len, int side);
void			init_g_matrix(int side, int len);
int				fill_g_matrix(int side, int len, t_sq arr[26][4], int num);
int				read_file(int fd, t_sq arr[26][4]);
void			delete_tetro(int num, int side, int len);
void			add_tetro(int num, int i, t_sq sub[4], char c);
void			put_marker(int num, int i, t_sq sub[4], int len);
int				check_field(int num, int i, int total, t_sq sub[4]);
int 			ft_isalpha(char c);
void 			*ft_memset(void *ptr, int val, size_t len);

#endif
