/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:09:43 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/20 19:16:55 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_count_word(char const *s, char c)
{
	int		i;
	int		save;
	int		count;

	i = 0;
	save = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && save == 0)
		{
			count++;
			save = 1;
		}
		if (s[i] == c && save == 1)
			save = 0;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(str = (char**)ft_memalloc(sizeof(char*) * (ft_count_word(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			str[k++] = ft_strsub(s, j, (i - j));
		}
		else
			i++;
	}
	str[k] = NULL;
	return (str);
}
