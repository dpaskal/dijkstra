#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
	if (!(argc == 2)) {
		cerr << "Usage: ./dijkstra <input.txt>" << endl;
		exit(EXIT_FAILURE);
	}

	if (!ifstream(argv[1])) {
		cerr << "error opening input.txt" << endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}