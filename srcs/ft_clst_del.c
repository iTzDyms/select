/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 16:30:13 by cheron            #+#    #+#             */
/*   Updated: 2014/01/08 18:32:09 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <stdlib.h>
#include <string.h>

t_clist		*ft_clst_delone(t_clist *current)
{
	t_clist	*tmp;

	if (current->i == current->next->i)
	{
		free(current->content);
		free(current);
		return (NULL);
	}
	tmp = current->prev;
	current->prev->next = current->next;
	current = current->next;
	free(current->prev->content);
	free(current->prev);
	current->uline = 1;
	current->prev = tmp;
	return (current);
}

void	ft_clst_del(t_clist	*clst)
{
	while (clst)
		clst = ft_clst_delone(clst);
}

t_clist		*ft_clst_delindex(t_clist *current)
{
	t_clist	*tmp;

	if (current->i == current->next->i)
	{
		free(current->content);
		free(current);
		return (NULL);
	}
	tmp = current->prev;
	current->prev->next = current->next;
	current = current->next;
	free(current->prev->content);
	free(current->prev);
	current->uline = 1;
	current->prev = tmp;
	tmp = current;
	while (tmp->i != 0)
	{
		tmp->i -= 1;
		tmp = tmp->next;
	}
	return (current);
}
