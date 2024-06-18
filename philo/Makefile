NAME = philo

SRCS = philo_utils.c \
		my_malloc.c \
		ft_init.c \
		actions.c \
		philo_utils2.c \
		main.c \
		philo_utils3.c \
		pacer.c \
		philotr.c \
		ft_timer.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra  -fsanitize=thread #-fsanitize=address

CC = gcc

all: $(NAME) philo.h

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
