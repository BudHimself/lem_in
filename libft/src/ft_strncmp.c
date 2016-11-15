/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:38:35 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:38:36 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int max;
	int l1;
	int l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	max = (l1 < l2) ? l2 : l1;
	max = (max < (int)n) ? max : (int)n;
	return (ft_memcmp(s1, s2, max));
}
