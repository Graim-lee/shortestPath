#include "floydWarshall.h"
#include "stdio.h"
#include "stdlib.h"

int floydWarshall(GRAPH* graph, int*** L, int*** P){
    int n = graph->nbVertices;

    // Initialize distance (L) matrix
    int** dist = (int**)malloc(n * sizeof(int*));
    // Initialize predecessor (P) matrix
    int** pred = (int**)malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++){
        dist[i] = (int*)malloc(n * sizeof(int));
        pred[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++){

            // diagonal (vertex on itself)
            if(i == j && graph->matrix[i][j] == INF){
                // if NO loop on itself( value = 0 pred = -1 )
                dist[i][j] = 0;
                pred[i][j] = -1;


            }
            // if value in adjacency matrix, put it in dist[i][j]
            else if(graph->matrix[i][j] != INF){
                dist[i][j] = graph->matrix[i][j];
                pred[i][j] = i;

            // if no edge -> INF and no predecessors (-1)
            } else {
                dist[i][j] = INF;
                pred[i][j] = -1;
            }
        }
    }

    // displayResult(pred,n);
    // displayResult(dist,n);

    // Core algorithm
    for(int k = 0; k < n; k++){ // intermediate vertex
        printf("\n--- Step k = %d ---\n", k); // nb steps = nb vertices
        for(int i = 0; i < n; i++){ // starting vertex
            for(int j = 0; j < n; j++){ // ending vertex

                // to avoid sum of infinite (if both are infinite, the other dist[i][j] is always smaller)
                if(dist[i][k] != INF && dist[k][j] != INF){

                    // check if with intermediate vertex k (i->k->j), total edges weight is less than direct edge from i to j
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

    // Negative cycle detection (once all computation done)
    for(int i = 0; i < n; i++){
        // if in diagonal negative value => negative cycle
        if(dist[i][i] < 0){
            printf("Error: negative cycle detected at vertex %d\n", i);
            *L = dist;
            *P = pred;
            return 1;
        }
    }

    *L = dist;
    *P = pred;
    return 0;
}

// display results matrix
void displayResult(int** matrix, int nbVertices){
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
            if(matrix[i][j] == INF)
                printf("%6s ", "INF");
            else
                printf("%6d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void displayPath(int** P, int start, int end, int nbVertices){

    // check for start / end not in the graph
    if (start>nbVertices || end>nbVertices || start<0 || end<0) {
        printf("You need to stay in the range of existing vertices");
        printf("With 0 <= start and end <= %d",nbVertices-1);
        return;
    }
    if(P[start][end] == -1){
        printf("No path from %d to %d\n", start, end);
        return;
    }

    // Reconstruct path using predecessor matrix
    // we start from end and go back to start
    int path[nbVertices];
    int size = 0;
    int current = end;

    while(current != start){
        path[size++] = current;
        current = P[start][current];
        if(size > nbVertices){
            printf("Error: cycle detected during path reconstruction\n");
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