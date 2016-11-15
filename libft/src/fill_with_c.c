/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_with_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:28:39 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:31:51 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*fill_with_c(size_t len, char c)
{
	char	*padding;
	size_t	i;

	i = -1;
	padding = ft_strnew(len);
	while (++i < len)
		padding[i] = c;
	return (padding);
}
