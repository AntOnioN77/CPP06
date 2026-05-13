# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Archivos
SRCS = main.cpp \
	ScalarConverter.cpp \
	Print.cpp \
	ParseType.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = convert

# Reglas
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re