#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include "graphHandler.h"

#define INF 99999

int floydWarshall(GRAPH* graph, int*** L, int*** P);
void displayResult(int** dist, int nbVertices);
void displayPath(int** P, int start, int end, int nbVertices);

#endif