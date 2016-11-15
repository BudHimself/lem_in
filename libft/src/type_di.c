/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:30:37 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:14:05 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void		cast_atoi_di(t_data *data, char **ddi, long long d)
{
	if (LL_)
		ddi[0] = ft_ull_itoa_base((long long)d, 10);
	else if (L_ || (TYPE == 'D'))
		ddi[0] = ft_ull_itoa_base((long)d, 10);
	else if (HH_)
		ddi[0] = ft_ull_itoa_base((unsigned char)d, 10);
	else if (H_)
		ddi[0] = ft_itoa_base((unsigned short int)d, 10);
	else if (Z_)
		ddi[0] = ft_ull_itoa_base((size_t)d, 10);
	else if (J_)
		ddi[0] = ft_ull_itoa_base((intmax_t)d, 10);
	else
		ddi[0] = ft_itoa_base((unsigned int)d, 10);
}

static void		cast_size_di(t_data *data, va_list *ap, long long *d)
{
	if (LL_)
		d[0] = (long long)va_arg(*ap, long long);
	else if (L_ || (TYPE == 'D'))
		d[0] = (long)va_arg(*ap, long);
	else if (HH_)
		d[0] = (signed char)va_arg(*ap, int);
	else if (H_)
		d[0] = (short int)va_arg(*ap, int);
	else if (Z_)
		d[0] = (size_t)va_arg(*ap, size_t);
	else if (J_)
		d[0] = (intmax_t)va_arg(*ap, intmax_t);
	else
		d[0] = (int)va_arg(*ap, int);
	SIGN = (d[0] >= 0) ? '+' : '-';
	if (d[0] < 0)
	{
		(PLUS) ? del_c_to_string(&OPT, '+') : 42;
		(SPACE) ? del_c_to_string(&OPT, ' ') : 42;
		d[0] *= -1;
	}
}

void			type_di(va_list *ap, t_data *data)
{
	long long	d;
	char		*ddi;
	char		*tmp;
	char		sign[2];

	tmp = NULL;
	ddi = NULL;
	cast_size_di(data, ap, &d);
	cast_atoi_di(data, &ddi, d);
	LEN_ARG = ft_strlen(ddi);
	get_sign(data, &sign);
	if (WIDTH >= (MAX(PRECI, LEN_ARG)))
		width_max(data, &tmp, ddi, sign);
	else if (PRECI >= (MAX(WIDTH, LEN_ARG)))
		preci_max(data, &tmp, ddi, sign);
	else
		len_arg_max(data, &tmp, ddi, sign);
	STRING = ft_strjoin_free(STRING, tmp, 3);
	free(ddi);
}
