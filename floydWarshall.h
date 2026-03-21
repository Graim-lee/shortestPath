#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include "graphHandler.h"

#define INF 99999

/**
 * Implementation of the floydWarshall algorithm
 * Takes as an argument:
 * - the graph readed from a file
 * - A pointer of the distance matrix (L)
 * - A pointer of the predecessor matrix (P)
 *
 * @returns 1 if absorbing circuit (negative cycle), 0 else
 */
int floydWarshall(GRAPH* graph, int*** L, int*** P);


/**
 * Display resulting matrix from iterations in floydwarhsall
 * Displays the L and P matrix
 */
void displayResult(int** matrix, int nbVertices);


/**
 * @param P  predecessor matrix used to find the path
 * @param start starting vertex
 * @param end ending vertex
 * @param nbVertices nbvertices of the graph
 *
 * How it works:
 * Starts from the end and go back using the P matrix until reach start
 */
void displayPath(int** P, int start, int end, int nbVertices);

#endif