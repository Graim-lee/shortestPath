#ifndef SHORTESTPATH_GRAPHHANDLER_H
#define SHORTESTPATH_GRAPHHANDLER_H

/**
 * Creation of graph structure
 */
struct graph{
    int nbVertices;
    int nbArcs;
    int** matrix;
    int** arcs;
};
typedef struct graph GRAPH;

GRAPH* createGraph(int nbVertices, int nbArcs);

/**
 * Create a graph from a file
 * @return A n by n matrix (n the number of vertices)
 */
GRAPH* createGraphFromFile(char* fileName);

/**
 * Display the "adjacency matrix" of the graph
 */
void displayMatrix(int** matrix, int nbVertices);


#endif //SHORTESTPATH_GRAPHHANDLER_H
