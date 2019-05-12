NAME := ft_retro
DNAME := d_$(NAME)
ANAME := a_$(NAME)

CXX	:= g++-9
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror -pipe
DBGFLAGS := -std=c++98 -Wall -Wextra -g -pipe
ASNFLAGS := $(DBGFLAGS) -fsanitize=address

OBJDIR := .obj/
DBGDIR := .dbg/
ASNDIR := .asn/

SRCDIR := src/
INCDIR := include/

INCFLAGS := -I$(INCDIR)
LIBFLAGS := -lncurses

FILES := main Game Pixel Player Sprite Timer AObj Basher AEnemy Random Shooter Bullet Laser BigO

SRCS := $(addsuffix .cpp, $(FILES))
OBJS := $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))
DBGS := $(addprefix $(DBGDIR), $(SRCS:.cpp=.o))
ASNS := $(addprefix $(ASNDIR), $(SRCS:.cpp=.o))

.PHONY: all clean fclean re debug dclean asan aclean j k

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR):
	mkdir -p $@

$(addprefix $(OBJDIR), %.o): $(addprefix $(SRCDIR), %.cpp)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c -o $@ $<

debug: $(DBGDIR) $(DBGS)
	$(CXX) $(DBGFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $(DNAME) $(DBGS)

$(DBGDIR):
	mkdir -p $@

$(addprefix $(DBGDIR), %.o): $(addprefix $(SRCDIR), %.cpp)
	$(CXX) $(DBGFLAGS) $(INCFLAGS) -c -o $@ $<

dclean:
	rm -rf $(DNAME) $(DNAME).dSYM $(DBGDIR)

asan: $(ASNDIR) $(ASNS)
	$(CXX) $(ASNFLAGS) $(INCFLAGS) $(LIBFLAGS) -o $(ANAME) $(ASNS)

$(ASNDIR):
	mkdir -p $@

$(addprefix $(ASNDIR), %.o): $(addprefix $(SRCDIR), %.cpp)
	$(CXX) $(ASNFLAGS) $(INCFLAGS) -c -o $@ $<

aclean:
	rm -rf $(ANAME) $(ANAME).dSYM $(ASNDIR)

j: debug

k: dclean

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
