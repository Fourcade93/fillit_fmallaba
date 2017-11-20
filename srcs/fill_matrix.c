/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:33:55 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/18 12:33:58 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		fill_field(int side, int len, t_sq arr[26][4])
{
	int i;
	int ret;

	i = 0;
	while (i < len)
	{
		ret = fill_field_help(side, i, arr, len);
		if (ret == 1)
			return (1);
		else if (!ret)
			return (0);
		else
			i++;
	}
	return (1);
}

int		fill_t_matrix(int side, int len, t_sq arr[26][4])
{
	init_t_arr(len);
	set_marker(len, arr);
	init_t_matrix(side, len);
	while (1)
	{
		if (fill_field(side, len, arr))
			break ;
		else
		{
			if (is_sort_arr(len) || is_same(len))
				return (0);
			change_comb(len);
			while (!(check_t_arr(len)))
			{
				if (is_sort_arr(len))
					return (0);
				change_comb(len);
			}
			clean_t_matrix(len, side);
		}
	}
	print_square(len, side);
	return (1);
}
