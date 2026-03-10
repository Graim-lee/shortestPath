#include "floydWarshall.h"
#include "stdio.h"
#include "stdlib.h"

int floydWarshall(GRAPH* graph, int*** L, int*** P){
    int n = graph->nbVertices;

    // Initialize L matrix
    int** dist = (int**)malloc(n * sizeof(int*));
    // Initialize P matrix
    int** pred = (int**)malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++){
        dist[i] = (int*)malloc(n * sizeof(int));
        pred[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){
            if(i == j){
                dist[i][j] = 0;
                pred[i][j] = -1;
            } else if(graph->matrix[i][j] != 0){
                dist[i][j] = graph->matrix[i][j];
                pred[i][j] = i;
            } else {
                dist[i][j] = INF;
                pred[i][j] = -1;
            }
        }
    }

    // Core algorithm
    for(int k = 0; k < n; k++){
        printf("\n--- Step k = %d ---\n", k);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                        pred[i][j] = pred[k][j];
                    }
                }
            }
        }
        printf("L matrix:\n");
        displayResult(dist, n);
        printf("P matrix:\n");
        displayResult(pred, n);
    }

    // Negative cycle detection
    for(int i = 0; i < n; i++){
        if(dist[i][i] < 0){
            printf("ERROR - negative cycle detected at vertex %d\n", i);
            *L = dist;
            *P = pred;
            return 1;
        }
    }

    *L = dist;
    *P = pred;
    return 0;
}

void displayResult(int** dist, int nbVertices){
    printf("    ");
    for(int i = 0; i < nbVertices; i++)
        printf("%6d ", i);
    printf("\n   ");
    for(int i = 0; i < nbVertices; i++)
        printf("-------");
    printf("\n");
    for(int i = 0; i < nbVertices; i++){
        printf("%2d | ", i);
        for(int j = 0; j < nbVertices; j++){
            if(dist[i][j] == INF)
                printf("%6s ", "INF");
            else
                printf("%6d ", dist[i][j]);
        }
        printf("\n");
    }
}

void displayPath(int** P, int start, int end, int nbVertices){
    if(P[start][end] == -1){
        printf("No path from %d to %d\n", start, end);
        return;
    }

    // Reconstruct path using predecessor matrix
    int path[nbVertices];
    int size = 0;
    int current = end;

    while(current != start){
        path[size++] = current;
        current = P[start][current];
        if(size > nbVertices){
            printf("ERROR - cycle detected during path reconstruction\n");
            return;
        }
    }
    path[size++] = start;

    // Print in reverse
    printf("Path from %d to %d: ", start, end);
    for(int i = size - 1; i >= 0; i--){
        if(i > 0) printf("%d -> ", path[i]);
        else printf("%d", path[i]);
    }
    printf("\n");
}