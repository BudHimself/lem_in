/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:23:54 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:14:45 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void		less_minus(t_data *data, char **tmp, char *ddi, char *sign)
{
	if (FILL == '0')
	{
		(SIGN == '-') ? del_c_to_string(&tmp[0], '-') : 42;
		(SIGN == '+') ? del_c_to_string(&tmp[0], '+') : 42;
		(SPACE) ? del_c_to_string(&tmp[0], ' ') : 42;
		tmp[0] = ft_strjoin_free(fill_with_c(MAX_SPACE, '0'), tmp[0], 3);
		tmp[0] = ((DIESE) && (X_) && ft_strcmp(ddi, "0")) ?
		ft_strjoin_free("0x", tmp[0], 2) : tmp[0];
		tmp[0] = ft_strjoin_free(sign, tmp[0], 2);
	}
	else
	{
		tmp[0] = ((DIESE) && (X_) && ft_strcmp(ddi, "0")) ?
		ft_strjoin_free("0x", tmp[0], 2) : tmp[0];
		tmp[0] = ft_strjoin_free(fill_with_c(MAX_SPACE, ' '), tmp[0], 3);
	}
}

void			width_max(t_data *data, char **tmp, char *ddi, char *sign)
{
	PRECI = ((DIESE) && (O_) && (LEN_ARG > PRECI)) ? LEN_ARG + 1 : PRECI;
	if (sign[0] != '\0')
		tmp[0] = (PRECI > LEN_ARG) ?
		ft_strjoin_free(sign, fill_with_c(PRECI - LEN_ARG, '0'), 2) :
		ft_strjoin_free(sign, tmp[0], 2);
	else
		tmp[0] = (PRECI > LEN_ARG) ?
		ft_strjoin_free(sign, fill_with_c(PRECI - LEN_ARG, '0'), 2) : tmp[0];
	tmp[0] = ((DIOUX) && (REEL == 0) && (!ft_strcmp(ddi, "0"))) ?
	tmp[0] : ft_strjoin_free(tmp[0], ddi, 1);
	MAX_SPACE = (WIDTH > (int)ft_strlen(tmp[0])) ?
	WIDTH - ft_strlen(tmp[0]) : 0;
	MAX_SPACE -= ((DIESE) && (X_)) ? 2 : 0;
	if (MOINS)
	{
		tmp[0] = ((DIESE) && (X_) && ft_strcmp(ddi, "0")) ?
		ft_strjoin_free("0x", tmp[0], 2) : tmp[0];
		tmp[0] = ft_strjoin_free(tmp[0], fill_with_c(MAX_SPACE, ' '), 3);
	}
	else
		less_minus(data, tmp, ddi, sign);
}
