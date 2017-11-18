/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:33:44 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/18 12:33:48 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	delete_tetro(int num, int side)
{
	int i;

	i = -1;
	while (++i < (side * side))
		matrix[num][i].field = '.';
}

void		clean_matrix(int len, int side)
{
	int i;

	i = -1;
	while (++i < len)
		delete_tetro(i, side);
}
