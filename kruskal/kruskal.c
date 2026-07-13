#include "kruskal.h"
#include <stdio.h>
#include <stdlib.h>

int parent[MAX_VEX];

void InitUnionFind(int n) {
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int Find(int x) {
    if (parent[x] != x)
        parent[x] = Find(parent[x]);
    return parent[x];
}

int Union(int x, int y) {
    int rx = Find(x);
    int ry = Find(y);
    if (rx == ry) return 0;
    parent[ry] = rx;
    return 1;
}

int CmpEdge(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->weight - e2->weight;
}

void Kruskal(Graph *G, int *sumWeight) {
    InitUnionFind(G->vexNum);
    qsort(G->edge, G->edgeNum, sizeof(Edge), CmpEdge);

    *sumWeight = 0;
    int cnt = 0;
    printf("最小生成树边：\n");
    printf("起点 终点 权值\n");

    for (int i = 0; i < G->edgeNum; i++) {
        int s = G->edge[i].start;
        int e = G->edge[i].end;
        int w = G->edge[i].weight;

        if (Union(s, e)) {
            printf("%d   %d   %d\n", s, e, w);
            *sumWeight += w;
            cnt++;
            if (cnt == G->vexNum - 1) break;
        }
    }

    if (cnt != G->vexNum - 1) {
        printf("该图不连通，无完整最小生成树\n");
        *sumWeight = -1;
    }
}