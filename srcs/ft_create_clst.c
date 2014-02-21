/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_clst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:15:31 by cheron            #+#    #+#             */
/*   Updated: 2014/01/10 15:47:32 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <string.h>

t_clist		*ft_create_clst(char **argv)
{
	static t_clist	*clist;
	t_clist			*new;
	t_clist			*prev;
	int				i;

	if (argv)
	{
		i = 1;
		new = NULL;
		while (argv[i])
		{
			prev = new;
			if (!(new = ft_clstnew(argv[i])))
				return (NULL);
			clist = ft_clistadd(new, prev);
			i++;
		}
	}
	return (clist);
}

