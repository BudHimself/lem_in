/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:57:17 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:57:18 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void			free_room(t_env *env)
{
	int			i;

	i = -1;
	while (++i < env->room_num)
	{
		ft_strdel(&env->room[i].name);
		if (env->room[i].pipe_c)
			ft_free_tab(env->room[i].pipe_c);
	}
}

void			free_env(t_env *env)
{
	int			i;

	i = -1;
	ft_strdel(&env->start_name);
	ft_strdel(&env->end_name);
	while (++i < env->room_num)
		free(env->room[i].pipe);
	free_room(env);
	free(env->result);
	free(env->room);
}
