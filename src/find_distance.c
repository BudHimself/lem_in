/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:56:21 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 15:28:14 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int		len_is_fill(t_env *env)
{
	int			y;

	y = 0;
	while (++y < env->room_num)
		if (env->room[y].len == 0 && env->room[y].pipe_num > 0)
			return (1);
	return (0);
}

static int		check_len2(t_env *env, int y, int x, int j)
{
	if (env->room[env->room[env->room[y].pipe[x]].pipe[j]].len >
		env->room[env->room[y].pipe[x]].len + 1 ||
		env->room[env->room[env->room[y].pipe[x]].pipe[j]].len == 0)
		return (1);
	return (0);
}

static int		check_len(t_env *env, int y, int j)
{
	if (env->room[env->room[y].pipe[j]].len > env->room[y].len + 1 ||
		env->room[env->room[y].pipe[j]].len == 0)
		return (1);
	return (0);
}

void			find_distance(t_env *env, int y, int x, int j)
{
	j = -1;
	if (y > env->room_num - 1)
		return ;
	if (y == env->room_num)
	{
		if (len_is_fill(env))
			find_distance(env, 0, 0, 0);
		return ;
	}
	if (x == env->room[y].pipe_num || (env->room[y].len == 0 && y > 0))
	{
		find_distance(env, y + 1, 0, 0);
		return ;
	}
	while (++j < env->room[y].pipe_num)
		if (check_len(env, y, j))
			env->room[env->room[y].pipe[j]].len = env->room[y].len + 1;
	j = -1;
	while (++j < env->room[env->room[y].pipe[x]].pipe_num)
		if (check_len2(env, y, x, j))
			env->room[env->room[env->room[y].pipe[x]].pipe[j]].len =
			env->room[env->room[y].pipe[x]].len + 1;
	env->room[0].len = 0;
	find_distance(env, y, x + 1, 0);
}
