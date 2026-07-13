#ifndef PRIM_H
#define PRIM_H

#define MAX_VEX 100
#define INF 0x3f3f3f3f  // 无穷大代表无边

// 邻接矩阵存储图
typedef struct {
    int vexNum;
    int edgeNum;
    int matrix[MAX_VEX][MAX_VEX];
} Graph;

// 创建测试图
Graph CreateGraph();
// Prim最小生成树，返回总权值
void Prim(Graph* G, int* sumWeight);

#endif