/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:56:30 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/12 14:56:31 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/include/libft.h"

typedef struct	s_room
{
	char		*name;
	int			ant;
	int			ant_number;
	int			num_of_the_ant;
	int			coor_x;
	int			coor_y;
	int			pipe_num;
	int			index;
	int			len;
	int			find_len;
	char		**pipe_c;
	int			*pipe;
}				t_room;

typedef struct	s_parsing
{
	int			ant_number;
	int			start;
	int			end;
}				t_parsing;

typedef struct	s_env
{
	int			ant_number;
	int			num_of_the_ant;
	int			room_num;
	int			parsing_end;
	int			first;
	int			path_number;
	char		*path;
	int			*result;
	int			len_result;
	int			error;
	int			switched;
	char		*start_name;
	int			start_index;
	char		*end_name;
	int			end_index;
	char		*buff;
	char		*buff_error;
	char		*save_line;
	t_parsing	parser;
	t_room		*room;
}				t_env;

void			init_env(t_env *env);
int				str_is_digit(char *str);
void			parsing(t_env *env, char *line);
int				len_param(char **split);
void			pathfinding(t_env *env);
void			error_parsing(t_env *env, char *message, char *line);
void			free_room(t_env *env);
void			check_data(t_env *env);
int				*expand_tab_i(int *src, int old_len, int value);
void			free_env(t_env *env);
void			save_line(t_env *env, char *line);
void			print_lemin(t_env *env);
void			print_arg(t_env *env, char **av);
void			find_distance(t_env *env, int y, int x, int j);
void			lex_ant(t_env *env, char *line);
void			parse_room(t_env *env, char *line);
void			parse_pipe(t_env *env, char *line);
int				double_double(t_env *env, char *line);
int				double_pipe(t_env *env, char *line);

#endif
