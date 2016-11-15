/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_c_to_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:27:36 by fhenry            #+#    #+#             */
/*   Updated: 2016/07/07 14:25:43 by francoishenry    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void		add_c_to_string(char **string, char c)
{
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	string[0] = ft_strjoin_free(string[0], tmp, 1);
}
