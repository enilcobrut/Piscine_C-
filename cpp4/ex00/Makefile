SRC 	= 	main.cpp \
			Animal.cpp \
			Dog.cpp \
			Cat.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp 

OBJS 	=	${SRC:.cpp=.o}

NAME	=	 Animal

CC		=	c++

CFLAGS 	=	-Wall -Wextra -Werror -std=c++98# -fsanitize=address

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
