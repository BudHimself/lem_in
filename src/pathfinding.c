/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:57:51 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:57:51 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		load_way(t_env *env, int index)
{
	env->result = expand_tab_i(env->result, env->len_result, index);
	env->len_result++;
}

static void		error_path(t_env *env, char *message)
{
	env->buff_error = ft_strjoin_free(env->buff_error, "\n\n", 1);
	env->buff_error = ft_strjoin_free(env->buff_error, message, 1);
	ft_putendl(env->buff);
	if (env->error)
		ft_putendl(env->buff_error);
	ft_strdel(&env->buff);
	ft_strdel(&env->buff_error);
	free_env(env);
}

static void		find_way(t_env *env)
{
	int			y;
	int			x;
	int			fewer;

	y = env->end_index;
	while (y != env->start_index && y < INT_MAX)
	{
		x = -1;
		fewer = INT_MAX;
		load_way(env, env->room[y].index);
		while (++x < env->room[y].pipe_num)
			if (env->room[y].len > env->room[env->room[y].pipe[x]].len &&
				!env->room[env->room[y].pipe[x]].ant)
				fewer = env->room[env->room[y].pipe[x]].index;
		y = fewer;
	}
	if (y != env->start_index)
	{
		error_path(env, "pas de chemin possible");
		exit(0);
	}
	load_way(env, env->room[y].index);
}

void			pathfinding(t_env *env)
{
	if (env->room[env->start_index].pipe_num > 0 &&
		env->room[env->end_index].pipe_num > 0)
	{
		find_distance(env, 0, 0, 0);
		find_way(env);
	}
	else
	{
		error_path(env, "pas de chemin possible");
		exit(0);
	}
}
