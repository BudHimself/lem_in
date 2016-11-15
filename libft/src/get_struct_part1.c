/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:06:35 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:13:31 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void			get_path(char *format, t_data *data, int index)
{
	int				j;

	j = index + 1;
	while (format[j] && !ft_istype(format[j]))
		add_c_to_string(&PATH, format[j++]);
	add_c_to_string(&PATH, format[j]);
	data->len_path = j - index - 1;
}

static void			get_type(t_data *data)
{
	TYPE = PATH[ft_strlen(PATH) - 1];
	BASE = (TYPE == 'o' || TYPE == 'O') ? 8 : BASE;
	BASE = (TYPE == 'u' || TYPE == 'U') ? 10 : BASE;
	BASE = (TYPE == 'x' || TYPE == 'X') ? 16 : BASE;
}

static void			get_option(t_data *data)
{
	int				i;

	i = -1;
	while (PATH[++i] && (ft_isoption(PATH[i])))
		add_c_to_string(&OPT, PATH[i]);
	(MOINS && ZERO) ? del_c_to_string(&OPT, '0') : 42;
	((ft_isprecision(PATH) && ZERO) && DIOUX) ? del_c_to_string(&OPT, '0') : 42;
	((SPACE) && (PLUS)) ? del_c_to_string(&OPT, ' ') : 42;
	OPT = (!OPT) ? ft_strdup("9999") : OPT;
}

void				get_struct_part1(char *format, t_data *data, int index)
{
	init_struct(data);
	get_path(format, data, index);
	get_type(data);
	get_option(data);
	get_struct_part2(data);
}
