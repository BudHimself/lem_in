/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_oux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:30:48 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 18:09:46 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void				cast_atoi_oux(t_data *data, char **ddi, ULL d)
{
	if (LL_)
		ddi[0] = ft_ull_itoa_base((ULL)d, BASE);
	else if (L_ || (TYPE == 'O') || (TYPE == 'U'))
		ddi[0] = ft_ull_itoa_base((unsigned long)d, BASE);
	else if (HH_)
		ddi[0] = ft_ull_itoa_base((unsigned char)d, BASE);
	else if (H_)
		ddi[0] = ft_ull_itoa_base((unsigned short)d, BASE);
	else if (Z_)
		ddi[0] = ft_ull_itoa_base((size_t)d, BASE);
	else if (J_)
		ddi[0] = ft_ull_itoa_base((uintmax_t)d, BASE);
	else
		ddi[0] = ft_ull_itoa_base((unsigned int)d, BASE);
}

static void				cast_size_oux(t_data *data, va_list *ap, ULL *d)
{
	if (LL_)
		d[0] = (ULL)va_arg(*ap, long long);
	else if (L_ || (TYPE == 'O') || (TYPE == 'U'))
		d[0] = (unsigned long)va_arg(*ap, long);
	else if (HH_)
		d[0] = (unsigned char)va_arg(*ap, int);
	else if (H_)
		d[0] = (unsigned short)va_arg(*ap, int);
	else if (Z_)
		d[0] = (size_t)va_arg(*ap, size_t);
	else if (J_)
		d[0] = (uintmax_t)va_arg(*ap, uintmax_t);
	else
		d[0] = (unsigned int)va_arg(*ap, int);
	(PLUS) ? del_c_to_string(&OPT, '+') : 42;
	(SPACE) ? del_c_to_string(&OPT, ' ') : 42;
	SIGN = '\0';
}

void					type_oux(va_list *ap, t_data *data)
{
	ULL					d;
	char				*ddi;
	char				*tmp;

	tmp = NULL;
	ddi = NULL;
	cast_size_oux(data, ap, &d);
	cast_atoi_oux(data, &ddi, d);
	LEN_ARG = ft_strlen(ddi);
	if (WIDTH >= (MAX(PRECI, LEN_ARG)))
		width_max(data, &tmp, ddi, "\0");
	else if (PRECI >= (MAX(WIDTH, LEN_ARG)))
		preci_max(data, &tmp, ddi, "\0");
	else
		len_arg_max(data, &tmp, ddi, "\0");
	(TYPE == 'X') ? ft_str_capitalizer(&tmp) : tmp;
	STRING = ft_strjoin_free(STRING, tmp, 3);
	free(ddi);
}
