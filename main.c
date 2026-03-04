#include "graphHandler.h"

int main(){
    GRAPH* graph = createGraphFromFile("../graph2.txt");
    displayMatrix(graph->matrix, graph->nbVertices);
    return 0;
}