# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 02:18:30 by liguyon           #+#    #+#              #
#    Updated: 2023/06/06 03:30:17 by liguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output
NAME		:= liballocators.a

# Includes
INC_DIR		:= include

# Sources
SRC_DIR		:= src

SRC			:= arena/arena.c \
				arena/arena_alloc.c \


# Objects
OBJ_DIR		:= .build

OBJ			:= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Compiler
CC			:= cc

CFLAGS		:= -Wall -Wextra -Werror -I $(INC_DIR)

# Archive
AR			:= ar rcs

# Logging
SUCCESS_COLOR	= \033[0;32m
ERROR_COLOR		= \033[0;31m
RESET_COLOR		= \033[0m
COMPILE_MSG		= "Compiling target: "
SUCCESS_MSG		= "Compilation successful: "

# Targets
$(NAME):	$(OBJ)
		@echo "$(COMPILE_MSG)$(NAME)"
		@$(AR) $@ $^
		@ranlib $@
		@echo "$(SUCCESS_COLOR)$(SUCCESS_MSG)$(NAME)$(RESET_COLOR)"

all:	$(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -o $@ -c $<

clean:
		@echo "Cleaning up..."
		@rm -rf $(OBJ_DIR)
		@echo "$(SUCCESS_COLOR)Done$(RESET_COLOR)"

fclean:	clean
		@rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
