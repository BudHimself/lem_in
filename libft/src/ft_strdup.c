/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:38:11 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:38:12 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_strdup(const char *s)
{
	char	*copy;

	copy = ft_strnew(ft_strlen(s));
	if (copy == NULL)
		return (NULL);
	ft_strcpy(copy, s);
	return (copy);
}
