# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 02:18:30 by liguyon           #+#    #+#              #
#    Updated: 2023/06/20 14:26:24 by liguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output
NAME		:= liballocators.a

# Includes
INC_DIR		:= src

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

# Targets
$(NAME):	$(OBJ)
		$(AR) $@ $^
		ranlib $@

all:	$(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
		@rm -rf $(OBJ_DIR)

fclean:	clean
		@rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
