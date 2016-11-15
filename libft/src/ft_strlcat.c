/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:36:10 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 18:09:46 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t					ft_strlcat(char *s1, const char *s2, size_t size)
{
	unsigned int		i0;
	unsigned int		i1;
	unsigned int		i2;
	unsigned int		i3;

	i0 = ft_strlen(s1);
	i1 = ft_strlen(s2);
	i2 = i0 + i1;
	i3 = 0;
	if (i0 < size)
	{
		while (i0 < size - 1)
			s1[i0++] = s2[i3++];
		s1[i0] = '\0';
		return (i2);
	}
	else
		return (size + i1);
}
