/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:57:34 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 15:50:25 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		convert_tab(t_env *env)
{
	int			y;
	int			x;
	int			k;
	int			*pipe;

	y = -1;
	while (++y < env->room_num)
	{
		if (!(pipe = (int *)ft_memalloc(sizeof(int) * env->room[y].pipe_num)))
			exit(-1);
		x = -1;
		while (++x < env->room[y].pipe_num)
		{
			k = -1;
			while (++k < env->room_num - 1)
				if (ft_strequ(env->room[k].name, env->room[y].pipe_c[x]))
					break ;
			pipe[x] = k;
		}
		env->room[y].pipe = pipe;
	}
}

static void		order_index(t_env *env)
{
	int			i;
	int			j;
	t_room		*room_order;

	i = -1;
	if (!(room_order = (t_room *)ft_memalloc(sizeof(t_room) * env->room_num)))
		exit(-1);
	while (++i < env->room_num)
	{
		j = 0;
		while (j != env->room[i].index)
			j++;
		room_order[j] = env->room[i];
	}
	free(env->room);
	env->room = room_order;
	convert_tab(env);
}

static void		init_index_other_room(t_env *env, int i, int j)
{
	env->room[i].index = j;
	env->room[i].len = 0;
}

static void		init_index(t_env *env)
{
	int			i;
	int			j;

	i = -1;
	j = 2;
	while (++i < env->room_num)
	{
		if (ft_strequ(env->start_name, env->room[i].name))
		{
			env->room[i].index = 0;
			env->start_index = 0;
			env->room[i].len = 1;
			env->room[i].find_len = 0;
		}
		else if (ft_strequ(env->end_name, env->room[i].name))
		{
			env->room[i].index = 1;
			env->end_index = 1;
			env->room[i].len = 0;
		}
		else
			init_index_other_room(env, i, j++);
	}
	order_index(env);
}

int				main(int ac, char **av)
{
	t_env		env;
	char		*line;

	init_env(&env);
	while (env.parsing_end && get_next_line(0, &line) > 0)
	{
		env.save_line = ft_strdup(line);
		parsing(&env, line);
	}
	check_data(&env);
	init_index(&env);
	print_arg(&env, av);
	pathfinding(&env);
	print_lemin(&env);
	ft_strdel(&env.buff);
	ft_strdel(&env.buff_error);
	free_env(&env);
	ac = 0;
	return (0);
}
