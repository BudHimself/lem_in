/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:15:21 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:13:13 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void		delete_maillon(t_lst **list, int fd)
{
	t_lst		*del;
	t_lst		*tmp;

	if (fd == (*list)->fd)
	{
		del = *list;
		*list = del->next;
		free(del->str);
		free(del);
		return ;
	}
	tmp = *list;
	while (tmp->next)
	{
		if (fd == tmp->next->fd)
		{
			del = tmp->next;
			tmp->next = del->next;
			free(del->str);
			free(del);
			return ;
		}
		tmp = tmp->next;
	}
}

static t_lst	*give_me_fd(t_lst **list, int fd)
{
	t_lst		*tmp;

	tmp = *list;
	while (tmp)
	{
		if (fd == tmp->fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	tmp->fd = fd;
	tmp->str = ft_strnew(0);
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

static int		get_return(t_env_gnl *env, t_lst *maillon, char **line)
{
	char	*tmp;

	if (env->ret == -1)
		return (-1);
	if (env->ret == 0 && env->eol == NULL)
	{
		if ((maillon->str)[0] == '\0')
		{
			*line = NULL;
			delete_maillon(env->first, maillon->fd);
			return (0);
		}
		*line = maillon->str;
		maillon->str = NULL;
		delete_maillon(env->first, maillon->fd);
		return (1);
	}
	*line = ft_strsub(maillon->str, 0, (env->eol - maillon->str));
	tmp = maillon->str;
	maillon->str = ft_strdup(env->eol + 1);
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			work[BUFF_SIZE + 1];
	static t_lst	*list = NULL;
	t_lst			*maillon;
	t_env_gnl		env;

	env.first = &list;
	env.tmp = NULL;
	if (fd == -1 || BUFF_SIZE < 1)
		return (-1);
	if ((maillon = give_me_fd(&list, fd)) == NULL)
		return (-1);
	env.ret = 0;
	while (((env.eol = ft_strchr(maillon->str, '\n')) == NULL) &&
			((env.ret = read(fd, work, BUFF_SIZE)) > 0))
	{
		work[env.ret] = '\0';
		env.tmp = maillon->str;
		maillon->str = ft_strjoin(env.tmp, work);
		free(env.tmp);
	}
	return (get_return(&env, maillon, line));
}
