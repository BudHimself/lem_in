/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:29:02 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:29:04 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void		init_struct(t_data *data)
{
	data->len_path = 0;
	PATH = NULL;
	OPT = ft_strnew(0);
	WIDTH = 0;
	REEL = 0;
	PRECI = 0;
	SIZE = ft_strnew(0);
	TYPE = '\0';
	SIGN = '\0';
	BASE = 0;
	LEN_ARG = 0;
	MAX_SPACE = 0;
}
