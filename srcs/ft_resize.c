/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:34:30 by cheron            #+#    #+#             */
/*   Updated: 2014/01/11 16:12:52 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <termios.h>
#include "select.h"
#include <libft.h>

static size_t	ft_get_hlen(t_clist *run);
static int		ft_need_resize(size_t co, size_t li, t_clist *clst, int fd);
static void		ft_print_resize(t_clist *clst, int fd, int li);
static void		ft_pos_cursor(size_t i, int li, size_t hlen);

int				ft_resize(t_clist *clst, int fd)
{
	int			co;
	int			li;

	co = tgetnum("co");
	li = tgetnum("li");
	return (ft_need_resize(co, li, clst, fd));
}

static int		ft_need_resize(size_t co, size_t li, t_clist *clst, int fd)
{
	size_t		hlen;
	size_t		nb_elem;
	size_t		nb_co_sel;

	nb_elem = clst->prev->i + 1;
	hlen = ft_get_hlen(clst);
	if (nb_elem > li || co < hlen)
	{
		nb_co_sel = nb_elem / (li + 1) + 1;
		if (((hlen + 1) * nb_co_sel > co))
			return (-1);
		ft_print_resize(clst, fd, li);
		return (1);
	}
	return (0);
}

static size_t	ft_get_hlen(t_clist *run)
{
	size_t		hlen;

	hlen = 0;
	while (run->i < run->next->i)
	{
		if (hlen < run->len)
			hlen = run->len;
		run = run->next;
	}
	if (hlen < run->len)
		hlen = run->len;
	run = run->next;
	return (hlen);
}

static void		ft_print_resize(t_clist *clst, int fd, int li)
{
	size_t		hlen;

	hlen = ft_get_hlen(clst);
	while (clst->i < clst->next->i)
	{
		ft_pos_cursor(clst->i, li, hlen);
		ft_enable_mode(clst);
		ft_putstr_fd(clst->content, fd);
		tputs(tgetstr("me", NULL), 1, tputs_putchar);
		clst = clst->next;
	}
	ft_pos_cursor(clst->i, li, hlen);
	ft_enable_mode(clst);
	ft_putstr_fd(clst->content, fd);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
}

static void		ft_pos_cursor(size_t i, int li, size_t hlen)
{
	size_t		cursor_li;
	size_t		cursor_co;

	cursor_li = i % li;
	cursor_co = (hlen * ((i / li))) + (i / li);
	tputs(tgoto(tgetstr("cm", NULL), cursor_co, cursor_li), 1, tputs_putchar);
}
