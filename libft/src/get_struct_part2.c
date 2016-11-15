/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:06:41 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:13:38 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void			get_size(t_data *data)
{
	int				i;

	i = -1;
	while (PATH[++i])
		if (ft_is_c_size(PATH[i]))
			add_c_to_string(&SIZE, PATH[i]);
}

static void			get_precision(t_data *data)
{
	int				i;
	char			*tmp;

	i = -1;
	tmp = NULL;
	if (ft_isprecision(PATH))
	{
		while (PATH[++i] != '.')
			;
		i++;
		while (ft_isdigit(PATH[i]) &&
		(!ft_is_c_size(PATH[i]) || !ft_istype(PATH[i])))
			add_c_to_string(&tmp, PATH[i++]);
		PRECI = (tmp) ? ft_atoi(tmp) : 1;
	}
	REEL = ((POINT) && (ft_atoi(tmp) == 0)) ? 0 : 1;
	PRECI = (!PRECI) ? 1 : PRECI;
	free(tmp);
}

static void			get_width_mini(t_data *data)
{
	int				i;
	char			*tmp;

	i = 0;
	tmp = NULL;
	while (ft_isoption(PATH[i]) && PATH[i])
		i++;
	while (ft_isdigit(PATH[i]) && PATH[i] != '.' &&
	!ft_is_c_size(PATH[i]) && !ft_istype(PATH[i]))
		add_c_to_string(&tmp, PATH[i++]);
	WIDTH = (tmp) ? ft_atoi(tmp) : 0;
	free(tmp);
}

void				get_struct_part2(t_data *data)
{
	get_width_mini(data);
	get_precision(data);
	get_size(data);
}
