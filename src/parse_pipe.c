/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:57:38 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 15:49:24 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static char		*switch_pipe(t_env *env, char *line)
{
	char		**split;
	char		*line_rev;

	if (!env->switched)
		env->switched = 1;
	else
		env->switched = 0;
	split = ft_strsplit(line, '-');
	line_rev = ft_strjoin_free(split[1], "-", 0);
	line_rev = ft_strjoin_free(line_rev, split[0], 1);
	ft_free_tab(split);
	return (line_rev);
}

static int		patch_pipe(t_env *env, char *line)
{
	int			i;
	int			tiret;
	int			space;

	i = -1;
	tiret = 0;
	space = 0;
	while (line[++i] && tiret < 2 && space < 1)
	{
		if (line[i] == '-')
			tiret++;
		if (line[i] == ' ')
			space++;
	}
	if (tiret > 1 || space > 0)
	{
		error_parsing(env, "initialisation tunnel invalide", line);
		return (1);
	}
	return (0);
}

static int		valide_pipe(t_env *env, char *line)
{
	int			i;
	int			j;
	char		**split;

	i = -1;
	j = -1;
	split = ft_strsplit(line, '-');
	while (++i < env->room_num)
		if (ft_strequ(split[0], env->room[i].name))
			break ;
	while (++j < env->room_num)
		if (ft_strequ(split[0], env->room[j].name))
			break ;
	if (i == env->room_num || j == env->room_num)
	{
		if (env->switched)
			line = switch_pipe(env, line);
		error_parsing(env, "initialisation tunnel invalide", line);
		ft_free_tab(split);
		return (0);
	}
	ft_free_tab(split);
	return (1);
}

static void		lex_pipe(t_env *env, char *line)
{
	char		**split;
	char		**pipe;
	int			i;
	int			j;

	i = 0;
	split = ft_strsplit(line, '-');
	if (!valide_pipe(env, line))
	{
		ft_free_tab(split);
		return ;
	}
	while (!ft_strequ(split[0], env->room[i].name))
		i++;
	if (!(pipe = (char **)ft_memalloc(sizeof(char *) *
	(++env->room[i].pipe_num + 1))))
		exit(0);
	j = -1;
	if (env->room[i].pipe_c)
		while (++j < env->room[i].pipe_num - 1)
			pipe[j] = ft_strdup(env->room[i].pipe_c[j]);
	pipe[(j < 0) ? 0 : j] = ft_strdup(split[1]);
	(env->room[i].pipe_c) ? ft_free_tab(env->room[i].pipe_c) : 42;
	env->room[i].pipe_c = pipe;
	ft_free_tab(split);
}

void			parse_pipe(t_env *env, char *line)
{
	int			len;
	char		*line_rev;

	len = len_param(ft_strsplit(line, '-'));
	if (len != 2 || patch_pipe(env, line) || double_pipe(env, line))
	{
		env->parsing_end = 0;
		error_parsing(env, "pipe invalide", line);
		return ;
	}
	if (double_double(env, line))
	{
		lex_pipe(env, line);
		line_rev = switch_pipe(env, line);
		ft_strdel(&line);
		lex_pipe(env, line_rev);
		line = switch_pipe(env, line_rev);
		ft_strdel(&line_rev);
	}
	if (line)
		ft_strdel(&line);
}
