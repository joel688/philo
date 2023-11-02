NAME		=	philo

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -pthread

SRCS		=	main.c \
				algo.c \
				threads.c \
				parse_init.c \
				utils_philo.c \
				utils.c \
				ft_atoi.c\
				check_param.c\

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all
