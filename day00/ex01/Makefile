# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: callen <callen@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 12:34:05 by callen            #+#    #+#              #
#    Updated: 2019/04/29 11:45:15 by callen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := phonebook

SRCS := PhoneBook.cpp main.cpp
OBJS := $(SRCS:.cpp=.o)

CXX	:= g++-9
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -pipe
INCFLAGS := -I.

# Note: the '-pipe' compiler flag speeds up compilation time and in the rare
#       event that the NFS becomes full, allows for recompilation by using unix
#       pipes instead of intermediate files for compilation

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
