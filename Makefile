# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 17:54:46 by marcrodr          #+#    #+#              #
#    Updated: 2023/01/30 15:31:32 by marcrodr         ###   ########.fr        #
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

## Utils
UTILS_DIR	= utils
UTILS_SRC	= check_args.c utils.c

## Init
INIT_DIR	= init
INIT_SRC	= init.c

SRCS		=	$(MAIN_SRC) \
				$(addprefix $(UTILS_DIR)/, $(UTILS_SRC)) \
				$(addprefix $(INIT_DIR)/, $(INIT_SRC))

SRCS_PATH	= $(addprefix $(SRCS_DIR)/, $(SRCS))

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
	$(CC) -g $(CFLAGS) -pthread $(INC_FLAGS) $(SRCS_PATH) -o $@
	gdb --tui --args ./$@ 100 1 4 2
	$(RM) debug

.PHONY: re fclean clean all
