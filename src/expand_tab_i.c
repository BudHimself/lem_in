/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tab_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:57:08 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:57:09 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int				*expand_tab_i(int *src, int old_len, int value)
{
	int			*dst;
	int			i;

	if (!(dst = (int *)ft_memalloc(sizeof(int) * old_len)))
		exit(-1);
	i = -1;
	while (++i < old_len - 1)
		dst[i] = src[i];
	free(src);
	dst[i] = value;
	return (dst);
}
