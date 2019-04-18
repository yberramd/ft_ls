/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bprunevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:45:09 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/18 10:22:56 by yberramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# define BUFF_SIZE 16

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstaddlast(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_atoi_base(char *nbr, char *base_from);
char			*ft_itoa_base(int nbr, char *base_to);
char			*ft_change_base(char *nbr, char *base_from, char *base_to);
int				ft_power(int a, int b);
char			*ft_strtok(char *str, const char *delim);
char			*ft_strtokcpy(char *str, const char *delim);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int i);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int i, int fd);
char			*ft_strndup(const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isascii(int c);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *s);
void			ft_bzero(void *b, size_t len);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int i);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
void			ft_strdel(char **ap);
char			*ft_strdup(const char *src);
void			ft_striter(char *tab, void (*f)(char *));
void			ft_striteri(char *tab, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinfree(char const *s1, char const *s2);
size_t			ft_strlcat(char *s1, const char *s2, size_t size);
char			*ft_strmap(char const *tab, char (*f)(char));
char			*ft_strmapi(char const *tab, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t nb);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *str, char c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				get_next_line(const int fd, char **line);
char			*ft_strjoin_free(char *line, char *buffer, int option);

#endif
