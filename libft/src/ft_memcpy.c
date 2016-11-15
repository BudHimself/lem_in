/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:37:15 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:10:36 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d_str;
	const char	*s_str;

	if (!dest || !src)
		return (NULL);
	d_str = (char*)dest;
	s_str = (const char *)src;
	while (n-- && s_str && d_str)
		*d_str++ = *s_str++;
	return (dest);
}
