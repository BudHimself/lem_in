/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:38:23 by fhenry            #+#    #+#             */
/*   Updated: 2016/07/07 14:29:57 by francoishenry    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strjoin_free(char *s1, char *s2, int free_malloc)
{
	char	*dest;

	dest = ft_strnew(ft_strlen_printf(s1) + ft_strlen_printf(s2));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, (char *)s1);
	ft_strcat(dest, (char *)s2);
	if (free_malloc == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	else if (free_malloc == 2)
		ft_strdel(&s2);
	else if (free_malloc == 1)
		ft_strdel(&s1);
	return (dest);
}
