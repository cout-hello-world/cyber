CFLAGS = --std=c90 -pedantic -Wall -Wextra -Werror -DNDEBUG -O3
EXE = ceaser md5_undo

%.o: %.c cyber_func.h
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(EXE)

ceaser: ceaser_main.o ceaser.o
	$(CC) -o $@ $^ $(CFLAGS)

md5_undo: md5_undo_main.o md5_undo.o
	$(CC) -o $@ $^ $(CFLAGS) -lcrypto

clean:
	$(RM) *.o $(EXE)
