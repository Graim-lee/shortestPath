#include "graphHandler.h"
#include "menu.h"

int main(){

    int step = 0;
    GRAPH* graph;
    graph = displayguidlines(&step, graph);
    graph = displayguidlines(&step, graph);
    displayMatrix(graph->matrix, graph->nbVertices);

    freeGraph(graph);

    return 0;
}