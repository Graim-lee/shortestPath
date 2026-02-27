#include "graphHandler.h"
#include "stdio.h"
#include "stdlib.h"

GRAPH* createGraph(int nbVertices, int nbArcs){
    GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
    graph->nbVertices = nbVertices;
    graph->nbArcs = nbArcs;

    int** matrix = (int **)malloc(nbVertices * (sizeof(int*)));
    for(int i =0; i<nbVertices; i++){
        matrix[i] = (int*)malloc(nbVertices * sizeof(int));
    }

    for(int i =0; i<nbVertices; i++){
        for(int y = 0; y<nbVertices; y++){
            matrix[i][y] = 0;
        }
    }

    graph->matrix = matrix;

    int** arcs = (int **)malloc(nbArcs * (sizeof(int*)));
    for(int i =0; i<nbVertices; i++){
        matrix[i] = (int*)malloc(3 * sizeof(int));
    }
    graph->arcs = arcs;

    printf("Graph initiated\n");

    return graph;
}


GRAPH* createGraphFromFile(char* fileName){

    FILE *file = fopen(fileName, "r");
    if(file == NULL){
        printf("ERROR - couldn't open file");
    }

// Use fscanf
    int nbVertices;
    fscanf(file, "%d", &nbVertices);
    int nbArcs;
    fscanf(file, "%d", &nbArcs);

    GRAPH* graph = createGraph(nbVertices, nbArcs);



    for(int i =0; i<graph->nbArcs; i++){
        int startVertex, endVertex, weight;
        fscanf(file, "%d %d %d", &startVertex, &endVertex, &weight);
        graph->arcs[i][0] = startVertex;
        graph->arcs[i][1] = endVertex;
        graph->arcs[i][2] = weight;
        graph->matrix[startVertex][endVertex] = weight;
    }
    printf("Graph created\n");

    fclose(file);
    return graph;
}

void displayMatrix(int** matrix, int nbVertices){

    for(int i =0; i<nbVertices; i++){
        for(int y = 0; y<nbVertices; y++){
            printf("%d ", matrix[i][y]);
        }
        printf("\n");
    }
}