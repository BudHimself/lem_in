/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:26:13 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:09:27 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

BOOL			ft_istype(char c)
{
	const char	*type = "%cCsSdDipoOuUxX";

	if (ft_strchr((char *)type, c))
		return (1);
	return (0);
}
