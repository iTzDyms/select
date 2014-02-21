/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 16:18:18 by cheron            #+#    #+#             */
/*   Updated: 2014/01/10 17:09:26 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include <string.h>

# define ESCAPE		27
# define SPACE		32
# define UP			4283163
# define LEFT		4479771
# define RIGHT		4414235
# define DOWN		4348699
# define RETURN		10
# define DELETE		127
# define BACKSPACE	2117294875

typedef struct		s_clist
{
	size_t			i;
	int				rcolor;
	int				uline;
	char			*content;
	size_t			len;
	struct s_clist	*next;
	struct s_clist	*prev;
}					t_clist;

void				ft_sig(int signum);
struct termios		*ft_get_termios(void);
void				ft_init_terminal_data(void);
int					*ft_get_tty(void);
t_clist				*ft_clstnew(char const *content);
t_clist				*ft_clistadd(t_clist *new, t_clist *prev);
t_clist				*ft_create_clst(char **argv);
int					ft_get_input(t_clist **clst);
t_clist				*ft_proceed_input(unsigned int key, t_clist *clst);
int					ft_newterm(t_clist **clst);
void				ft_putclst(t_clist *clst);
int					tputs_putchar(int c);
t_clist				*ft_clst_delone(t_clist *current);
void				ft_clst_del(t_clist *clst);
void				ft_print_res(t_clist *clst);
t_clist				*ft_clst_delindex(t_clist *current);
int					ft_resize(t_clist *clst, int fd);
void				*ft_print_clst(t_clist *clst, int resize);
void				ft_enable_mode(t_clist *elem);

#endif /* !SELECT_H */
