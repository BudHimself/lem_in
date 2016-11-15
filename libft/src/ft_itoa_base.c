/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:05:59 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:09:31 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char			*ft_itoa_base(long long value, int base)
{
	char		ret[20];
	int			i;
	int			sign;
	const char	hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	i = 0;
	sign = 0;
	if (value == 0)
		return (ft_strdup("0"));
	if (value < 0 && base == 10)
	{
		sign = -1;
		value *= -1;
	}
	while (value > 0)
	{
		ret[i++] = hex[value % base];
		value = value / base;
	}
	if (sign < 0)
		ret[i++] = '-';
	ret[i] = '\0';
	return (ft_strrev(ret));
}
