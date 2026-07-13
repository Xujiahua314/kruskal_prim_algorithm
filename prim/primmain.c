#include "prim.h"
#include <stdio.h>

int main() {
    Graph G = CreateGraph();
    int totalWeight;
    Prim(&G, &totalWeight);
    if (totalWeight != -1) {
        printf("=========================\n");
        printf("Prim最小生成树总权值：%d\n", totalWeight);
    }
    return 0;
}