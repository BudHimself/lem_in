/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:58:03 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:58:03 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		print_map(t_env *env)
{
	int			i;
	int			j;

	i = 0;
	while (i < env->room_num)
	{
		j = 0;
		if (ft_strequ(env->start_name, env->room[i].name))
			ft_printf("         --------------\n         | START ROOM |\n");
		if (ft_strequ(env->end_name, env->room[i].name))
			ft_printf("         --------------\n         |  END ROOM  |\n");
		ft_putendl("--------------------------------");
		ft_printf("name room  : %s | ", env->room[i].name);
		ft_printf("pipe number : %d\n", env->room[i].pipe_num);
		while (j < env->room[i].pipe_num)
		{
			ft_printf("pipe %d     : %2s\n", j, env->room[i].pipe_c[j]);
			j++;
		}
		ft_printf("---------------\nindex room : %2d\n", env->room[i].index);
		i++;
	}
	ft_printf("--------------------------------\n\n");
}

void			print_arg(t_env *env, char **av)
{
	int			i;

	i = 0;
	while (av[++i])
	{
		if (ft_strstr(av[i], "-m"))
			print_map(env);
	}
}
