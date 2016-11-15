/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:06:28 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:13:56 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int		ft_strlen_data(t_data *data)
{
	int			i;

	i = 0;
	if (STRING)
	{
		while (STRING[i] && (NUL >= 1))
		{
			if (STRING[i] == '\v')
				NUL--;
			i++;
		}
	}
	return (i);
}

static int		ft_strlen_vt(t_data *data)
{
	int			i;

	i = 0;
	if (STRING)
	{
		while (STRING[i] != '\v' && STRING[i] != '\0')
			i++;
	}
	return (i);
}

static void		ft_putstr_printf(t_data *data)
{
	int			i;
	int			nul;
	char		*save;

	i = 0;
	nul = NUL;
	save = STRING;
	while (nul >= 1)
	{
		write(1, STRING += i, ft_strlen_vt(data));
		(nul > 1) ? write(1, "\0", 1) : 42;
		i += ft_strlen_vt(data) + 1;
		nul--;
	}
	STRING = save;
	save = NULL;
}

/*
** setlocale(LC_ALL, "en_US.UTF-8");
** a rajouter dans ft_printf au cas ou l'env n'est pas sur en_US.UTF-8
*/

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_data		data;
	int			i;

	data.nul = 1;
	data.string = NULL;
	va_start(ap, format);
	buff_string(&ap, (char *)format, &data);
	va_end(ap);
	ft_putstr_printf(&data);
	i = ft_strlen_data(&data);
	free(data.string);
	return (i);
}
