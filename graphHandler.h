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
 * Create a graph from a file (creation of adjacency matrix of a directed weighted graph)
 * if edge doesnt exist, we set to INF the value to consider weight = 0
 * @return A n by n matrix (n the number of vertices)
 */
GRAPH* createGraphFromFile(char* fileName);

/**
 * Display the "adjacency matrix" of the graph
 */
void displayMatrix(int** matrix, int nbVertices);

void freeGraph(GRAPH* graph);

void freeMatrix(int** matrix, int n);

#endif //SHORTESTPATH_GRAPHHANDLER_H
