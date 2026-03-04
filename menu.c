#include "menu.h"
#include "stdio.h"
#include "stdlib.h"
#include "graphHandler.h"

/**
* display the starting menu (the name and R2D2)
 */
GRAPH* choose_graph()
{
    int number = 0; // choice by the user
    while(1)
    {
        do{
            printf("Which graph do you want ?\n\n");
            printf("\t1. Graph 1\n");
            printf("\t2. Graph 2\n");
            printf("\t3. Exit\n");
            scanf("%d",&number);
        }while(number <1 | number > 3);
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
}