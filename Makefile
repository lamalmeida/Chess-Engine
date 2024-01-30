CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

chess: main.o board.o move.o util.o human.o player.o 
		$(CC) -o chess main.o board.o move.o util.o human.o player.o 

player.o: player.cpp player.hpp 
		$(CC) -c player.cpp $(CFLAGS)

human.o: human.cpp human.hpp player.hpp board.hpp 
		$(CC) -c human.cpp $(CFLAGS)

util.o: util.cpp util.hpp 
		$(CC) -c util.cpp $(CFLAGS)

move.o: move.cpp move.hpp util.hpp 
		$(CC) -c move.cpp $(CFLAGS)

board.o: board.cpp board.hpp move.hpp util.hpp 
		$(CC) -c board.cpp $(CFLAGS)

main.o: main.cpp board.hpp player.hpp human.hpp
		$(CC) -c main.cpp $(CFLAGS)

.PHONY: clean all
clean:
	rm -f *.o chess