/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:41:47 by fhenry            #+#    #+#             */
/*   Updated: 2016/05/12 14:14:02 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char*)dst;
	s2 = (char*)src;
	if (s2 < s1)
	{
		s2 += len - 1;
		s1 += len - 1;
		while (len > 0)
		{
			*s1-- = *s2--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*s1++ = *s2++;
			len--;
		}
	}
	return (dst);
}
