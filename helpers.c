/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:05:16 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/26 17:41:42 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_isalpha(char c)
{
	if (c > 64 && c < 91)
		return (1);
	return (0);
}

void	*ft_memset(void *ptr, int val, size_t len)
{
	unsigned char *c;

	c = ptr;
	while (len--)
	{
		*c = (unsigned char)val;
		c++;
	}
	return (ptr);
}
