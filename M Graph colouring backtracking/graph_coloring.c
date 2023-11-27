#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int G[MAX_VERTICES][MAX_VERTICES], color[MAX_VERTICES];
int vertices, edges, m;

// Function to check if it's safe to color a vertex with a given color
bool isSafe(int v, int c) {
    for (int i = 0; i < vertices; i++) {
        if (G[v][i] && color[i] == c) {
            return false; // An adjacent vertex has the same color
        }
    }
    return true;
}
// Function to perform m-coloring
void mColoring(int v) {
    if (v == vertices) {
        // All vertices are colored, print the solution
        printf("Solution found:\n");
        for (int i = 0; i < vertices; i++) {
            printf("Vertex %d -> Color %d\n", i + 1, color[i] + 1);
        }
        printf("\n");
        return;
    }
    // Try different colors for the current vertex
    for (int c = 0; c < m; c++) {
        if (isSafe(v, c)) {
            color[v] = c; // Assign the color to the current vertex

            // Recur for the next vertex
            mColoring(v + 1);

            // Backtrack: reset the color if the current assignment doesn't lead to a solution
            color[v] = -1;
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Enter the number of colors (m): ");
    scanf("%d", &m);
    // Initialize color array
    for (int i = 0; i < vertices; i++) {
        color[i] = -1; // -1 represents that no color is assigned yet
    }
    // Start coloring from the first vertex
    mColoring(0);

    return 0;
}
