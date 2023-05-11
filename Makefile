CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c
OBJECTS = $(SRCS:.c=.o)
INC = -I./
ARRCS = ar rcsu
RMF = rm -f

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(ARRCS) $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< $(INC)

clean :
	$(RMF) $(OBJECTS) $(BNSOBJECTS)

fclean : clean
	$(RMF) $(NAME) 

re : fclean all

.PHONY : claen fclaen all re bonus