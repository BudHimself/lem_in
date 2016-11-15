/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_printable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 10:47:46 by fhenry            #+#    #+#             */
/*   Updated: 2016/05/12 14:16:41 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int			ft_str_printable(char *str)
{
	int		i;
	int		print;

	i = 0;
	print = 0;
	if (str == NULL)
		return (0);
	while ((str[i] > 31 && str[i] < 127 && str[i]) ||
			str[i] == '\n' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] != '\0')
		return (0);
	else
		return (1);
}
