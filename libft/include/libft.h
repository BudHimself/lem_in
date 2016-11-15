/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:04:30 by fhenry            #+#    #+#             */
/*   Updated: 2016/11/11 13:10:54 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <limits.h>
# include <locale.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BOOL		int
# define ULL		unsigned long long
# define PATH		data->path
# define OPT		data->option
# define WIDTH		data->width_mini
# define REEL		data->preci_reel
# define PRECI		data->preci_defaut
# define SIZE		data->size
# define TYPE		data->type
# define SIGN		data->signe
# define STRING		data->string
# define BASE		data->base
# define NUL		data->nul
# define LEN_ARG	data->len_arg
# define MAX_SPACE	data->max_space
# define MOINS		(ft_strstr(OPT, "-")) ? 1 : 0
# define PLUS		(ft_strstr(OPT, "+")) ? 1 : 0
# define SPACE		(ft_strstr(OPT, " ")) ? 1 : 0
# define DIESE		(ft_strstr(OPT, "#")) ? 1 : 0
# define ZERO		(ft_strstr(OPT, "0")) ? 1 : 0
# define POINT		(ft_strstr(PATH, ".")) ? 1 : 0
# define DIOUX		(ft_strchr("dDiIoOuUxX", TYPE)) ? 1 : 0
# define DIUX		(ft_strchr("dDiIuUxX", TYPE)) ? 1 : 0
# define DI_		(ft_strchr("dDiI", TYPE)) ? 1 : 0
# define OUX_		(ft_strchr("oOuUxX", TYPE)) ? 1 : 0
# define O_			(ft_strchr("oO", TYPE)) ? 1 : 0
# define U_			(ft_strchr("uU", TYPE)) ? 1 : 0
# define X_			(ft_strchr("xX", TYPE)) ? 1 : 0
# define P_			(ft_strchr("p", TYPE)) ? 1 : 0
# define C_			(ft_strchr("cC", TYPE)) ? 1 : 0
# define S_			(ft_strchr("sS", TYPE)) ? 1 : 0
# define PRC_		(ft_strchr("%", TYPE)) ? 1 : 0
# define HH_		(ft_strstr(SIZE, "hh"))
# define H_			(ft_strstr(SIZE, "h"))
# define LL_		(ft_strstr(SIZE, "ll"))
# define L_			(ft_strstr(SIZE, "l"))
# define J_			(ft_strstr(SIZE, "j"))
# define Z_			(ft_strstr(SIZE, "z"))
# define FILL		(ZERO) ? '0' : ' '
# define MAX(x, y)	(x > y) ? x : y
# define MIN(x, y)	(x < y) ? x : y
# define BUFF_SIZE	11000

typedef struct		s_lst
{
	int				fd;
	char			*str;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env_gnl
{
	int				ret;
	char			*eol;
	char			*tmp;
	char			**table;
	t_lst			**first;
}					t_env_gnl;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_data
{
	int				len_path;
	int				len_arg;
	char			*path;
	char			*option;
	int				width_mini;
	int				preci_reel;
	int				preci_defaut;
	char			*size;
	char			type;
	char			signe;
	char			*string;
	int				base;
	int				nul;
	int				max_space;
}					t_data;

/*
**					PERSO
*/

void				ft_free_tab(char **tab);
char				**expand_tab_c(char **src, char *string);

/*
**					FT_PRINTF
*/

int					ft_printf(const char *restrict format, ...);
void				buff_string(va_list *ap, char *format, t_data *data);
void				get_struct_part1(char *format, t_data *data, int index);
void				get_struct_part2(t_data *data);
BOOL				ft_isoption(char c);
BOOL				ft_isprecision(char *path);
BOOL				ft_is_c_size(char c);
BOOL				ft_istype(char c);
BOOL				ft_strtabstr(char **size, char *path);
void				ft_str_capitalizer(char **str);
void				add_c_to_string(char **string, char c);
void				del_c_to_string(char **string, char c);
BOOL				ft_strsrch(char *s1, char *s2);
char				*fill_with_c(size_t len, char c);
void				width_max(t_data *data, char **tmp, char *ddi, char *sign);
void				preci_max(t_data *data, char **tmp, char *ddi, char *sign);
void				len_arg_max(t_data *data, char **tmp, char *ddi,
					char *sign);
void				type_di(va_list *ap, t_data *data);
void				type_oux(va_list *ap, t_data *data);
void				type_c(va_list *ap, t_data *data);
void				type_s(va_list *ap, t_data *data);
void				type_p(va_list *ap, t_data *data);
char				*ft_ull_itoa_base(ULL value, int base);
char				*ft_itoa_base(long long value, int base);
void				get_sign(t_data *data, char sign[1][2]);
char				*ft_strrev(char *string);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t				ft_strlen_printf(const char *s);
size_t				ft_strnlen(const char *s, size_t n);
int					ft_get_bytes(unsigned int c);
char				*ft_fill_wstr(char *p, unsigned char byte, unsigned int c);
int					ft_islower(int c);
size_t				ft_wstrlen(wchar_t *s);
char				*ft_strjoin_free(char *s1, char *s2, int free_malloc);
void				init_struct(t_data *data);
char				*ft_itoa_base_oux(long long value, int base);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);

/*
**					LIBFT
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_str_printable(char *str);
char				*ft_strnncpy(const char *s1, int start, int end);
void				ft_putnbr_base(unsigned int nbr, char *base);
int					ft_is_upper(char *str, int index);
int					ft_is_lower(char *str, int index);

int					get_next_line(const int fd, char **line);

#endif
