SRC 	= 	main.cpp \
			ClapTrap.cpp


OBJS 	=	${SRC:.cpp=.o}

NAME	=	ClapTrap

CC		=	c++

CFLAGS 	=	-Wall -Wextra -Werror -std=c++98 #-fsanitize=address

RM	 	=	rm -f

all:	${NAME}

%.o:	%.cpp
		${CC} ${CFLAGS} -o $@ -c $<

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^

clean:
		${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean $(NAME)

.PHONY:	all clean fclean re
