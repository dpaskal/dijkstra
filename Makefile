FLAGS = -std=c++14 -Wall -Wextra -pedantic -g

all: dijkstra

proxy: dijkstra.cpp
	g++ dijkstra.cpp -o dijkstra $(FLAGS)

clean:
	rm -f dijkstra
