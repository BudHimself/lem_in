/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:58:11 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:58:11 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		save_line(t_env *env, char *line)
{
	if (env->buff)
		env->buff = ft_strjoin_free(env->buff, "\n", 1);
	env->buff = ft_strjoin_free(env->buff, line, 3);
}
