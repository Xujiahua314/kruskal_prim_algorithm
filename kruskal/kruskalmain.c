#include "kruskal.h"
#include <stdio.h>

Graph CreateGraph() {
    Graph G;
    G.vexNum = 5;
    G.edgeNum = 7;

    G.edge[0] = (Edge){1, 2, 2};
    G.edge[1] = (Edge){1, 3, 3};
    G.edge[2] = (Edge){2, 3, 1};
    G.edge[3] = (Edge){2, 4, 4};
    G.edge[4] = (Edge){3, 4, 2};
    G.edge[5] = (Edge){3, 5, 5};
    G.edge[6] = (Edge){4, 5, 1};

    return G;
}

int main() {
    Graph G = CreateGraph();
    int total;
    Kruskal(&G, &total);
    if (total != -1)
        printf("最小生成树总权值：%d\n", total);
    return 0;
}