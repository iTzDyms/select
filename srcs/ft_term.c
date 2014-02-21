/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:10:58 by cheron            #+#    #+#             */
/*   Updated: 2014/01/11 19:04:15 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <termios.h>
#include "select.h"

int				ft_newterm(t_clist **clst)
{
	struct termios			*term;
	int						res;

	term = ft_get_termios();
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, 0, term);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	ft_putclst(*clst);
	res = ft_get_input(clst);
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	term->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, term);
	return (res);
}

struct termios	*ft_get_termios(void)
{
	static struct termios	term;
	return (&term);
}
