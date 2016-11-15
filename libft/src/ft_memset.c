/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:37:26 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:37:27 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	char	*convert;

	convert = s;
	while (n--)
		*convert++ = c;
	return (s);
}
