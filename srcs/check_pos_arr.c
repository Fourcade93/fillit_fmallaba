/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_g_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:33:34 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/18 12:33:37 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int				check_g_arr(int len)
{
	int i;
	int j;

	i = -1;
	while (++i < len)
	{
		if (g_arr[i].y != -1)
		{
			j = i;
			while (++j < len)
			{
				if (g_arr[i].y == g_arr[j].y && \
					g_arr[i].x > g_arr[j].x)
					return (0);
			}
		}
	}
	return (1);
}

int				is_sort_arr(int len)
{
	int i;
	int j;

	i = -1;
	while (++i < len - 1)
	{
		j = i + 1;
		if (g_arr[i].x < g_arr[j].x)
			return (0);
	}
	return (1);
}

int				is_same(int len)
{
	int i;
	int same;

	i = 0;
	if (g_arr[i].y == -1)
		return (0);
	same = g_arr[i].y;
	while (i++ < len)
		if (g_arr[i].y != same)
			return (0);
	return (1);
}
