/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:38:40 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:38:41 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strnlen(src, n);
	ft_memcpy(dest, src, len);
	ft_memset(dest + len, 0, n - len + 1);
	return (dest);
}
