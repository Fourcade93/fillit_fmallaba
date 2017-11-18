/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 21:47:22 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/03 22:44:21 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*head;

	if (alst != NULL && new != NULL)
	{
		head = (*alst);
		new->next = head;
		(*alst) = new;
	}
}
