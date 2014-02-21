/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:56:37 by cheron            #+#    #+#             */
/*   Updated: 2014/01/07 14:03:06 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_clist	*ft_clistadd(t_clist *new, t_clist *prev)
{
	if (prev)
	{
		new->prev = prev;
		new->i = prev->i + 1;
		new->next = prev->next;
		prev->next = new;
		new->next->prev = new;
	}
	else
	{
		new->prev = new;
		new->i = 0;
		new->next = new;
		new->uline = 1;
	}
	return (new->next);
}
