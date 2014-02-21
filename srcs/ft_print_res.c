/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:33:28 by cheron            #+#    #+#             */
/*   Updated: 2014/01/14 14:06:56 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <libft.h>
#include <unistd.h>

void			ft_print_res(t_clist *clst)
{
	t_clist			*run;

	run = clst;
	while (run->i < run->next->i)
		run = run->next;
	run = run->next;
	while (run->i < run->next->i)
	{
		if (run->rcolor == 1)
		{
			ft_putstr_fd((char const *)run->content, 1);
			ft_putstr_fd((char const *)" ", 1);
		}
		run = run->next;
	}
	if (run->rcolor == 1)
		ft_putstr_fd((char const *)run->content, 1);
}

