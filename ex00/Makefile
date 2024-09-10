NAME = btc

SRCS =  main.cpp BitcoinExchange.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp BitcoinExchange.hpp
	$(CC) $(FLAGS)  -c $< -o $@

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	
.PHONY : all clean fclean re