# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 08:42:10 by rbryento          #+#    #+#              #
#    Updated: 2024/08/27 16:38:42 by rbryento         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	main.c						\
		t_minishell.c				\
		parse.c						\
		ft_ext.c					\
		local_command.c				\
		find_command.c				\
		create_child.c				\
		env.c						\
		get_args.c					\
		get_args_ext.c				\
		remove_double_quotes.c		\
		tree/process_tree.c			\
		tree/tree.c					\
		tree/seperator.c			\
		tree/forks.c				\
		tree/get_info.c				\
		builtins/builtin_handler.c	\
		builtins/export.c			\
		builtins/export_utils.c		\
		builtins/echo.c				\
		builtins/unset_env.c		\
		builtins/builtins.c			\
		builtins/cd_utils.c			\
		builtins/create_env.c		\
		command/get_sign_command.c	\

NAME	=	minishell

SRC	:= $(addprefix src/, $(SRC))

OBJ	=	$(SRC:.c=.o)

LIBDIR	=	./lib/ft

CFLAGS	=	-Wall -Werror -Wextra -I./include

LDFLAGS	=	$(CFLAGS) -I./$(LIBDIR)/include -L$(LIBDIR) -lft -lreadline


$(NAME):	$(OBJ) lib
	make -C $(LIBDIR)
	cc -o $(NAME) $(OBJ) $(LDFLAGS)
	make clean

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	make -C $(LIBDIR) fclean
	rm -rf $(NAME)

re:	fclean all