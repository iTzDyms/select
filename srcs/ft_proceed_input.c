/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proceed_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:56:31 by cheron            #+#    #+#             */
/*   Updated: 2014/01/08 18:32:11 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static t_clist		*ft_move(unsigned int key, t_clist *clst);
static t_clist		*ft_select(t_clist *current);

t_clist				*ft_proceed_input(unsigned int key, t_clist *clst)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		return (ft_move(key, clst));
	else if (key == SPACE)
		return (ft_select(clst));
	else if (key == DELETE || key == BACKSPACE)
		return (ft_clst_delindex(clst));
	return (clst);
}

static t_clist		*ft_move(unsigned int key, t_clist *current)
{
	if (key == UP || key == LEFT)
	{
		current->uline = 0;
		current->prev->uline = 1;
		current = current->prev;
	}
	if (key == DOWN || key == RIGHT)
	{
		current->uline = 0;
		current->next->uline = 1;
		current = current->next;
	}
	return (current);
}

static t_clist		*ft_select(t_clist *current)
{
	current->rcolor = (current->rcolor == 1? 0 : 1);
	return (ft_move(DOWN, current));
}
