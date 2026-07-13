#ifndef KRUSKAL_H
#define KRUSKAL_H

#define MAX_VEX 100
#define MAX_EDGE 1000

typedef struct {
    int start;
    int end;
    int weight;
} Edge;

typedef struct {
    int vexNum;
    int edgeNum;
    Edge edge[MAX_EDGE];
} Graph;

extern int parent[MAX_VEX];

void InitUnionFind(int n);
int Find(int x);
int Union(int x, int y);
int CmpEdge(const void *a, const void *b);
void Kruskal(Graph *G, int *sumWeight);

#endif