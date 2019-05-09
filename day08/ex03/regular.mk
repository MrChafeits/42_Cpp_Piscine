# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    regular.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: callen <callen@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 12:34:05 by callen            #+#    #+#              #
#    Updated: 2019/05/08 21:20:18 by callen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := discordantSynth.out

SRCS := main.cpp \
		RightAngleBracket.cpp \
		LeftAngleBracket.cpp \
		AdditionSymbol.cpp \
		FullWidthHyphen.cpp \
		FullStop.cpp \
		AntiApostrophe.cpp \
		OpenSquareBracket.cpp \
		CloseSquareBracket.cpp

OBJS := $(SRCS:.cpp=.o)

CXX	:= clang++
CXXFLAGS := -Wall -Wextra -Werror -pipe
INCFLAGS := -I.

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
