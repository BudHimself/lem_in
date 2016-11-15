/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_arg_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:24:48 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:13:43 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void			len_arg_max(t_data *data, char **tmp, char *ddi, char *sign)
{
	tmp[0] = ((O_) && (DIESE) && ft_strcmp(ddi, "0")) ?
	ft_strjoin_free("0", tmp[0], 2) : tmp[0];
	tmp[0] = ft_strjoin_free(tmp[0], sign, 1);
	tmp[0] = ((DIOUX) && (REEL == 0) && (!ft_strcmp(ddi, "0"))) ?
	tmp[0] : ft_strjoin_free(tmp[0], ddi, 1);
	tmp[0] = ((DIESE) && (X_) && ft_strcmp(ddi, "0")) ?
	ft_strjoin_free("0x", tmp[0], 2) : tmp[0];
}
