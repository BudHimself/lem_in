/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:12:38 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:14:24 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void			type_p(va_list *ap, t_data *data)
{
	void		*d;
	char		*tmp;
	char		*ptr;

	tmp = NULL;
	ptr = NULL;
	d = va_arg(*ap, void *);
	ptr = ft_strjoin_free("0x", ft_ull_itoa_base((ULL)d, 16), 2);
	LEN_ARG = ft_strlen(ptr);
	tmp = fill_with_c((WIDTH - LEN_ARG > 0) ? WIDTH - LEN_ARG : 0, ' ');
	tmp = (MOINS) ? ft_strjoin_free(ptr, tmp, 3) : ft_strjoin_free(tmp, ptr, 3);
	STRING = ft_strjoin_free(STRING, tmp, 3);
}
