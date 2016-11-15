/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:56:35 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:56:36 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		init_parsing(t_env *env)
{
	t_parsing	parser;

	parser.ant_number = 0;
	parser.start = 0;
	parser.end = 0;
	env->parser = parser;
}

void			init_env(t_env *env)
{
	init_parsing(env);
	env->ant_number = 0;
	env->num_of_the_ant = 0;
	env->room_num = 0;
	env->parsing_end = 1;
	env->buff = NULL;
	env->buff_error = NULL;
	env->room = NULL;
	env->first = 1;
	env->path_number = 1;
	env->path = NULL;
	env->result = NULL;
	env->len_result = 1;
	env->error = 1;
	env->switched = 0;
	env->start_name = NULL;
	env->start_index = 0;
	env->end_name = NULL;
	env->end_index = 1;
}
