#include "prim.h"
#include <stdio.h>
#include <string.h>

void Prim(Graph* G, int* sumWeight) {
    int n = G->vexNum;
    int lowCost[MAX_VEX];  // 到生成树的最小权值
    int visited[MAX_VEX];  // 标记是否加入生成树
    *sumWeight = 0;

    // 初始化：从顶点1开始
    memset(visited, 0, sizeof(visited));
    visited[1] = 1;
    for (int i = 1; i <= n; i++) {
        lowCost[i] = G->matrix[1][i];
    }

    printf("===== Prim最小生成树边 =====\n");
    printf("起点\t终点\t权值\n");

    // 还需要选 n-1 条边
    for (int i = 1; i <= n - 1; i++) {
        // 找未访问里权值最小的点
        int minVal = INF;
        int newVex = -1;
        int startVex = 1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && lowCost[j] < minVal) {
                minVal = lowCost[j];
                newVex = j;
                // 记录这条边的起点
                for (int k = 1; k <= n; k++) {
                    if (visited[k] && G->matrix[k][newVex] == minVal) {
                        startVex = k;
                        break;
                    }
                }
            }
        }

        if (newVex == -1) {
            printf("该图不连通，无法生成完整最小生成树\n");
            *sumWeight = -1;
            return;
        }

        // 加入生成树
        visited[newVex] = 1;
        *sumWeight += minVal;
        printf("%d\t%d\t%d\n", startVex, newVex, minVal);

        // 更新lowCost数组
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && G->matrix[newVex][j] < lowCost[j]) {
                lowCost[j] = G->matrix[newVex][j];
            }
        }
    }
}

// 构建和Kruskal相同的5顶点测试图
Graph CreateGraph() {
    Graph G;
    G.vexNum = 5;
    G.edgeNum = 7;
    // 邻接矩阵初始化为无穷大
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            G.matrix[i][j] = INF;
        }
        G.matrix[i][i] = 0;
    }
    // 填入所有边
    G.matrix[1][2] = 2; G.matrix[2][1] = 2;
    G.matrix[1][3] = 3; G.matrix[3][1] = 3;
    G.matrix[2][3] = 1; G.matrix[3][2] = 1;
    G.matrix[2][4] = 4; G.matrix[4][2] = 4;
    G.matrix[3][4] = 2; G.matrix[4][3] = 2;
    G.matrix[3][5] = 5; G.matrix[5][3] = 5;
    G.matrix[4][5] = 1; G.matrix[5][4] = 1;
    return G;
}