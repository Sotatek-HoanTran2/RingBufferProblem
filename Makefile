CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -pthread
LIBNAME = libringbuffer.a
SRCS = ringbuffer.c
OBJS = ringbuffer.o

.PHONY: all clean

all: $(LIBNAME) example

$(LIBNAME): $(SRCS)
	$(CC) $(CFLAGS) -c ringbuffer.c -o ringbuffer.o
	$(AR) rcs $(LIBNAME) ringbuffer.o

example: main.c $(LIBNAME)
	$(CC) $(CFLAGS) -o example main.c $(LIBNAME)

clean:
	rm -f $(OBJS) $(LIBNAME) example
