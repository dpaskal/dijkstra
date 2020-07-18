#include <iostream>
#include <fstream>

using namespace std;

// Helper function for pretty printing adjacency matrix
void prettyPrint(int numNodes, char* nodeNames, int** matrix) {
	char tab = '\t';
	cout << "Adjacency matrix: " << endl;
	cout << endl;
	cout << tab;
	for(int i=0; i<numNodes; ++i)
		cout << nodeNames[i] << tab;
	cout << endl << endl;

	for(int i=0; i<numNodes; ++i) {
		cout << nodeNames[i] << tab;
		for(int j=0; j<numNodes; ++j) {
			cout << matrix[i][j] << tab;
		}
		cout << endl << endl;

	}
}

int main(int argc, char **argv) {
	char startNode;
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

	// Initialize the matrix from input file
	for(int i=0; i<numNodes; ++i) {
		for(int j=0; j<numNodes; ++j) {
			inFile >> matrix[i][j];
		}
	}

	// Debug print the matrix
	// for(int i=0; i<numNodes; ++i) {
	// 	for(int j=0; j<numNodes; ++j) {
	// 		cout << matrix[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	prettyPrint(numNodes, nodeNames, matrix);


	// Read an input from the user regarding the starting node
	cout << "Which of these nodes should we start at: ";
	for(int i=0; i<numNodes; i++)
		cout << nodeNames[i] << ' ';
	cout << "? ";
	cin >> startNode;

	// Verify the input is valid
	bool found = false;
	for(int i=0; i<numNodes; i++)
		if(startNode == nodeNames[i])
			found = true;

	if(!found) {
		cerr << "input value is not a valid node" << endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}


