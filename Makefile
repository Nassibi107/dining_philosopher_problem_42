NAME = philo

SRCS = modules/actions.c  modules/ft_timer.c  modules/my_malloc.c \
		 modules/philotr.c    modules/pacer.c modules/ft_init.c   modules/lunch.c  \
		 modules/ft_atoi.c  src/main.c modules/ft_tools_routine.c


OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra  -fsanitize=thread

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
