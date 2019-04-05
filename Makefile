# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberramd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 16:45:12 by yberramd          #+#    #+#              #
#    Updated: 2019/04/05 11:36:36 by yberramd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIBFT_A = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/

COMPILE = $(CC) $(CFLAGS) $(SRCS)

LIB = libft/*.c		\
		   libft/libft.h

SRCS = srcs/ft_ls.c			\
	   srcs/sort.c			\
	   srcs/single_elem.c	\

all : $(NAME)

$(NAME): $(SRCS) $(LIB)
	@make -C $(LIBFT)
	@$(COMPILE) -o $(NAME) $(LIBFT_A)

clean :
	@make clean -C $(LIBFT)
	@rm -rf $(OBJS)

fclean : clean
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean flcean re
