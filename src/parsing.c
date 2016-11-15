/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:56:24 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 15:38:20 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void			check_data(t_env *env)
{
	t_parsing	parser;

	parser = env->parser;
	if (parser.start != 2 || parser.end != 2 || parser.ant_number != 1)
	{
		error_parsing(env, "start/end ou nombre de fourmis non valide", NULL);
		if (env->buff)
			ft_putendl(env->buff);
		if (env->buff_error)
			ft_putendl(env->buff_error);
		exit(-1);
	}
}

static void		parse_command(t_env *env, char *line)
{
	if (ft_strstr(line, "##start") &&
	ft_strlen(line) == 7)
		env->parser.start = 1;
	else if (ft_strstr(line, "##end") &&
	ft_strlen(line) == 5)
		env->parser.end = 1;
	ft_strdel(&line);
}

static void		verif_coor(t_env *env, char *line)
{
	int			i;
	int			j;

	i = -1;
	while (++i < env->room_num)
	{
		j = i + 1;
		while (j < env->room_num)
		{
			if (env->room[i].coor_x == env->room[j].coor_x)
				if (env->room[i].coor_y == env->room[j].coor_y)
					break ;
			j++;
		}
		if (j != env->room_num)
			break ;
	}
	if (i != env->room_num)
		error_parsing(env, "2 chambres avec les memes coordonnees", line);
}

void			parsing(t_env *env, char *line)
{
	if (!env->parser.ant_number && str_is_digit(line))
		lex_ant(env, line);
	else if (env->ant_number && line[0] == '#')
		parse_command(env, line);
	else if (env->ant_number && ft_strstr(line, " ") && !ft_strstr(line, "-") &&
		env->first && !ft_strstr(line, "L"))
	{
		parse_room(env, line);
		verif_coor(env, env->save_line);
	}
	else if (env->ant_number && ft_strstr(line, "-") && !ft_strstr(line, " ") &&
		env->ant_number)
	{
		if (env->first)
			check_data(env);
		parse_pipe(env, line);
		env->first = 0;
	}
	else
	{
		error_parsing(env, "initialisation map invalide", line);
		return ;
	}
	if (env->parsing_end)
		save_line(env, env->save_line);
}
