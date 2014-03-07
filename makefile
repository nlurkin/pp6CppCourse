

CFLAGS= -Wall -Werror -Wshadow -Wextra -O3
CC= g++


ex1: ex1.cpp
	$(CC) $(CFLAGS) -o $@ $<

.phony: clean

clean:
	rm -f ex1
