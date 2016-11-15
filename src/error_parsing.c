/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:57:02 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 15:40:19 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		error_parsing(t_env *env, char *message, char *line)
{
	if (message)
	{
		env->buff_error = ft_strjoin_free(env->buff_error, "\n\n", 1);
		env->buff_error = ft_strjoin_free(env->buff_error, message, 1);
		if (line)
		{
			env->buff_error = ft_strjoin_free(env->buff_error, " : ", 1);
			env->buff_error = ft_strjoin_free(env->buff_error, line, 1);
		}
	}
	env->parsing_end = 0;
}
