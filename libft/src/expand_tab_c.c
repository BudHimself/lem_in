/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tab_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:26:16 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/15 14:16:26 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char			**expand_tab_c(char **src, char *string)
{
	int			i;
	int			len;
	char		**dst;

	len = 0;
	while (src[len])
		len++;
	if (!(dst = (char **)ft_memalloc(sizeof(char *) * len)))
		exit(-1);
	i = -1;
	while (++i < len)
	{
		dst[i] = ft_strdup(src[i]);
		ft_strdel(&src[i]);
	}
	free(src);
	dst[i] = ft_strdup(string);
	return (dst);
}
