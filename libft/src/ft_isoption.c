/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoption.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:33:47 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:09:20 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

BOOL			ft_isoption(char c)
{
	const char	*option = "#-+ 0";

	if (ft_strchr((char *)option, c))
		return (1);
	return (0);
}
