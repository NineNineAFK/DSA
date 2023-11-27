#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INF 9999999
#define V 3

int G[V][V] = {
    {0, 5, 2},
    {5, 0, 1},
    {2, 1, 0}
};

int main() {
    int no_edge;
    int selected[V];

    memset(selected, false, sizeof(selected));

    no_edge = 0;
    selected[0] = true;

    int x, y;

    printf("Edge : Weight\n");

    while (no_edge < V - 1) {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {                        //checks if the current vertex has been 
                                                    //included in the minimum spanning tree.  
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {      //checks if the current vertex has not been included in the 
                                                        //minimum spanning tree and if there is an edge between the current vertices.
                        
                        if (min > G[i][j]) {            // checks if the weight of the current edge is less than the 
                                                        //minimum weight found so far  
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }

    return 0;
}
