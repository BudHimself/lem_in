/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:39:02 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:12:47 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char			*ft_strrev(char *string)
{
	char		*str;
	int			i;
	int			j;

	if (!string)
		return (NULL);
	i = ft_strlen(string);
	str = ft_strnew(i);
	j = 0;
	while (i--)
		str[j++] = string[i];
	return (str);
}
