/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 10:34:42 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:19:30 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char		*ft_negative(char *integer, int count, int n)
{
	count += 1;
	while (count-- > 0)
	{
		integer[count] = (n % 10) + 48;
		n /= 10;
	}
	integer[0] = '-';
	return (integer);
}

static char		*ft_positive(char *integer, int count, int n)
{
	while (count--)
	{
		(integer)[count] = (n % 10) + 48;
		n /= 10;
	}
	return (integer);
}

static char		*ft_create_malloc(int n, int count)
{
	char		*memory;

	memory = NULL;
	if (n < 0)
		count += 2;
	else if (n > 0)
		count += 1;
	else if (n == 0)
		count = 0;
	else if (n == -2147483648)
		count = 12;
	memory = (char *)ft_memalloc(sizeof(char) * count);
	if (!memory)
		return (NULL);
	return (memory);
}

static char		*ft_particular(char *integer, int n)
{
	free(integer);
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("-2147483648"));
}

char			*ft_itoa(int n)
{
	int			i;
	char		*integer;
	int			count;

	count = 0;
	i = (n < 0) ? -n : n;
	while (i)
	{
		count++;
		i /= 10;
	}
	integer = ft_create_malloc(n, count);
	if (!integer)
		return (NULL);
	integer[ft_strlen(integer) + 1] = '\0';
	i = (n < 0) ? -n : n;
	if (n == 0 || n == -2147483648)
		return (ft_particular(integer, n));
	if (n < 0)
		return (ft_negative(integer, count, i));
	else
		return (ft_positive(integer, count, n));
}
