#include "graphHandler.h"
#include "stdio.h"

int main(){
    GRAPH* graph = createGraphFromFile("../graph3.txt");
    if (graph == NULL){
        printf("Failed to load\n");
        return 1;
    }
    displayMatrix(graph->matrix, graph->nbVertices);
    return 0;
}