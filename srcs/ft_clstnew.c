/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 19:01:49 by cheron            #+#    #+#             */
/*   Updated: 2014/01/11 19:01:51 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "select.h"
#include <libft.h>

t_clist	*ft_clstnew(char const *content)
{
	t_clist	*new;
	size_t	len;

	if (!(new = (t_clist *) malloc(sizeof(t_clist))))
		return (NULL);
	if (content == NULL)
		new->content = NULL;
	else
	{
		len = ft_strlen(content);
		if (!(new->content = malloc(sizeof(content) * len)))
		{
			free(new);
			return (NULL);
		}
		new->content = ft_strcpy(new->content, content);
	}
	new->len = len;
	new->rcolor = 0;
	new->uline = 0;
	return (new);
}
