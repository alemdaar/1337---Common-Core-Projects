NAME = libftprintf.a

CC = cc

SRCS = ft_pchar.c ft_phex.c ft_pnbr.c \
		ft_pptr.c ft_printf.c ft_pstr.c ft_punsigned.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all