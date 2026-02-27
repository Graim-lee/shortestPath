#include "graphHandler.h"

int main(){
    GRAPH* graph = createGraphFromFile("../graph.txt");
    displayMatrix(graph->matrix, graph->nbVertices);
    return 0;
}