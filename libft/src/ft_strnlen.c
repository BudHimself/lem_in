/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:38:51 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:38:52 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t		ft_strnlen(const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	i = -1;
	len = 0;
	while (++i < n && src[i])
		len++;
	return (len);
}
