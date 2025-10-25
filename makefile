# =============================
#   🧩 CONFIGURAÇÕES GERAIS
# =============================
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fPIE
LIBFT_DIR = lib
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = mlx
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

# Compilar libft
$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

# Compilar executável
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -lX11 -lXext -lm -o $(NAME)
	@echo "✅ Compilado com sucesso!"

# Compilar arquivos .c para .o
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

