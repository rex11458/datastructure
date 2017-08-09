//
//  queuechain.h
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#ifndef queuechain_h
#define queuechain_h

#include <stdio.h>

typedef char ElemType;
typedef struct qnode{
    ElemType data;
    struct qnode *next;
}Node;

typedef struct {
    
    Node *rear;
    Node *front;
    
}Queue;


void c_initQueue(Queue *Q);

void c_enter(Queue *Q,ElemType e);
void c_delete(Queue *Q);

ElemType c_gethead(Queue *Q);

int c_empty(Queue *Q);
void c_display(Queue *Q);
#endif /* queuechain_h */
