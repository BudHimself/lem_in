/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_ant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:57:29 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:57:30 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		lex_ant(t_env *env, char *line)
{
	env->ant_number = ft_atoi(line);
	if (env->ant_number > 0 && env->ant_number <= INT_MAX)
	{
		env->parser.ant_number = 1;
		ft_strdel(&line);
		return ;
	}
	error_parsing(env, "nombre de fourmis non valide", line);
	return ;
}
