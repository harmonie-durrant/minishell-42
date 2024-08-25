# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 11:37:28 by rbryento          #+#    #+#              #
#    Updated: 2023/11/08 08:45:33 by rbryento         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_BASE	=	ft_isalpha.c\
				ft_isdigit.c\
				ft_isalnum.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_strlen.c\
				ft_memset.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_strlcpy.c\
				ft_strlcat.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_strncmp.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_strnstr.c\
				ft_atoi.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_split.c\
				ft_itoa.c\
				ft_strmapi.c\
				ft_striteri.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_lstnew_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstsize_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstmap_bonus.c
SRC_BASE	:= $(addprefix libft_base/, $(SRC_BASE))

SRC_PRINTF	=	ft_printf.c\
				ft_nbrlen.c\
				ft_printf_hexaflags.c\
				ft_printf_nbflags.c\
				ft_printf_strflags.c
SRC_PRINTF	:= $(addprefix libft_printf/, $(SRC_PRINTF))


OBJ_BASE	=	$(SRC_BASE:.c=.o)
OBJ_PRINTF	=	$(SRC_PRINTF:.c=.o)

NAME	=	libft.a

CFLAGS	=	-Wall -Werror -Wextra -I./include

$(NAME):	$(OBJ_BASE) $(OBJ_PRINTF)
	ar rcs $(NAME) $(OBJ_BASE) $(OBJ_PRINTF)

all:	$(NAME)

clean:
	rm -rf $(OBJ_BASE)
	rm -rf $(OBJ_PRINTF)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all