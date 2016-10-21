CC=gcc
CFLAGS=-Wall

HEADERS = main.h game.h
OBJECTS = main.o menu.o game.o

all: microsim

microsim: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o microsim
