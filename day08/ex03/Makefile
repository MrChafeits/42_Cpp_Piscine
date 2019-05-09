# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: callen <callen@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 12:34:05 by callen            #+#    #+#              #
#    Updated: 2019/05/09 12:36:55 by callen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := galacticNoggin.out
DNAME := d_$(NAME)
ANAME := a_$(NAME)

SRCS := main.cpp Instruction.cpp

OBJS := $(SRCS:.cpp=.o)

CXX	:= clang++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -pipe
DBGFLAGS := -std=c++98 -Wall -Wextra -g -pipe -fno-omit-frame-pointer
ASNFLAGS := $(DBGFLAGS) -fsanitize=address
INCFLAGS := -I.

.PHONY: all clean fclean re debug dclean j k asan aclean fast

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

fast:
	$(CXX) $(CXXFLAGS) -O2 $(INCFLAGS) -o $(NAME) $(SRCS)

debug:
	$(CXX) $(DBGFLAGS) $(INCFLAGS) -o $(DNAME) $(SRCS)

dclean:
	$(RM) -r $(DNAME) $(DNAME).dSYM

asan:
	$(CXX) $(ASNFLAGS) $(INCFLAGS) -o $(ANAME) $(SRCS)

aclean:
	$(RM)-r $(ANAME) $(ANAME).dSYM

j: debug

k: dclean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
