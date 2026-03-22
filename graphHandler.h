#ifndef SHORTESTPATH_GRAPHHANDLER_H
#define SHORTESTPATH_GRAPHHANDLER_H

/**
 * Creation of graph structure
 * nbVertices is the number of vertices in the graph
 * nbArcs is the number of edges
 * matrix is the matrix of size nbVertices by nbVertices that contain the weight of the edges
 * arcs is the matrix of size nbArcs by 3 containing any edge in the graph such that we have, in the first column the starting vertex, in the second column the end vertex and in the third column the weight
 */
struct graph{
    int nbVertices;
    int nbArcs;
    int** matrix;
    int** arcs;
};
typedef struct graph GRAPH;

/**
 * Create the graph
 * @param nbVertices is the number of vertices in the graph
 * @param nbArcs is the number of edges in the graph
 * @return the graph created
 */
GRAPH* createGraph(int nbVertices, int nbArcs);

/**
 * Create a graph from a file (creation of adjacency matrix of a directed weighted graph)
 * if edge doesnt exist, we set to INF the value to consider weight = 0
 * @param fileName is the name of the file where we extract the graph
 * @return A n by n matrix (n the number of vertices)
 */
GRAPH* createGraphFromFile(char* fileName);

/**
 * Display the "adjacency matrix" of the graph
 * @param matrix is the adjacency matrix
 * @param nbVertices is the size of the matrix
 */
void displayMatrix(int** matrix, int nbVertices);

/**
 * Free the memory allocation for the graph to ensure no memory leak
 * @param graph is a pointer to the graph that need to be freed
 */
void freeGraph(GRAPH* graph);

/**
 * Free any matrix given to ensure no memory leak
 * @param matrix is the matrix to be freed
 * @param n size of the matrix
 */
void freeMatrix(int** matrix, int n);

#endif //SHORTESTPATH_GRAPHHANDLER_H
