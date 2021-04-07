# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ukheon <ukheon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 19:33:14 by ukwon             #+#    #+#              #
#    Updated: 2020/10/14 03:14:02 by ukheon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RANLIB  = ranlib

NAME    = libft.a
HEAD    = libft.h
SRCS	= ./ft_memset.c \
		  ./ft_bzero.c \
		  ./ft_memcpy.c \
		  ./ft_memccpy.c \
		  ./ft_memmove.c \
		  ./ft_memchr.c \
		  ./ft_memcmp.c \
		  ./ft_strlen.c \
		  ./ft_strlcpy.c \
		  ./ft_strlcat.c \
		  ./ft_strchr.c \
		  ./ft_strrchr.c \
		  ./ft_strnstr.c \
		  ./ft_strncmp.c \
		  ./ft_atoi.c \
		  ./ft_isalpha.c \
		  ./ft_isdigit.c \
		  ./ft_isalnum.c \
		  ./ft_isascii.c \
		  ./ft_isprint.c \
		  ./ft_tolower.c \
		  ./ft_toupper.c \
		  ./ft_calloc.c \
		  ./ft_strdup.c \
		  ./ft_substr.c \
		  ./ft_strjoin.c \
		  ./ft_strtrim.c \
		  ./ft_split.c \
		  ./ft_itoa.c \
		  ./ft_strmapi.c \
		  ./ft_putchar_fd.c \
		  ./ft_putstr_fd.c \
		  ./ft_putendl_fd.c \
		  ./ft_putnbr_fd.c \
		  ./ft_lstnew.c \
		  ./ft_lstadd_front.c \
		  ./ft_lstsize.c \
		  ./ft_lstlast.c \
		  ./ft_lstadd_back.c \
		  ./ft_lstdelone.c \
		  ./ft_lstclear.c \
		  ./ft_lstiter.c \
		  ./ft_lstmap.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -c $(SRCS)
		$(AR) $(NAME) $(OBJS)

clean:
		rm -f $(OBJS) $(OBJS2)

fclean: clean
		rm -f $(NAME)

re:		fclean all

bonus:
		$(CC) $(CFLAGS) -c $(SRCS_B)
		$(AR) $(NAME) $(OBJS2)
		$(RANLIB) $(NAME)
