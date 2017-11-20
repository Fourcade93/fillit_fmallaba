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

int			fill_matrix(int side, int len, t_sq arr[26][4])
{
	int i;

	init_pos_arr(len);
	set_marker(len, arr);
	init_matrix(side, len);
	i = 1;
	while (i)
	{
		if (fill_field(side, len, arr))
			i = 0;
		else
		{
			change_comb(len);
			if (is_sort_arr(len))
				return (0);
			while (!(check_pos_arr(len)))
			{
				if (is_sort_arr(len) || is_same(len))
					return (0);
				change_comb(len);
			}
			clean_matrix(len, side);
		}
	}
	print_square(len, side);
	return (1);
}
