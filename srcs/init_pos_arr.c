/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_g_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:34:15 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/18 12:34:17 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void		init_g_arr(int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		g_arr[i].x = i;
		g_arr[i].y = -1;
		i++;
	}
}

static int	check_tetro(t_sq a[4], t_sq b[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (a[i].x != b[i].x || a[i].y != b[i].y)
			return (0);
		i++;
	}
	return (1);
}

void		set_marker(int len, t_sq arr[26][4])
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		if (g_arr[i].y == -1)
			while (j < len)
			{
				if (check_tetro(arr[i], arr[j]) && g_arr[j].y == -1)
				{
					g_arr[i].y = g_arr[i].x;
					g_arr[j].y = g_arr[i].x;
				}
				j++;
			}
		i++;
	}
}
