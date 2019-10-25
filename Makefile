#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 10:23:33 by erli              #+#    #+#              #
#    Updated: 2019/10/25 11:21:04 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	ft_ls

SRCSDIR			=	srcs

OBJSDIR			= 	objs

SRCS			=	main.c	\
					ls_create_list_from_args.c	ls_get_options.c 	ls_print.c	\
					\
					ls_usage.c \
					\
					\
					\
					ls_print_options.c \
					\
					ls_get_terminal_width.c









OBJS			=	$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC				=	gcc -g

CFLAG			=	-Wall -Werror -Wextra

INCL			=	-I includes/ -I libft/includes

RM				= 	rm -f

MYLIB			=	libft/libft.a

HEADER			=	includes/ft_ls.h libft/includes

LIB				=	-L libft -lft

GREEN			=	"\x1B[32m"

DEFAULT			=	"\x1B[0m"


all				:	libft
					@make -s $(NAME)

$(NAME)			:	$(OBJS) $(MYLIB)
					@echo "Compiling:" $(GREEN) $(NAME) $(DEFAULT)
					$(CC) $(CFLAG) $(INCL) $(OBJS) -o $(NAME) $(LIB)

libft			:
					@make -s -C libft/

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c $(HEADER)
					@mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAG) $(INCL) $< -o $@

norm			:	delsav
					@echo "==== Norme" $(GREEN) "srcs" $(DEFAULT) "===="
					norminette $(SRCSDIR)
					@echo "==== Norme" $(GREEN) "includes" $(DEFAULT) "===="
					norminette includes
#					@echo "==== Norme" $(GREEN) "libft" $(DEFAULT) "===="
#					make -C libft norm

clean			:
					@$(RM) $(OBJS)

fclean			:	clean
					@$(RM) $(NAME)

re				:
					@make fclean
					@make all

delsav			:
					@$(RM) *~
					@$(RM) */*~
					@$(RM) \#*\#
					@$(RM) */\#*\#

reset			:
					@make delsav
					@make fclean
					@make -C libft/ reset
					@rm -f $(OBJSDIR)

test			:	
					@make -s all
					@./$(NAME)

.PHONY			:	clean fclean delsav re reset libft test
