
INCLUDES= -IPP6Lib
CFLAGS= -Wall -Werror -Wshadow -Wextra -O3
CC= g++


ex1: ex1.cpp PP6Lib/PP6Math.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES)

.phony: clean

clean:
	rm -f ex1
