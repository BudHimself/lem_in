/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:58:16 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:58:16 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int				double_double(t_env *env, char *line)
{
	int			i;
	int			j;
	char		**split;

	i = -1;
	split = ft_strsplit(line, '-');
	while (++i < env->room_num)
	{
		if (ft_strequ(split[0], env->room[i].name))
		{
			j = -1;
			while (++j < env->room[i].pipe_num)
				if (ft_strequ(split[1], env->room[i].pipe_c[j]))
				{
					ft_free_tab(split);
					return (0);
				}
		}
	}
	ft_free_tab(split);
	return (1);
}

int				double_pipe(t_env *env, char *line)
{
	char		**split;

	split = ft_strsplit(line, '-');
	if (ft_strequ(split[0], split[1]))
	{
		error_parsing(env, "deux chambres sont identique", line);
		ft_free_tab(split);
		return (1);
	}
	ft_free_tab(split);
	return (0);
}
