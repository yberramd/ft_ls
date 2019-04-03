# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberramd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 16:45:12 by yberramd          #+#    #+#              #
#    Updated: 2019/04/03 17:34:18 by yberramd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror

COMPILE = $(CC) $(CFLAGS) $(SRCS)

SRCS = srcs/ft_ls.c

all : $(NAME)

$(NAME): $(SRCS)
	@$(COMPILE) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean flcean re
