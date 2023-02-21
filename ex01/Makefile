SRCS		= 

OBJS		= ${SRCS:.cpp=.o}

RM			= rm -f

NAME		= megaphone

FLAGS		= -Wall -Wextra -Werror -std=c++98

CC			= g++-11

.cpp.o:
			${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

#${NAME}:
#			${CC} ${FLAGS} ${SRCS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
