# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoynet <amoynet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 14:10:13 by bprunevi          #+#    #+#              #
#    Updated: 2019/04/17 10:56:56 by bprunevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	 libftprintf.a

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Werror
CFLAGS		+=	-I includes

SRCDIR		=	srcs

OBJDIR		=	objects

SRCS_NAME	=	ft_printf.c				\
				buff.c					\
				checkers.c				\
				parser.c				\
				convert.c				\
				convert_s.c				\
				power.c					\
				solve.c					\
				ft_atoi.c				\
				ft_strlen.c				\
				ft_isdigit.c			\

SRCS		=	$(addprefix $(SRCDIR)/,$(SRCS_NAME))
OBJS		=	$(addprefix $(OBJDIR)/, $(SRCS_NAME:.c=.o))

.SILENT:
all:		$(NAME)

clean:
	rm -rf $(OBJDIR)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY : all clean fclean re

$(OBJS): | 	$(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $(LDLIBS) -o $@ $<

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS) 
	ranlib $(NAME)
