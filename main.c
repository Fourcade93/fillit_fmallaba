/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:34:23 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/28 15:21:31 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (nb);
	while (i * i <= nb && i * i > 0)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

static int	get_side(int square)
{
	int	side;

	while (!(side = ft_sqrt(square)))
		square++;
	return (side);
}

static void	call_fill_g_matrix(int side, int len, t_sq arr[26][4])
{
	while (1)
	{
		init_g_matrix(side, len);
		if (fill_g_matrix(side, len, arr, 0))
		{
			print_square(len, side);
			return ;
		}
		else
			side++;
	}
}

int			main(int ac, char **av)
{
	t_sq	arr[26][4];
	int		len;
	int		fd;

	len = 0;
	if (ac != 2)
	{
		write(1, USAGE, 24);
		return (0);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 0)
			len = read_file(fd, arr);
	}
	if (!len)
		write(1, "error\n", 6);
	else
		call_fill_g_matrix(get_side(len * 4), len, arr);
}
