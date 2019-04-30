# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: callen <callen@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 12:34:05 by callen            #+#    #+#              #
#    Updated: 2019/04/29 16:56:53 by callen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := horde.out
DNAME := d_$(NAME)
ANAME := a_$(NAME)

SRCS := Zombie.cpp ZombieHorde.cpp main.cpp
OBJS := $(SRCS:.cpp=.o)

CXX	:= clang++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -pipe
DBGFLAGS := -std=c++98 -Wall -Wextra -g -pipe
ASNFLAGS := $(DBGFLAGS) -fsanitize=address
INCFLAGS := -I.

.PHONY: all clean fclean re debug dclean asan aclean j k

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

debug:
	$(CXX) $(DBGFLAGS) $(INCFLAGS) -o $(DNAME) $(SRCS)

dclean:
	rm -rf $(DNAME) $(DNAME).dSYM

asan:
	$(CXX) $(ASNFLAGS) $(INCFLAGS) -o $(ANAME) $(SRCS)

aclean:
	rm -rf $(ANAME) $(ANAME).dSYM

j: debug

k: dclean

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
