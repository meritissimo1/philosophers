# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcrodr <marcrodr@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 17:54:46 by marcrodr          #+#    #+#              #
#    Updated: 2023/02/06 12:07:04 by marcrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	philo
CC			= 	gcc
RM			= 	rm -rf
CFLAGS		= 	-Wall -Wextra -Werror

## Main Header
INCS		= 	philo.h
INCS_DIR	= 	includes
MAIN_HEADER	= 	$(addprefix $(INCS_DIR)/, $(INCS))

##includes
INC_FLAGS	= 	-I $(INCS_DIR)

## Source Code
SRCS_DIR	= 	./src
MAIN_SRC	= 	main.c

## Utils
UTILS_DIR	= 	utils
UTILS_SRC	= 	check_args.c utils.c time.c

## Init
INIT_DIR	= 	init
INIT_SRC	= 	init.c

## Parse
PARSER_DIR	= 	parse
PARSER_SRC	= 	parser.c

## Actions
ACTION_DIR	= 	actions
ACTION_SRC	= 	dinner.c action.c

## Routine
ROUTINE_DIR	= 	routine
ROUTINE_SRC	=	routine.c eating.c sleeping.c thinking.c

## Exit
EXIT_DIR	=	exit
EXIT_SRC	=	exit.c

SRCS		=	$(MAIN_SRC) \
				$(addprefix $(UTILS_DIR)/, $(UTILS_SRC)) \
				$(addprefix $(INIT_DIR)/, $(INIT_SRC)) \
				$(addprefix $(PARSER_DIR)/, $(PARSER_SRC)) \
				$(addprefix $(ACTION_DIR)/, $(ACTION_SRC)) \
				$(addprefix $(ROUTINE_DIR)/, $(ROUTINE_SRC)) \
				$(addprefix $(EXIT_DIR)/, $(EXIT_SRC))

SRCS_PATH	= 	$(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS_DIR	= 	./objs
OBJS		=	 $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DIR_OBJS	= 	mkdir -p $(@D)

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
	gdb --tui --args ./$@ 2 1 4 2
	$(RM) debug

git: fclean
	git add -A
	git status	

.PHONY: re fclean clean all
