/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 10:49:50 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/14 16:23:44 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		i2;

	i = 0;
	if (!s)
		return ("\0");
	i2 = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[i2] && (s[i2] == ' ' || s[i2] == '\n' || s[i2] == '\t'))
		i2--;
	if ((i2 - i + 1) <= 0)
		return ("\0");
	return (ft_strsub(s, i, (i2 - i + 1)));
}
