/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:50:43 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/26 17:01:11 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		delete_tetro(int num, int side, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < side * side)
		if (ft_isalpha(g_matrix[num][i].field))
		{
			g_matrix[num][i].field = '.';
			j = num;
			while (++j < len)
				g_matrix[j][i].field = '.';
		}
}
