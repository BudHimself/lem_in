/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lemin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:57:56 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:57:56 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		print_start_end(t_env *env, int index)
{
	int			i;

	i = -1;
	while (++i < env->ant_number)
	{
		env->room[env->result[index]].ant_number += 1;
		env->room[env->result[index + 1]].ant_number -= 1;
		ft_printf("L%d-", env->room[env->result[index]].ant_number);
		ft_printf("%s ", env->room[env->result[index]].name);
	}
	ft_putchar('\n');
}

static void		switch_ant(t_env *env, int index)
{
	env->error = 0;
	if (env->len_result == 3 && env->result[index] == env->end_index &&
		env->result[index + 1] == env->start_index)
	{
		print_start_end(env, index);
		exit(0);
	}
	else if (env->result[index + 1] == env->start_index)
	{
		env->num_of_the_ant++;
		env->room[env->result[index]].num_of_the_ant = env->num_of_the_ant;
		env->room[env->result[index]].ant_number += 1;
		env->room[env->result[index + 1]].ant_number -= 1;
	}
	else
	{
		env->room[env->result[index]].num_of_the_ant =
		env->room[env->result[index + 1]].num_of_the_ant;
		env->room[env->result[index]].ant_number += 1;
		env->room[env->result[index + 1]].ant_number -= 1;
	}
}

static void		print_result(t_env *env)
{
	int			i;
	int			j;

	env->room[env->start_index].ant_number = env->ant_number;
	while (env->room[env->end_index].ant_number < env->ant_number)
	{
		i = -1;
		while (++i + 2 < env->len_result)
			if (env->room[env->result[i + 1]].ant_number > 0)
				switch_ant(env, i);
		j = -1;
		while (++j < env->len_result - 2)
			if (env->room[env->result[j]].ant_number > 0)
			{
				ft_printf("L%d-", env->room[env->result[j]].num_of_the_ant);
				ft_printf("%s ", env->room[env->result[j]].name);
			}
		ft_putchar('\n');
	}
}

void			print_lemin(t_env *env)
{
	ft_putendl(env->buff);
	ft_putchar('\n');
	print_result(env);
}
