//
//  graph.c
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "graph.h"
#include <stdlib.h>


graph creatgraph(int *n)
{
    int i,j,k,w,e;
    char b,t;
    graph adj;
    printf("顶点数(n)和边数(e):");
    scanf("%d,%d",n,&e);
    
    for (i = 1; i < *n; i++) {
        
        getchar();
        printf("\t第%d个顶点的信息：",i);
        scanf("%c",&adj.vexs[i].data);
        adj.vexs[i].num = i;
        
    }
    
    for (i = 1; i <= *n; i++){
        for (j = 1; j<= *n; j++) {
            adj.edges[i][j] = 0;
        }
    }
    
    for (k = 1; k <= e; k++) {
        getchar();
        printf("第%d条边=>",k);
        printf("起点：");
        b = getchar();
        i = 1;
        while (i <= *n && adj.vexs[i].data != b) i++;
        if (i> *n) {
            printf("输入的起点不存在");exit(0);
        }
        
        printf("终点：");
        t = getchar();
        j = 1;
        while (j <= *n && adj.vexs[j].data != t) j++;
        
        if (j > *n) {
            printf("输入的终点不存在!\n");exit(1);
        }
        
        printf("权值:");
        scanf("%d",&w);
        adj.edges[i][j] = w;
        
    }
    
    return adj;
    
}
