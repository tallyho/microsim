CC=gcc
CFLAGS=-Wall

HEADERS =
OBJECTS = main.o

all: microsim

microsim: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o microsim
