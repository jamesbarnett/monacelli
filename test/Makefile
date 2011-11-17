CC = clang++
CFLAGS = -g -Wall -std=c++0x -I/usr/local/include
LDFLAGS = 

all : score_game_test

score_game_test : score_game_test.cpp
	$(CC) $(CFLAGS) score_game_test.cpp $(LDFLAGS) -o score_game_test

clean :
	rm score_game_test
