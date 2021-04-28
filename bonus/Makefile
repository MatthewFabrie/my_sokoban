CC	=	gcc
CFLAGS	=	-W -Wall -Wextra
LDFLAGS	= 	-L/usr/share/doc -lncurses

SRC	=	$(wildcard *.c)
OBJ	=	$(SRC:.c=.o)

TARGET	=	my_sokoban

all	:	$(TARGET)

$(TARGET)	:	$(OBJ)
			$(CC) -o $@ $^ $(LDFLAGS)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(TARGET)

re	:	fclean all
