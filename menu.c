#include "menu.h"
#include "stdio.h"
#include "stdlib.h"
#include "graphHandler.h"

void freeGraph(GRAPH* graph)
{
    if (graph != NULL)
    {
        for(int i = 0; i< graph->nbVertices - 1; i++){
            free(graph->matrix[i]);
        }
        for(int i =0; i< graph->nbArcs; i++){
            free(graph->arcs[i]);
        }
        free(graph->arcs);
        free(graph->matrix);
        free(graph);
    }
}



GRAPH* choose_graph(int number)
{
    switch(number)
    {
    case 1:
        {
            GRAPH* graph = createGraphFromFile("../Graph/graph1.txt");
            return graph;
        }
    case 2:
        {
            GRAPH* graph = createGraphFromFile("../Graph/graph2.txt");
            return graph;
        }
    case 3:
        {
            GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
            return graph;
        }
    }
}



GRAPH* displayguidlines(int* step, GRAPH* graph)
{
    switch (*step)
    {
        case 0:
        {
                int number = 0;
                do
                {
                    printf("Which graph do you want?\n\n");
                    printf("\t1. Graph 1\n");
                    printf("\t2. Graph 2\n");
                    printf("\t3. Exit\n");
                    scanf("%d", &number);
                } while(number < 1 || number > 3);

                if (number == 3)
                    exit(0);

                graph = choose_graph(number);
                break;
        }
        case 1:
        {
                int number = 0;
                printf("Press 1 to display the matrix associated to the graph\n");
                scanf("%d", &number);
                break;
        }
        case 2:
        {
                printf("Next step\n");
                break;
        }
    }
    (*step)++;
    return graph;
}