OS := $(shell uname -s | tr A-Z a-z)

NAME := cub3D

CC := cc
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -O3

LIBMLX := lib/mlx42
LIBFT := lib/libft/libft.a
LIBS := $(LIBMLX)/build/libmlx42.a $(LIBFT)

# GLFW & system libs
ifeq ($(OS), linux)
    LIBS += -ldl -lglfw -pthread -lm
else
    GLFW_PREFIX := $(shell brew --prefix glfw)
    LIBS += -framework Cocoa -framework OpenGL -framework IOKit \
            $(GLFW_PREFIX)/lib/libglfw3.a
endif

# Includes
INCLUDES := -I./src -I$(LIBMLX)/include -Ilib/libft

HDR := ./src/mandatory/main.h lib/gnl/get_next_line.h src/mandatory/parse/parse.h
SRCS := ./src/mandatory/gfx.c ./src/mandatory/hooks.c ./src/mandatory/main.c ./src/mandatory/move.c \
		./src/mandatory/rotate.c \
		./lib/gnl/get_next_line.c ./lib/gnl/get_next_line_utils.c \
		./src/mandatory/parse/checks.c ./src/mandatory/parse/color_checks.c ./src/mandatory/parse/helper.c \
		./src/mandatory/parse/helper2.c ./src/mandatory/parse/parse.c \
		./src/mandatory/parse/parse2.c ./src/mandatory/parse/parse3.c ./src/mandatory/parse/player_stuff.c \
		./src/mandatory/helper.c ./src/mandatory/rays.c ./src/mandatory/rays2.c \
		./src/mandatory/move_hor.c ./src/mandatory/move_ver.c
OBJS := $(SRCS:.c=.o)
HDRB := ./src/bonus/main_bonus.h lib/gnl/get_next_line.h src/bonus/parse/parse_bonus.h
SRCSB := ./src/bonus/draw_bonus.c ./src/bonus/gfx_bonus.c ./src/bonus/hooks_bonus.c ./src/bonus/main_bonus.c ./src/bonus/move_bonus.c \
		./src/bonus/rotate_bonus.c \
		./lib/gnl/get_next_line.c ./lib/gnl/get_next_line_utils.c \
		./src/bonus/parse/checks_bonus.c ./src/bonus/parse/color_checks_bonus.c ./src/bonus/parse/helper_bonus.c \
		./src/bonus/parse/helper2_bonus.c ./src/bonus/parse/parse_bonus.c \
		./src/bonus/parse/parse2_bonus.c ./src/bonus/parse/parse3_bonus.c ./src/bonus/parse/player_stuff_bonus.c \
		./src/bonus/helper_bonus.c ./src/bonus/rays_bonus.c ./src/bonus/rays2_bonus.c \
		./src/bonus/mouse_bonus.c ./src/bonus/draw2_bonus.c   \
		./src/bonus/move_hor_bonus.c ./src/bonus/move_ver_bonus.c \
		./src/bonus/hand_bonus.c
OBJSB := $(SRCSB:.c=.o)

all: $(NAME)

# Clone MLX42
clone_mlx42:
	@git clone --depth=1 https://github.com/codam-coding-college/MLX42.git lib/mlx42

# Build MLX42
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j6

# Build libft
$(LIBFT):
	@make -C lib/libft

# Build object files
%.o: %.c $(HDR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build final binary
$(NAME): libmlx $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

bonus: libmlx $(LIBFT) $(OBJSB)
	$(CC) $(OBJSB) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJS) $(OBJSB)
	@make -C lib/libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C lib/libft fclean

re: fclean all

.PHONY: all clean fclean re libmlx clone_mlx42
