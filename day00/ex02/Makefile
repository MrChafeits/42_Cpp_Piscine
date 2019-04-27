# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: callen <callen@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 12:34:05 by callen            #+#    #+#              #
#    Updated: 2019/04/27 01:57:00 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := test

SRCS := Account.class.cpp resources/tests.cpp
OBJS := $(SRCS:.cpp=.o)

CXX	:= clang++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror
INCFLAGS := -Iresources

.PHONY: all clean fclean re debug dclean asan aclean j k rundiff

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS)  -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

rundiff: all
	./$(NAME) | awk -F' ' '{print $$2}' > /tmp/out.txt
	cat resources/19920104_091532.log | awk -F' ' '{print $$2}' > /tmp/in.txt
	diff /tmp/out.txt /tmp/in.txt || true
	rm -f /tmp/out.txt /tmp/in.txt
