/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:37:52 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:37:53 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int		i_s1;
	int		i_s2;

	i_s1 = ft_strlen(s1) + 1;
	i_s2 = ft_strlen(s2) + 1;
	return (ft_memcmp(s1, s2, (i_s1 <= i_s2) ? i_s1 : i_s2));
}
