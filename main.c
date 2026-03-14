#include "graphHandler.h"
#include "floydWarshall.h"
#include "stdio.h"

int main(){
    int graphNumber;
    char fileName[50];

    while(1){
        printf("\nWhich graph to analyze? (-1 to quit): ");
        scanf("%d", &graphNumber);

        if(graphNumber == -1) break;

        sprintf(fileName, "../graphs/graph%d.txt", graphNumber);

        GRAPH* graph = createGraphFromFile(fileName);
        if(graph == NULL){
            printf("ERROR - could not load graph %d\n", graphNumber);
            continue;
        }

        printf("\nAdjacency matrix:\n");
        displayMatrix(graph->matrix, graph->nbVertices);

        int** L = NULL;
        int** P = NULL;
        int hasNegativeCycle = floydWarshall(graph, &L, &P);

        if(hasNegativeCycle){
            printf("\nThis graph contains an absorbing circuit!\n");
        } else {
            printf("\nFinal shortest paths (L matrix):\n");
            displayResult(L, graph->nbVertices);

            char answer;
            printf("\nDo you want to display a path? (y/n): ");
            scanf(" %c", &answer);

            while(answer == 'y'){
                int start, end;
                printf("Starting vertex: ");
                scanf("%d", &start);
                printf("Ending vertex: ");
                scanf("%d", &end);

                displayPath(P, start, end, graph->nbVertices);

                printf("\nAnother path? (y/n): ");
                scanf(" %c", &answer);
            }
        }
    }

    printf("Goodbye!\n");
    return 0;
}