NAME = philo

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g -I -pthread -fsanitize=thread

# THREAD_FLAG = -g -I -pthread

RM = rm -f

SRCS =	main.c\
		utils.c\
		structs.c\
		routine.c

OBJS = $(SRCS:.c=.o)



$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "$(NAME) compiled"

all : $(NAME)

clean:
	echo "remove files"
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean all