/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:36:30 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/11 15:08:42 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	secure_len(const char *str)
{
	int		len;

	len = ft_strlen(str);
	if ((str[0] == '-' && len < 12) || len < 11)
		return (1);
	return (0);
}

static int	check_res(long res, long cut)
{
	long	ret;

	ret = res * cut;
	if (ret > INT_MAX || ret < INT_MIN)
		return (0);
	return (ret);
}

int			ft_atoi(const char *str)
{
	long	res;
	long	cup;

	res = 0;
	if (str == NULL || str == 0 || str[0] == '\0' || !secure_len(str))
		return (res);
	while (str[0] == '\n' || str[0] == '\v' || str[0] == '\t'
			|| str[0] == ' ' || str[0] == '\f' || str[0] == '\r')
		str++;
	cup = 1;
	if (*str == '-' || *str == '+')
	{
		cup = (*str == '-') ? -cup : cup;
		str++;
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (check_res(res, cup));
}
