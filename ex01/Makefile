SRCS		= main.cpp RPN.cpp

OBJS		= ${SRCS:.cpp=.o}

RM			= rm -f

NAME		= RPN

FLAGS		= -Wall -Wextra -Werror -std=c++98

CC			= g++

.cpp.o:
			${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
