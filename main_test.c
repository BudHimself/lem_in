/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:56:41 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 15:07:12 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/lem_in.h"

int			main(int ac, char **av)
{
	int		num;
	int		x;
	char	*map;
	char	*call;
	char	*bin;

	if (ac != 2)
	{
		ft_printf("give me number of map pls\n");
		return (-1);
	}
	num = ft_atoi(av[1]);
	x = 0;
	while (++x <= num)
	{
		map = ft_strdup("./map_test/map");
		map = ft_strjoin_free(map, ft_strdup(ft_itoa(x)), 3);
		ft_printf("------------------------------------------\n%27s", map);
		ft_printf("\n------------------------------------------\n\n");
		bin = ft_strdup("./lem-in < ");
		call = ft_strjoin_free(bin, map, 3);
		system(call);
	}
	return (0);
}
