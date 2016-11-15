/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:57:24 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:57:25 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			len_param(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		i++;
	ft_free_tab(split);
	return (i);
}