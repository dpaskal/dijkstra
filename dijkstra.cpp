#include <iostream>
#include <fstream>

using namespace std;

// Helper function for pretty printing adjacency matrix
void prettyMatrix(int numNodes, char* nodeNames, int** matrix) {
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

//Helper function for pretty printing result table
void prettyTable(int numNodes, char* nodeNames, int** matrix) {
	char tab = '\t';
	cout << "Result table:" << endl << endl;

	cout << "N'" << tab << tab;
	for(int i=0; i<numNodes; i++) {
		cout << "D(" << nodeNames[i] << "),p(" << nodeNames[i] << ")" << tab;
	}
	cout << endl;

	int counter = numNodes;
	for(int i=0; i<numNodes; i++) {
		for(int z=0; z <= i; z++) {
			cout << nodeNames[z];
		}
		cout << tab;
		for(int j=0; j<numNodes; j++) {
			;
		}
		cout << endl;
	}
}


// Helper function to calculate the minimum distance for a node
// Returns the index of the shortest path
int minimumDistance(int* dist, bool* visited, int numNodes) {
	int min = INT32_MAX;
	int index;

	for(int i=0; i < numNodes; i++) {
		if(visited[i] == false && dist[i] <= min) {
			min=dist[i];
			index=i;
		}
	}
	return index;
}


// Function to run the algorithm
void dijkstra(int** matrix, int numNodes, int startIndex) {
	int dist[numNodes]; // Array for calculating minimum distance for each node
	bool visited[numNodes]; // Array for marking visited nodes
	
	// Initialize arrays
	for(int i=0; i<numNodes; ++i) {
		dist[i] = INT32_MAX;
		visited[i] = false;
	}

	dist[startIndex] = 0; // Set start point to 0

	for(int i=0; i<numNodes; ++i) {
		int minDist = minimumDistance(dist, visited, numNodes);
		visited[minDist] = true;
		for(int j=0; j<numNodes; ++j) {
			if(!visited[i] && matrix[minDist][j] && dist[minDist] != INT32_MAX && dist[minDist] + matrix[minDist][j] < dist[i]) {
				dist[i] = dist[minDist] + matrix[minDist][i];
			}
		}
	}


}

int main(int argc, char **argv) {
	char startNode;
	ifstream inFile;
	int numNodes, startIndex;

	if (argc != 2) {
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
	prettyMatrix(numNodes, nodeNames, matrix);


	// Read an input from the user regarding the starting node
	cout << "Enter starting node:" << endl;
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
	
	// Get the start index given the inputed startNode
	for(int i=0; i<numNodes; ++i) {
		if( nodeNames[i] == startNode ) {
			startIndex = i;
		}
	}

	dijkstra(matrix, numNodes, startIndex);
	// Result table
	prettyTable(numNodes, nodeNames, matrix);

	return 0;
}


