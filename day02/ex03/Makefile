# ioccc2018:anderson
CXX := g++-9
CXXFLAGS := -Wall -Wextra -Werror
.PHONY: all clean fclean re
all: main.o
	$(CXX) $(CXXFLAGS) main.cpp
	./a.out < main.cpp

clean:
	rm -f main.o

fclean: clean
	rm -f a.out

re: fclean all
