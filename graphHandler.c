#include "graphHandler.h"
#include "stdio.h"
#include "stdlib.h"
#include "floydWarshall.h"
GRAPH* createGraph(int nbVertices, int nbArcs){
    GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
    graph->nbVertices = nbVertices;
    graph->nbArcs = nbArcs;

    // 2D array so double pointer array
    int** matrix = (int **)malloc(nbVertices * (sizeof(int*)));
    for(int i =0; i<nbVertices; i++){
        matrix[i] = (int*)malloc(nbVertices * sizeof(int));
    }

    for(int i =0; i<nbVertices; i++){
        for(int y = 0; y<nbVertices; y++){
            // initialize with inf values
            // can't put 0 because we need to consider weight = 0 values
            matrix[i][y] = INF;
        }
    }

    graph->matrix = matrix;

    //arcs[i][0]  // start vertex
    //arcs[i][1]  // end vertex
    //arcs[i][2]  // weight
    int** arcs = (int **)malloc(nbArcs * (sizeof(int*)));
    for(int i =0; i<nbArcs; i++){
        arcs[i] = (int*)malloc(3 * sizeof(int));
    }
    graph->arcs = arcs;

    printf("Graph initiated\n");

    return graph;
}


GRAPH* createGraphFromFile(char* fileName){

    FILE *file = fopen(fileName, "r");
    if(file == NULL){
        printf("Error: Couldn't open file\n");
        return NULL;

    }

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

    // Column headers
    printf("    ");
    for(int i = 0; i < nbVertices; i++){
        printf("%3d ", i); // number 3 gives space between numbers
    }
    printf("\n");

    // Separator
    printf("   ");
    for(int i = 0; i < nbVertices; i++){
        printf("----");
    }
    printf("\n");

    // Row header
    for(int i = 0; i < nbVertices; i++){
        printf("%2d | ", i);
        for(int y = 0; y < nbVertices; y++){
            if(matrix[i][y] == INF)
                printf("%3s ", "INF");  // add this check
            else
                printf("%3d ", matrix[i][y]);
        }
        printf("\n");
    }
}

// freeGraph function
void freeGraph(GRAPH* graph){
    if(!graph) return;
    for(int i = 0; i < graph->nbVertices; i++)
        free(graph->matrix[i]);
    free(graph->matrix);
    for(int i = 0; i < graph->nbArcs; i++)
        free(graph->arcs[i]);
    free(graph->arcs);
    free(graph);
}

// freeMatrix (for l & p)
void freeMatrix(int** matrix, int n){
    for(int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}