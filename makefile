# =============================
#   🧩 CONFIGURAÇÕES GERAIS
# =============================
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fPIE
LIBFT_DIR = libft_42
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
INC = -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)

# =============================
#   🧱 ARQUIVOS
# =============================
SRCS = src/parse_map.c src/utils.c src/flood_fill.c src/main.c src/init_game.c \
       src/parse_map_helper.c src/load_img.c src/moviment.c src/clean_all_exit.c
OBJS = $(SRCS:.c=.o)

# =============================
#   🎯 REGRAS PRINCIPAIS
# =============================
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -lX11 -lXext -lm -o $(NAME)
	@echo "✅ Compilado com sucesso!"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# =============================
#   🧹 LIMPEZA
# =============================
clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

