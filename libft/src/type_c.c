/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:10:40 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:14:01 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void			type_c(va_list *ap, t_data *data)
{
	wchar_t		c;
	char		*tmp;
	char		*tmp2;
	int			bytes;
	int			ret;

	c = 0;
	tmp2 = NULL;
	c = (TYPE == 'C' || L_) ? (wchar_t)va_arg(*ap, wchar_t) :
		(int)va_arg(*ap, int);
	ret = (TYPE == 'C' || L_) ? 0 : 1;
	(c == '\0') ? (NUL++) : 42;
	bytes = (ret) ? ret : ft_get_bytes(c);
	tmp = ft_strnew(bytes);
	tmp = ft_fill_wstr(tmp, bytes, c);
	tmp2 = (WIDTH) ? fill_with_c(WIDTH - bytes, FILL) : tmp2;
	tmp = (MOINS) ? ft_strjoin_free(tmp, tmp2, 3) :
		ft_strjoin_free(tmp2, tmp, 3);
	STRING = (c == '\0') ?
		ft_strjoin_free(STRING, ft_strjoin_free(tmp, "\v", 0), 3) :
		ft_strjoin_free(STRING, tmp, 3);
}
