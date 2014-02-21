/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putclst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:12:29 by cheron            #+#    #+#             */
/*   Updated: 2014/01/11 19:03:22 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include "select.h"
#include <libft.h>
#include <unistd.h>


static t_clist	*ft_get_clst_start(t_clist *run);
static void		ft_print_clst_simple(t_clist *run, int fd);

int				tputs_putchar(int c)
{
	int				fd;

	fd = *ft_get_tty();
	write(fd, &c, 1);
	return (fd);
}

void			ft_putclst(t_clist *clst)
{
	t_clist			*run;
	int				fd;
	int				res;

	tputs(tgetstr("ho", NULL), 1, tputs_putchar);
	tputs(tgetstr("cd", NULL), 1, tputs_putchar);
	run = clst;
	fd = *ft_get_tty();
	run = ft_get_clst_start(run);
	res = ft_resize(run, fd);
	if (res == -1)
		ft_putendl_fd("Window is too small, please resize it.", fd);
	else if (res == 0)
		ft_print_clst_simple(run, fd);
}

void			ft_enable_mode(t_clist *elem)
{
	if (elem->rcolor == 1)
		tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	if (elem->uline == 1)
		tputs(tgetstr("us", NULL), 1, tputs_putchar);
}

static t_clist	*ft_get_clst_start(t_clist *run)
{
	while (run->i != 0)
		run = run->next;
	return (run);
}

static void		ft_print_clst_simple(t_clist *run, int fd)
{
	while (run->i < run->next->i)
	{
		ft_enable_mode(run);
		ft_putendl_fd(run->content, fd);
		tputs(tgetstr("me", NULL), 1, tputs_putchar);
		run = run->next;
	}
	ft_enable_mode(run);
	ft_putstr_fd(run->content, fd);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}
