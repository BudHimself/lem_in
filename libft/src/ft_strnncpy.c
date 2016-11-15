/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:47:22 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/26 16:50:33 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_test(const char *s1, int start, int end)
{
	size_t	tmp;

	tmp = (size_t)end;
	if (start > end || !s1)
		return (0);
	if (ft_strlen(s1) < tmp)
		return (0);
	if (ft_str_printable((char *)s1) == 0)
		return (0);
	else
		return (1);
}

char		*ft_strnncpy(const char *s1, int start, int end)
{
	char	*dst;
	int		i;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	if (ft_test(s1, start, end) != 1)
	{
		ft_putstr("\n\n\n\nprobleme de parametre\n\n\n\n");
		free(dst);
		return (NULL);
	}
	while (start <= end)
	{
		dst[i] = (char)s1[start];
		i++;
		start++;
	}
	dst[i + 1] = '\0';
	return (dst);
}
