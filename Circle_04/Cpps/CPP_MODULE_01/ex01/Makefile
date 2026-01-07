NAME = Moar_brainz

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Makefile main.cpp Zombie.cpp Zombie.hpp zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
