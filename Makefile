# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 16:31:25 by rsenelle          #+#    #+#              #
#    Updated: 2022/01/31 16:32:28 by rsenelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRCS_F		=	parsing.c		utils.c		init_struct.c

SRCS_D		=	src/

INCLUDE		=	-I./include/ -I./libft/

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -MMD -g

SRCS		=	$(addprefix $(SRCS_D),$(SRCS_F))

LIBFT		=	./libft/libft.a

$(NAME)		:	$(OBJS)
				$(MAKE) -C $(dir $(LIBFT))
				$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT) $(OBJS) -o $(NAME)


all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean	:	
			$(MAKE) clean -C $(dir $(LIBFT))
			rm -rf $(OBJS) $(OBJS:.o=.d)

fclean	:	clean
			$(MAKE) fclean -C $(dir $(LIBFT))
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus

-include	$(OBJS:.o=.d)