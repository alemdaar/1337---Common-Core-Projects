NAME = library.a

CC = cc

AR = ar rc

SRC = mandatory/functions1.c mandatory/functions2.c mandatory/functions3.c mandatory/functions4.c mandatory/functions5.c mandatory/functions6.c \
    	mandatory/functions7.c mandatory/functions8.c mandatory/functions9.c mandatory/functions10.c mandatory/functions11.c mandatory/functions12.c

BONUS_SRC = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c operation_bonus.c operation2_bonus.c operation3_bonus.c \
			operation4_bonus.c operation5_bonus.c operation6_bonus.c operation7_bonus.c operation8_bonus.c

OBJ = ${SRC:.c=.o}

BONUS_OBJ = ${BONUS_SRC:.c=.o}

MAIN = mandatory/push_swap.c

BONUS_MAIN = checker_bonus.c

MAIN_O = push_swap

BONUS_MAIN_O = checker

CFLAGS = -Wall -Wextra -Werror


all: mandatory

mandatory: ${OBJ} exec1
	${CC} $(MAIN) -L. -lrary -o $(MAIN_O)

exec1:
	${AR} ${NAME} ${OBJ}

bonus: ${BONUS_OBJ}
	${AR} ${NAME} ${BONUS_OBJ}
	${CC} $(BONUS_MAIN) -L. -lrary -o $(BONUS_MAIN_O)

%.o: %.c mandatory/header.h checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ${OBJ} ${BONUS_OBJ}

fclean : clean 
	rm -f ${NAME} $(MAIN_O) $(BONUS_MAIN_O)

re: fclean all