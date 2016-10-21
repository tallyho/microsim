CC=gcc
CFLAGS=-Wall

HEADERS = main.h game.h product.h employee.h
OBJECTS = main.o menu.o game.o product.o employee.o

all: microsim

microsim: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o microsim
