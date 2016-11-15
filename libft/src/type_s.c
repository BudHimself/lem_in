/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:31:06 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 18:09:46 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void			fill_str(t_data *data, char *s)
{
	int				calcul;
	char			*tmp;
	char			*tmp2;

	LEN_ARG = ft_strlen(s);
	tmp = NULL;
	if (REEL)
	{
		tmp2 = ft_strnew(LEN_ARG);
		if (LEN_ARG > PRECI && PRECI != 1)
			LEN_ARG = PRECI;
		if (REEL)
			ft_strncpy(tmp2, s, (size_t)LEN_ARG);
		calcul = (WIDTH > LEN_ARG) ? WIDTH - LEN_ARG : 0;
		tmp = fill_with_c(calcul, FILL);
		if (MOINS)
			tmp = ft_strjoin_free(tmp2, tmp, 3);
		else
			tmp = ft_strjoin_free(tmp, tmp2, 3);
	}
	else
		tmp = fill_with_c(WIDTH, FILL);
	STRING = ft_strjoin_free(STRING, tmp, 3);
}

static char			*ft_wstr(wchar_t *str)
{
	char			*tmp;
	char			*tmp2;
	int				i;
	int				bytes;

	i = 0;
	tmp = NULL;
	if (str)
	{
		while (str[i])
		{
			tmp2 = ft_strnew(1);
			bytes = ft_get_bytes(str[i]);
			tmp = ft_strjoin_free(tmp, ft_fill_wstr(tmp2, bytes, str[i]), 3);
			i++;
		}
	}
	return (tmp);
}

static void			fill_wstr(t_data *data, wchar_t *ws)
{
	int				calcul;
	char			*tmp;
	char			*tmp2;

	LEN_ARG = ft_wstrlen(ws);
	tmp = NULL;
	tmp2 = NULL;
	if (LEN_ARG > PRECI && PRECI != 1)
		LEN_ARG = PRECI;
	if (REEL)
		tmp2 = ft_wstr(ws);
	LEN_ARG = ft_strlen(tmp2);
	calcul = (WIDTH > LEN_ARG) ? WIDTH - LEN_ARG : 0;
	tmp = fill_with_c(calcul, FILL);
	if (MOINS)
		tmp = ft_strjoin_free(tmp2, tmp, 3);
	else
		tmp = ft_strjoin_free(tmp, tmp2, 3);
	STRING = ft_strjoin_free(STRING, tmp, 3);
}

void				type_s(va_list *ap, t_data *data)
{
	char			*s;
	wchar_t			*ws;

	s = NULL;
	ws = NULL;
	if (TYPE == 'S' || (L_))
	{
		ws = va_arg(*ap, wchar_t *);
		if (!ws)
		{
			STRING = ft_strjoin_free(STRING, "(null)", 1);
			return ;
		}
		fill_wstr(data, ws);
	}
	else
	{
		s = va_arg(*ap, char *);
		if (!s)
		{
			STRING = ft_strjoin_free(STRING, "(null)", 1);
			return ;
		}
		fill_str(data, s);
	}
}
