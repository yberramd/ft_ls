# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberramd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 16:45:12 by yberramd          #+#    #+#              #
#    Updated: 2019/04/17 10:56:06 by bprunevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIBFT_A = libft/libft.a
FT_PRINTF_A = ft_printf/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/
FT_PRINTF = ft_printf/

COMPILE = $(CC) $(CFLAGS) $(SRCS)

LIB = libft/*.c		\
	  libft/libft.h	\
	  ft_printf/includes/ft_printf.h

SRCS = srcs/ft_ls.c					\
	   srcs/sort.c					\
	   srcs/single_elem.c			\
	   srcs/additional_functions.c

all : $(NAME)

$(NAME): $(SRCS) $(LIB)
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
