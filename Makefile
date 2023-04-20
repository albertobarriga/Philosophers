NAME = philo

CC = gcc

CFLAGS = -Werror -Wextra -Wall -g -I -pthread

SRCS = main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)