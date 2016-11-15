/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:15:06 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:09:39 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	while (*alst)
	{
		tmp = *alst;
		del((*alst)->content, (*alst)->content_size);
		(*alst) = (*alst)->next;
		free(tmp);
	}
	(*alst) = NULL;
}
