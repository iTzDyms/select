/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:56:21 by cheron            #+#    #+#             */
/*   Updated: 2013/11/29 17:07:07 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (del == NULL || alst == NULL)
		return ;
	if ((*alst)->next)
		ft_lstdel((&(*alst)->next), del);
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

