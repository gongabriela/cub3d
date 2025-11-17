# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 17:25:58 by jpedro-f          #+#    #+#              #
#    Updated: 2025/11/17 11:45:06 by ggoncalv         ###   ########.fr        #
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

NAME = cub3D

HEADER_PATH = ./includes/cub3d.h

LIBFT_DIR = ./includes/libft
LIBFT = ./includes/libft/libft.a

MLX_DIR = ./minilibx
MLX = ./minilibx/minilibx.a

SRCS_DIR = ./srcs/
SRCS =	$(addprefix $(SRCS_DIR), 	main.c \
									free.c \
									init.c \
									hooks.c \
									ray_casting.c \
									draw_utils.c \
									draw_3d.c \
									player_utils.c \
									debug_2d.c \
									debug_draw.c \
									parser.c \
									parser_utils.c \
									parser_textures.c \
									parser_colors.c \
									pre_parser_map.c \
									ff_matrix.c \
									parser_map.c )

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

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(C_COMP) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)
	@echo $(GREEN) "$(NAME) was created successfully!" $(RESET)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@touch $(LIBFT)

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo $(YELLOW) "Cloning MiniLibX..." $(RESET); \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)
	@touch $(MLX)


#==============================================================================#
#                                  CLEAN RULES                                 #
#==============================================================================#


valgrind:
	@echo $(YELLOW) "[!] Running $(NAME) with Valgrind..." $(RESET)
	/usr/bin/valgrind --track-fds=yes --leak-check=full -s --show-leak-kinds=all ./$(NAME)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo $(RED) "All .o files were deleted!" $(RESET)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo $(RED) "$(NAME) was deleted!" $(RESET)

fcleanall: clean fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -rf $(MLX_DIR)
	@clear
	@echo $(RED)"-> $(NAME), .o files, mlx and libft removed"$(RESET)

re: fclean $(NAME)

.PHONY: all clean fclean re cleanall fcleanall