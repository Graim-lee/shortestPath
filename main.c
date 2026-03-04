#include "graphHandler.h"
#include "menu.h"

int main(){
    GRAPH* graph = choose_graph();
    displayMatrix(graph->matrix, graph->nbVertices);

    return 0;
}