
#include <stdio.h>

#define INF 99999

struct Edge {
    int src, dest, weight;
};

int main() {
    int V, E, i, j, source;
    int dist[100];
    struct Edge edge[500];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    if (V < 1 || V > 100 || E < 0 || E > 500) {
        printf("Invalid graph size.\n");
        return 1;
    }

    printf("Enter source, destination and weight:\n");

    for (i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edge[i].src,
              &edge[i].dest,
              &edge[i].weight);

        if (edge[i].src < 0 || edge[i].src >= V ||
            edge[i].dest < 0 || edge[i].dest >= V) {
            printf("Invalid vertex number.\n");
            return 1;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= V) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    for (i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Relax all edges V-1 times
    for (i = 1; i < V; i++) {
        for (j = 0; j < E; j++) {
            int u = edge[j].src;
            int v = edge[j].dest;
            int w = edge[j].weight;

            if (dist[u] != INF &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (i = 0; i < E; i++) {
        int u = edge[i].src;
        int v = edge[i].dest;
        int w = edge[i].weight;

        if (dist[u] != INF &&
            dist[u] + w < dist[v]) {
            printf("Graph contains a negative weight cycle.\n");
            return 0;
        }
    }

    printf("\nVertex\tDistance from Source\n");

    for (i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    printf("\nName: Shourya Singh\n");
    return 0;
}
