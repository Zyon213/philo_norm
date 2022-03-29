SRC = create.c init.c join.c main.c time.c utils.c

all:
	gcc -pthread -lpthread $(SRC) -o philo
add:
	gcc -pthread -lpthread -g -fsanitize=address $(SRC) -o philo
thr:
	gcc -pthread -lpthread -g -fsanitize=thread $(SRC) -o philo
clean:
	rm -f philo
