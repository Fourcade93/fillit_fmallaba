/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:34:23 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/23 20:46:35 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		get_side(int square)
{
	int	side;

	while (!(side = ft_sqrt(square)))
		square++;
	return (side);
}

void	call_fill_g_matrix(int side, int len, t_sq arr[26][4])
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

int		main(int ac, char **av)
{
	t_sq	arr[26][4];
	int		len;

	if (ac != 2)
	{
		ft_putendl(USAGE);
		return (0);
	}
	else
		len = read_file(open(av[1], O_RDONLY), arr);
	if (!len)
		ft_putendl("error");
	else
		call_fill_g_matrix(get_side(len * 4), len, arr);
}
