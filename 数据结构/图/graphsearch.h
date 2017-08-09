//
//  graphsearch.h
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

/*
 *  邻接表
    注意：一个图的邻接矩阵表示是唯一的，但其邻接表表示不是唯一的。
 *  图的遍历
    *深度优先搜索
    *宽度优先搜索
    
 */

#ifndef graphsearch_h
#define graphsearch_h

#include <stdio.h>

/*邻接表结构定义*/
static int const MAX_VEX = 100;
typedef char VertexType;

struct edgenode{
    int adjvex;/*邻接点序号*/
    VertexType data;/*邻接点信息*/
    struct edgenode *next;
};
struct vexnode
{
    VertexType data;    /*结点信息*/
    struct edgenode *link; /*指向下一个边结点*/
};

typedef struct vexnode adjlist[MAX_VEX];

void c_creategraph(adjlist g,int *n);
void c_dispgraph(adjlist g,int n);

/*
 *  深度优先搜索
 */
void dfs(adjlist adj,int v, int visited[]);

/*
 *  宽度优先搜索
 */
void bfs(adjlist adj,int v, int visited[]);

#endif /* graphsearch_h */
