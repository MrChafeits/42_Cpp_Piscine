# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: callen <callen@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 12:34:05 by callen            #+#    #+#              #
#    Updated: 2019/04/29 11:48:56 by callen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := a.out

SRCS := Account.class.cpp \
		resources/tests.cpp

OBJS := $(SRCS:.cpp=.o)

CXX	:= clang++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror
INCFLAGS := -Iresources

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME) | awk -F' ' '{print $$2}' > /tmp/out.txt
	cat resources/19920104_091532.log | awk -F' ' '{print $$2}' > /tmp/in.txt
	diff /tmp/out.txt /tmp/in.txt
	rm -f /tmp/out.txt /tmp/in.txt
