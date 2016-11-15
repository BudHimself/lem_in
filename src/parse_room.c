/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:57:44 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:57:45 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static t_room	*fill_room(t_env *env, t_room *room)
{
	int			i;

	i = 0;
	while (i < env->room_num - 1)
	{
		room[i] = env->room[i];
		i++;
	}
	return (room);
}

static t_room	init_room(t_env *env, char *line, t_room room)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	room.name = ft_strdup(split[0]);
	room.ant = 0;
	room.ant_number = 0;
	room.num_of_the_ant = 0;
	room.coor_x = ft_atoi(split[1]);
	room.coor_y = ft_atoi(split[2]);
	room.pipe_num = 0;
	room.index = -1;
	room.len = 0;
	room.pipe = NULL;
	if (env->parser.start == 1)
	{
		env->start_name = ft_strdup(room.name);
		env->parser.start = 2;
	}
	else if (env->parser.end == 1)
	{
		env->end_name = ft_strdup(room.name);
		env->parser.end = 2;
	}
	ft_free_tab(split);
	return (room);
}

static void		verif_double_room(t_env *env, char *line)
{
	int			i;
	char		**split;

	i = -1;
	if (env->room_num > 1)
	{
		split = ft_strsplit(line, ' ');
		while (++i < env->room_num - 1)
			if (!ft_strcmp(env->room[i].name, split[0]))
				break ;
		if (i != env->room_num - 1)
		{
			error_parsing(env,
				"initialisation de room invalide, chambre deja declare :",
				line);
			return ;
		}
		ft_free_tab(split);
	}
	free(env->room);
}

void			parse_room(t_env *env, char *line)
{
	t_room		*room;
	int			len;

	len = len_param(ft_strsplit(line, ' '));
	if (len == 3)
	{
		if (!(room = (t_room *)ft_memalloc(sizeof(t_room) * ++env->room_num)))
			return ;
		if (env->room)
		{
			room = fill_room(env, room);
			verif_double_room(env, line);
		}
		room[env->room_num - 1] = init_room(env, line, room[env->room_num - 1]);
		env->room = room;
		ft_strdel(&line);
	}
	else
	{
		error_parsing(env, "initialisation de room invalide", line);
		return ;
	}
}
