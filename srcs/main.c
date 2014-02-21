/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:18:00 by cheron            #+#    #+#             */
/*   Updated: 2014/01/11 19:04:31 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include <libft.h>
#include <stdlib.h>
#include <term.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	t_clist			*clst;
	int				res;

	ft_init_terminal_data();
	if (argc > 1)
	{
		if (!(clst = ft_create_clst(argv)))
			return (1);
		signal(SIGWINCH, &ft_sig);
		signal(SIGTSTP, &ft_sig);
		signal(SIGCONT, &ft_sig);
		signal(SIGINT, &ft_sig);
		signal(SIGTERM, &ft_sig);
		res = ft_newterm(&clst);
		if (res == 1)
			ft_print_res(clst);
	}
	if (clst)
		ft_clst_del(clst);
	return (0);
}

void	ft_init_terminal_data(void)
{
	char			*termtype;
	int				success;
	char			buffer[2048];

	termtype = getenv("TERM");
	if (termtype == 0)
		ft_fatal("ft_select: Please specify a terminal type\n");
	success = tgetent(buffer, termtype);
	if (success < 0)
		ft_fatal("Could not access the termcap data base.\n");
	if (success == 0)
	{
		ft_putstr("Terminal type '");
		ft_putstr(termtype);
		ft_fatal("'is not defined.\n");
	}
}

int		*ft_get_tty(void)
{
	static int		fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_WRONLY);
	return (&fd);
}
