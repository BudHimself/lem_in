/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:05:17 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:32:03 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char		*ft_fill_wstr(char *p, unsigned char byte, unsigned int c)
{
	if (!p)
		return (NULL);
	if (byte == 1)
		p[0] = c;
	else if (byte == 2)
	{
		p[0] = (((c & 0x07c0) >> 6) + 0xC0);
		p[1] = ((c & 0x003F) + 0x80);
	}
	else if (byte == 3)
	{
		p[0] = (((c & 0xF000) >> 12) + 0xE0);
		p[1] = (((c & 0x0FC0) >> 6) + 0x80);
		p[2] = ((c & 0x003F) + 0x80);
	}
	else if (byte == 4)
	{
		p[0] = (((c & 0x1C0000) >> 18) + 0xF0);
		p[1] = (((c & 0x03F000) >> 12) + 0x80);
		p[2] = (((c & 0x0FC0) >> 6) + 0x80);
		p[3] = ((c & 0x3F) + 0x80);
	}
	return (p);
}
