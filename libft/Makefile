# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omillan <omillan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 11:14:47 by gagustin          #+#    #+#              #
#    Updated: 2021/09/11 21:15:06 by omillan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
SRCS		= ft_memset.c\
			ft_bzero.c\
			ft_itoa.c \
			ft_memcpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strlen.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_split.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_calloc.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_strdup.c\
			ft_strnstr.c \
			ft_strtrim.c \
			ft_strchr.c 

OBJS		= ${SRCS:.c=.o}
OBJS_B		= ${SRCS_B:.c=.o}
CC			= gcc
CFLAGS		= -Werror -Wextra -Wall
.c.o :
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.
$(NAME) :	${OBJS}
			ar rc $(NAME) ${OBJS}
			ranlib $(NAME)
bonus:		${OBJS} ${OBJS_B}
			ar rc $(NAME) ${OBJS}  ${OBJS_B}
			ranlib $(NAME)
so :        
			${CC} -shared -o libft.so ${OBJS}
all :		$(NAME)
clean :
			rm -f ${OBJS} ${OBJS_B}
fclean :	clean
			rm -f $(NAME)
			rm -f libft.so
re :		fclean all
.PHONY:		all clean fclean re .c.o test
