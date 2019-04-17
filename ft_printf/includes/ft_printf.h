/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:55:09 by bprunevi          #+#    #+#             */
/*   Updated: 2019/04/17 11:30:38 by bprunevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define PRINTF_BUFF_SIZE 4096
# define STDOUT	1
# define DELIMITER_CHAR '.'

# define ISNAN(f) (f!=f)

typedef struct		s_opts
{
	unsigned char	minus:1;
	unsigned char	plus:1;
	unsigned char	sharp:1;
	unsigned char	zero:1;
	unsigned char	space:1;
}					t_opts;

typedef struct		s_format
{
	int				width;
	int				accuracy;
	unsigned char	size[2];
	unsigned char	type;
	struct s_opts	opts;
}					t_format;

typedef struct		s_params
{
	char			buff[PRINTF_BUFF_SIZE];
	va_list			ap;
	int				len;
	unsigned short	buff_index;
}					t_params;

typedef struct		s_checker
{
	unsigned char	is_type:1;
	unsigned char	is_size:1;
	unsigned char	is_width:1;
	unsigned char	is_opt:1;
	unsigned char	is_accuracy:1;
}					t_checker;

int					ft_printf(const char *format, ...);
int					parser(const char *str);
int					opt_char_checker(char c);
int					type_char_checker(char c);
int					size_char_checker(char c);
int					width_char_checker(char c);
int					accuracy_char_checker(char c);
int					format_char_checker(t_checker *checker, char c);
void				empty_buff();
void				check_buff();
void				add_sub_to_buff(const char *s, int len);
int					add_char_to_buff(char c);
void				ft_lltoa(long long i, t_format format);
void				ft_ftoa(double i, t_format format);
void				ft_llutoa(unsigned long long i, t_format format);
void				ft_llutoa_oct(unsigned long long i, t_format format);
void				ft_llutoa_hex(unsigned long long i, t_format f, char *bt);
void				solve(t_format format);
long long			ten_power(long long a);
long long			eight_power(long long a);
long long			sixteen_power(long long a);
long long			chars_before_integer(t_format *format, int c, int t, int x);
void				ft_stoa(char *c, t_format format);
void				ft_ctoa(char c, t_format format);
int					ft_atoi(const char *s);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *str);
int					ft_floattest(double f, t_format format);

extern struct s_params params;
#endif
