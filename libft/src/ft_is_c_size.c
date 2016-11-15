/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_c_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:25:19 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:08:45 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

BOOL			ft_is_c_size(char c)
{
	const char	*size = "hljz";

	if (ft_strchr((char *)size, c))
		return (1);
	return (0);
}
