##
## EPITECH PROJECT, 2018
## arcade
## File description:
## main makefile
##

CDIR		=	Srcs
SRCS		=	$(CDIR)/Main.cpp

##   FileSystem   ##
#CDIR_FILESYS=	/FileSystem
#SRCS		+=	$(CDIR)$(CDIR_FILESYS)/Path.cpp
#SRCS		+=	$(CDIR)$(CDIR_FILESYS)/File.cpp
#SRCS		+=	$(CDIR)$(CDIR_FILESYS)/Directory.cpp
#CIFLAGS 	=	-I./Includes/FileSystem


OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++ -std=c++17
CIFLAGS		+=	-I./Includes
CXXFLAGS	=	-Werror -Wall -Wextra
CXXFLAGS	+= 	$(CIFLAGS)
LDFLAGS		=	$(CIFLAGS) -lpthread

NAME	=	bomberman

RM	=	rm -f

all: $(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug:CXXFLAGS = $(CIFLAGS) -W -Wall -g -g3
debug: re

.PHONY: all clean fclean re debug
