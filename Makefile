NAME = philo

SRCS = modules/actions.c  modules/ft_timer.c  modules/my_malloc.c \
		 modules/philotr.c  modules/lunch.c   modules/pacer.c \
		 modules/philotr.c  modules/lunch.c   modulesft_init.c \
		 src/main.c \


OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra  -fsanitize=thread #-fsanitize=address

CC = gcc

all: $(NAME) include/philo.h

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
