/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:05:24 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:05:26 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int			ft_get_bytes(unsigned int c)
{
	int		bytes;

	bytes = -1;
	if (c < 0x7F)
		bytes = 1;
	else if (c < 0x7FF)
		bytes = 2;
	else if (c < 0xFFFF)
		bytes = 3;
	else if (c < 0x10FFFF)
		bytes = 4;
	return (bytes);
}
