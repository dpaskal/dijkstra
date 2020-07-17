#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
	ifstream inFile;
	int numNodes;

	if (!(argc == 2)) {
		cerr << "Usage: ./dijkstra <input.txt>" << endl;
		exit(EXIT_FAILURE);
	}

	// Open file
	inFile.open(argv[1]);

	// First line
	inFile >> numNodes;
	cout << "numNodes = " << numNodes << endl; // debug

	// Second line
	char nodeNames[numNodes];

	for(int i=0; i < numNodes; i++) {
		inFile >> nodeNames[i];
	}
	cout << "nodeNames = " << nodeNames << endl; // debug

	// Third line and on. This is the adjacency matrix representing the graph.
	int** matrix = new int*[numNodes];
	for(int i=0; i<numNodes; ++i)
		matrix[i] = new int[numNodes];

	



	return 0;
}