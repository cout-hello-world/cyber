CFLAGS = --std=c90 -pedantic -Wall -Wextra -Werror -DNDEBUG -O3

%.o: %.c cyber_func.h
	$(CC) -c -o $@ $< $(CFLAGS)

ceaser: ceaser_main.o ceaser.o
	$(CC) -o $@ $^ $(CFLAGS)
