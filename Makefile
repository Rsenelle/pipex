# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 16:31:25 by rsenelle          #+#    #+#              #
#    Updated: 2022/03/12 21:22:29 by rsenelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

NAME_BONUS		=	pipex_bonus

SRCS_F			=	main.c				check_path.c		utils.c		pipex.c\
					heredoc.c		get_next_line.c		get_next_line_utils.c

SRCS_D			=	src/

INCLUDE			=	-I./include/ -I./libft/

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -MMD -g

SRCS			=	$(addprefix $(SRCS_D),$(SRCS_F))

LIBFT			=	./libft/libft.a

$(NAME)			:	$(OBJS) libft
					@echo 'Done'`$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT) $(OBJS) -o $(NAME)`''

$(NAME_BONUS)	:	$(OBJS) libft
					@echo 'Compiling...'`$(MAKE) -C $(dir $(LIBFT))`'\n'
					@echo 'Done'`$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT) $(OBJS) -o $(NAME_BONUS)`''

all		:	$(NAME)

libft	:
			@echo 'Compiling...'`$(MAKE) -C $(dir $(LIBFT))`'\n'
	

%.o		:	%.c
			@echo 'Compiling...'`$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@`''

bonus	:	$(NAME_BONUS)

clean	:	
			@echo 'Deleting...'`$(MAKE) clean -C $(dir $(LIBFT))`''
			@echo ''`rm -rf $(OBJS) $(OBJS:.o=.d)`''

fclean	:	clean
			@echo ''`$(MAKE) fclean -C $(dir $(LIBFT))`''
			@echo 'Deleted all'`rm -rf $(NAME) $(NAME_BONUS)`''

re		:	fclean all

.PHONY	:	all clean fclean re bonus libft

-include	$(OBJS:.o=.d)