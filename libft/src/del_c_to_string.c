/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_c_to_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:28:10 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:28:13 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void		del_c_to_string(char **string, char c)
{
	char	*tmp;
	char	*save;
	int		j;
	int		i;

	if (*string)
	{
		save = *string;
		j = -1;
		i = -1;
		tmp = ft_strnew(ft_strlen(*string) - 1);
		while (save[++i])
			if (save[i] != c)
				tmp[++j] = save[i];
		ft_bzero(*string, (ft_strlen(*string)));
		*string = ft_strjoin_free(*string, tmp, 3);
	}
}
