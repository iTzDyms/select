/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 15:27:51 by cheron            #+#    #+#             */
/*   Updated: 2014/01/06 16:09:07 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "select.h"

t_clist	*ft_clstnew(char const *content, t_clist *prev)
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
		new->content = ft_memcpy(new->content, content, len);
	}
	new->rcolor = 0;
	new->uline = 0;
	return (new);
}
