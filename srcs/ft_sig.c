/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 18:28:47 by cheron            #+#    #+#             */
/*   Updated: 2014/02/21 17:31:02 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <termios.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include "select.h"

static void	ft_handle_sigtstp(void);
static void	ft_handle_sigcont(void);
static void	ft_do_settings(void);
static void	ft_undo_settings(void);

void		ft_sig(int signumb)
{
	t_clist			*clst;

	if (signumb == SIGWINCH)
	{
		ft_init_terminal_data();
		clst = ft_create_clst(NULL);
		ft_putclst(clst);
	}
	if (signumb == SIGTSTP)
	{
		if (isatty(1))
			ft_handle_sigtstp();
	}
	if (signumb == SIGCONT)
		ft_handle_sigcont();
	if (signumb == SIGINT || signumb == SIGTERM)
	{
		ft_undo_settings();
		clst = ft_create_clst(NULL);
		ft_clst_del(clst);
		exit(0);
	}
}

static void	ft_handle_sigtstp(void)
{
	char			cp[2];
	struct termios	*term;

	term = ft_get_termios();
	cp[0] = term->c_cc[VSUSP];
	cp[1] = 0;
	ioctl(0, TIOCSTI, cp);
	ft_undo_settings();
	signal(SIGTSTP, SIG_DFL);
	signal(SIGCONT, ft_sig);
}

static void	ft_handle_sigcont(void)
{
	ft_do_settings();
	signal(SIGTSTP, ft_sig);
}

static void	ft_undo_settings(void)
{
	struct termios	*term;

	term = ft_get_termios();
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
}

static void	ft_do_settings(void)
{
	struct termios	*term;
	t_clist			*clst;

	term = ft_get_termios();
	term->c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, 0, term);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	ft_init_terminal_data();
	clst = ft_create_clst(NULL);
	ft_putclst(clst);
}
