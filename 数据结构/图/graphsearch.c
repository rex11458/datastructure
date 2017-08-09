//
//  graphsearch.c
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "graphsearch.h"
#include <stdlib.h>
void c_creategraph(adjlist g,int *n){
    int e,i,s,d;
    struct edgenode *p,*q;
    
    printf("结点数(n),边(e):");
    scanf("%d,%d",n,&e);
    for (i = 1; i <= *n; i++) {
        getchar();
        printf("第%d个结点信息：",i);
        scanf("%c",&g[i].data);
        g[i].link = NULL;
    }
    
    for (i = 1; i <= e; i++) {
        printf("第%d条边=>起点序号,终点序号:",i);
        scanf("%d %d",&s,&d);
        p = malloc(sizeof(struct edgenode));
        q = malloc(sizeof(struct edgenode));
        
        p->adjvex = d;
        p->data = g[d].data;
        q->adjvex = s;
        q->data = g[s].data;
        p->next = g[s].link;
        g[s].link = p;
        q->next = g[d].link;
        g[d].link = q;
    }
    
    
}


void c_dispgraph(adjlist g,int n){
    
    
}

void dfs(adjlist adj,int v, int visited[]){
   
    /*adj是一个邻接表表示的图，v为初始顶点编号，visited是辅助数组*/
    struct edgenode *p;
    visited[v] =1;
    printf("[%d %c]",v,adj[v].data);
    p = adj[v].link;
    while (p != NULL) {
        if (visited[p->adjvex] == 0) {
            dfs(adj,p->adjvex, visited);
        }
        p = p->next;
    }
    
    
}

int queue[MAX_VEX];
void bfs(adjlist adj,int vi, int visited[]){
    
    int front = 0,rear = 1,v;
    
    struct edgenode *p;
    visited[vi] = 1;
    
    printf("%d,%c",vi, adj[vi].data);
    queue[rear] = vi;
    
    while (front != rear) {
        front = (front + 1) % MAX_VEX;
        v = queue[front];
        p = adj[v].link;
        while (p != NULL) {
            if (visited[p->adjvex] == 0) {
                
                visited[p->adjvex] = 1;
                printf("[%d, %c]",p->adjvex,adj[p->adjvex].data);
                rear = (rear + 1) % MAX_VEX;
                queue[rear] = p->adjvex;
            }
            p = p->next;
        }
    }
}









