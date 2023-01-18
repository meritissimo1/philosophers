# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 17:54:46 by marcrodr          #+#    #+#              #
#    Updated: 2023/01/18 19:10:34 by marcrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror

## Main Header
INCS		= philo.h
INCS_DIR	= includes
MAIN_HEADER	= $(addprefix $(INCS_DIR)/, $(INCS))

##includes
INC_FLAGS	= -I $(INCS_DIR)

## Source Code
SRCS_DIR	= ./src
MAIN_SRC	= main.c

SRCS		=	$(MAIN_SRC)

OBJS_DIR	= ./objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DIR_OBJS	= mkdir -p $(@D)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(DIR_OBJS)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -pthread $(INC_FLAGS) $(OBJS) -o  $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) debug
	
re: fclean all

debug:
	$(CC) -g $(CFLAGS) -pthread $(INC_FLAGS) -o $@
	gdb --tui ./$@

.PHONY: re fclean clean all
