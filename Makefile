# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 17:25:58 by jpedro-f          #+#    #+#              #
#    Updated: 2025/10/18 18:41:57 by jpedro-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  COLORS                                      #
#==============================================================================#
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"  
YELLOW		= "\033[0;33m" 
RESET		= "\033[0m"

#==============================================================================#
#                                NAMES & PATHS                                 #
#==============================================================================#

NAME = cub3d

HEADER_PATH = ./includes/cub3d.h

LIBFT_DIR = ./includes/libft
LIBFT = ./includes/libft/libft.a

MLX_DIR = ./minilibx
MLX = ./minilibx/minilibx.a

SRCS_DIR = ./srcs/
SRCS =	$(addprefix $(SRCS_DIR), 	main.c \
									init.c \
									hooks.c \
									render.c \
									draw.c)

OBJS = $(SRCS:.c=.o)

#==============================================================================#
#                            FLAGS & COMMANDS                                  #
#==============================================================================#

C_COMP = cc

CFLAGS = -Wall -Werror -Wextra -g

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

RM = rm -f

AR = ar rcs

MAKE = make

#==============================================================================#
#                               RULES & DEPS                                   #
#==============================================================================#

all: $(MLX) $(LIBFT) $(NAME)

%.o: $(SRCS_DIR)%.c
	$(C_COMP) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
	echo $(YELLOW) "Cloning MiniLibX..." $(RESET); \
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	@$(C_COMP) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo $(GREEN) "$(NAME) was created successfully!" $(RESET)

#==============================================================================#
#                                  CLEAN RULES                                 #
#==============================================================================#


valgrind:
	@echo $(YELLOW) "[!] Running $(NAME) with Valgrind..." $(RESET)
	/usr/bin/valgrind --track-fds=yes --leak-check=full -s --show-leak-kinds=all ./$(NAME)

clean:
	@$(RM) $(OBJS)
	@echo $(RED) "All .o files were deleted!" $(RESET)

fclean: clean
	@$(RM) $(NAME)
	@echo $(RED) "$(NAME) was deleted!" $(RESET)

fcleanall: clean fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -rf $(MLX_DIR)
	@clear
	@echo $(RED)"-> $(NAME), .o files, mlx and libft removed"$(RESET)


re: fclean all

.PHONY: all clean fclean re cleanall fcleanall