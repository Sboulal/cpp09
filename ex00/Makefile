NAME = btc

SRCS =  main.cpp  

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp 
	$(CC) $(FLAGS)  -c $< -o $@

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	
.PHONY : all clean fclean re