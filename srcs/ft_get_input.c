/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:56:15 by cheron            #+#    #+#             */
/*   Updated: 2014/01/10 16:02:50 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include <libft.h>
#include "select.h"
#include <unistd.h>

static int		ft_isend(unsigned int key);

int				ft_get_input(t_clist **clst)
{
	char	read_char[5];
	int		ret;

	ret = 0;
	while (ret == 0)
	{
		ft_bzero(read_char, 4);
		read(0, read_char, 4);
		*clst = ft_proceed_input(*(unsigned int *)read_char, *clst);
		ret = ft_isend(*(unsigned int *)read_char);
		if (*clst)
			ft_putclst(*clst);
		else
		{
			tputs(tgetstr("ho", NULL), 1, tputs_putchar);
			tputs(tgetstr("cd", NULL), 1, tputs_putchar);
			ret = -1;
		}
	}
	return (ret);
}

static int		ft_isend(unsigned int key)
{
	if (key == ESCAPE)
		return (-1);
	else if (key == RETURN)
		return (1);
	else
		return (0);
}

