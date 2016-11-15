/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:05:01 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:08:33 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void			free_data(t_data *data)
{
	free(PATH);
	free(OPT);
	free(SIZE);
}

static void			type_percent(t_data *data)
{
	char			*tmp;

	tmp = NULL;
	if (ZERO)
		tmp = fill_with_c((WIDTH > 1) ? WIDTH - 1 : 0, '0');
	else
		tmp = fill_with_c((WIDTH > 1) ? WIDTH - 1 : 0, ' ');
	tmp = (MOINS) ? ft_strjoin_free("%", tmp, 2) : ft_strjoin_free(tmp, "%", 1);
	STRING = ft_strjoin_free(STRING, tmp, 3);
}

static void			choose_arg(t_data *data, va_list *ap)
{
	if (DI_)
		type_di(ap, data);
	else if (OUX_)
		type_oux(ap, data);
	else if (C_)
		type_c(ap, data);
	else if (S_)
		type_s(ap, data);
	else if (P_)
		type_p(ap, data);
	else
		type_percent(data);
}

void				buff_string(va_list *ap, char *format, t_data *data)
{
	int				i;

	i = -1;
	while (++i < (int)ft_strlen(format))
	{
		if (format[i] != '%')
			add_c_to_string(&STRING, format[i]);
		else
		{
			if (format[i + 1] == '\0')
				return ;
			get_struct_part1(format, data, i);
			choose_arg(data, ap);
			i += data->len_path + 1;
			free_data(data);
		}
	}
}
