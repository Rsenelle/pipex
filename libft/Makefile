# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 17:21:43 by rsenelle          #+#    #+#              #
#    Updated: 2022/02/20 11:41:39 by rsenelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_atoi.c			ft_bzero.c			ft_calloc.c\
		ft_isalnum.c		ft_isalpha.c		ft_isascii.c\
		ft_isdigit.c		ft_isprint.c		ft_memchr.c\
		ft_memcmp.c			ft_toupper.c		ft_memcpy.c\
		ft_memmove.c		ft_memset.c			ft_itoa.c\
		ft_putchar_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c\
		ft_putstr_fd.c		ft_strchr.c			ft_strdup.c\
		ft_striteri.c		ft_strjoin.c		ft_strlcat.c\
		ft_strlcpy.c		ft_strlen.c			ft_strmapi.c\
		ft_strncmp.c		ft_strnstr.c		ft_strrchr.c\
		ft_strtrim.c		ft_substr.c			ft_tolower.c\
		ft_split.c			add_str_to_arr.c	free_buf.c

FILES_BONUS =	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c		ft_lstsize_bonus.c\
				ft_lstlast_bonus.c		ft_lstadd_back_bonus.c		ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c		ft_lstiter_bonus.c			ft_lstmap_bonus.c
OBJ	= ${SRC:.c=.o}
OBJ_BONUS	=	${FILES_BONUS:.c=.o}
NAME	= libft.a
CC	= gcc
FLAGS	= -Wall -Werror -Wextra
HEADER	= libft.h
LIBC = ar rc
LIBR = ranlib
RM	= rm -f

.c.o:	${HEADER}
	@echo ''`${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}`'\n'

${NAME}: ${OBJ} ${HEADER}
	@echo ''`${LIBC} ${NAME} ${OBJ}`'\n'
	@echo ''`${LIBR} ${NAME}`''

all: ${NAME}

bonus:		${OBJ_BONUS}
			${LIBC} ${NAME} ${OBJ_BONUS}

clean:
	@echo ''`${RM} ${OBJ} ${OBJ_BONUS}`'\n'

fclean: clean
	@echo ''`${RM} ${NAME} ${OBJ_BONUS}`'\n'

re: fclean all

.PHONY: .c.o all clean fclean re 