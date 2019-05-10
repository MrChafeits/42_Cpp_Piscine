NAME := ft_gkrellm
DNAME := d_$(NAME)
ANAME := a_$(NAME)

CXX	:= clang++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -pipe
DBGFLAGS := -std=c++98 -Wall -Wextra -g -pipe
ASNFLAGS := $(DBGFLAGS) -fsanitize=address

OBJDIR := .obj
DBGDIR := .dbg
ASNDIR := .asn

SRCDIR := src
INCDIR := src

INCFLAGS := -I$(INCDIR)
LDFLAGS := -lncurses

SRCS := main.cpp

OBJS := $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
DBGS := $(addprefix $(DBGDIR)/, $(SRCS:.cpp=.o))
ASNS := $(addprefix $(ASNDIR)/, $(SRCS:.cpp=.o))

.PHONY: all clean fclean re debug dclean j k asan aclean f d

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR):
	mkdir -p $@

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.cpp)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -o $@ $<

debug: $(DBGDIR) $(DBGS)
	$(CXX) $(LDFLAGS) -o $(DNAME) $(DBGS)

$(DBGDIR):
	mkdir -p $@

$(addprefix $(DBGDIR)/, %.o): $(addprefix $(SRCDIR)/, %.cpp)
	$(CXX) $(DBGFLAGS) $(INCFLAGS) -c -o $@ $<

dclean:
	rm -rf $(DNAME) $(DNAME).dSYM $(DBGDIR)

asan: $(ASNDIR) $(ASNS)
	$(CXX) $(LDFLAGS) -o $(ANAME) $(ASNS)

$(ASNDIR):
	mkdir -p $@

$(addprefix $(ASNDIR)/, %.o): $(addprefix $(SRCDIR)/, %.cpp)
	$(CXX) $(ASNFLAGS) $(INCFLAGS) -c -o $@ $<

aclean:
	rm -rf $(ANAME) $(ANAME).dSYM $(ASNDIR)

j: debug

k: dclean

f: asan

d: aclean

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
