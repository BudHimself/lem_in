/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:33:15 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/18 18:31:25 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	int		i;

	s1 = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1));
	i = 0;
	if (!s1)
		return (NULL);
	while (s[i])
	{
		s1[i] = f(s[i]);
		i++;
	}
	s1[i++] = '\0';
	return (s1);
}
