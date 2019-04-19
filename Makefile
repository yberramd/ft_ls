# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberramd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 16:45:12 by yberramd          #+#    #+#              #
#    Updated: 2019/04/19 12:19:33 by yberramd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIBFT_A = libft/libft.a
FT_PRINTF_A = ft_printf/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/

FT_PRINTF = ft_printf/

PRINTF = ft_printf/Makefile					\
		 ft_printf/includes/ft_printf.h		\
		 ft_printf/srcs/buff.c				\
		 ft_printf/srcs/checkers.c			\
		 ft_printf/srcs/convert.c			\
		 ft_printf/srcs/convert_s.c			\
		 ft_printf/srcs/ft_atoi.c			\
		 ft_printf/srcs/ft_isdigit.c		\
		 ft_printf/srcs/ft_printf.c			\
		 ft_printf/srcs/ft_strlen.c			\
		 ft_printf/srcs/parser.c			\
		 ft_printf/srcs/power.c				\
		 ft_printf/srcs/solve.c				\

COMPILE = $(CC) $(CFLAGS) $(SRCS)

LIB = libft/Makefile			\
	  libft/ft_atoi.c			\
	  libft/ft_bzero.c			\
	  libft/ft_isalnum.c		\
	  libft/ft_isalpha.c		\
	  libft/ft_isascii.c		\
	  libft/ft_isdigit.c		\
	  libft/ft_isprint.c		\
	  libft/ft_itoa.c			\
	  libft/ft_memalloc.c		\
	  libft/ft_memccpy.c		\
	  libft/ft_memchr.c			\
	  libft/ft_memcmp.c			\
	  libft/ft_memcpy.c			\
	  libft/ft_memdel.c			\
	  libft/ft_memmove.c		\
	  libft/ft_memset.c			\
	  libft/ft_strcat.c			\
	  libft/ft_strchr.c			\
	  libft/ft_strclr.c			\
	  libft/ft_strcmp.c			\
	  libft/ft_strcpy.c			\
	  libft/ft_strdel.c			\
	  libft/ft_strdup.c			\
	  libft/ft_striter.c		\
	  libft/ft_striteri.c		\
	  libft/ft_strjoin.c		\
	  libft/ft_strjoinfree.c	\
	  libft/ft_strlcat.c		\
	  libft/ft_strlen.c			\
	  libft/ft_strmap.c			\
	  libft/ft_strmapi.c		\
	  libft/ft_strncat.c		\
	  libft/ft_strncmp.c		\
	  libft/ft_strncpy.c		\
	  libft/ft_strnew.c			\
	  libft/ft_strnequ.c		\
	  libft/ft_strnstr.c		\
	  libft/ft_strequ.c			\
	  libft/ft_strrchr.c		\
	  libft/ft_strsplit.c		\
	  libft/ft_strstr.c			\
	  libft/ft_strsub.c			\
	  libft/ft_strtrim.c		\
	  libft/ft_tolower.c		\
	  libft/ft_toupper.c		\
	  libft/ft_strndup.c		\
	  libft/ft_putchar.c		\
	  libft/ft_putstr.c			\
	  libft/ft_putnbr.c			\
	  libft/ft_putendl.c		\
	  libft/ft_putchar_fd.c		\
	  libft/ft_putstr_fd.c		\
	  libft/ft_putnbr_fd.c		\
	  libft/ft_putendl_fd.c		\
	  libft/ft_strtok.c			\
	  libft/ft_strtokcpy.c		\
	  libft/ft_power.c			\
	  libft/ft_atoi_base.c		\
	  libft/ft_itoa_base.c		\
	  libft/ft_lstnew.c			\
	  libft/ft_lstadd.c			\
	  libft/ft_lstaddlast.c		\
	  libft/ft_lstiter.c		\
	  libft/ft_lstmap.c			\
	  libft/ft_lstdelone.c		\
	  libft/ft_lstdel.c			\
	  libft/ft_change_base.c	\
	  libft/get_next_line.c		\
	  libft/ft_strjoin_free.c

SRCS = srcs/ft_ls.c					\
	   srcs/sort.c					\
	   srcs/list.c					\
	   srcs/single_elem.c			\
	   srcs/additional_functions.c

all : $(NAME)

$(NAME): $(SRCS) $(LIB) $(PRINTF)
	@make -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@$(COMPILE) -o $(NAME) $(LIBFT_A) $(FT_PRINTF_A)

clean :
	@make clean -C $(LIBFT)
	@make clean -C $(FT_PRINTF)
	@rm -rf $(OBJS)

fclean : clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(FT_PRINTF)
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean flcean re
