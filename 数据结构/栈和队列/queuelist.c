//
//  queuelist.c
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "queuelist.h"



void q_initQueue(Queue *Q){
    Queue *q = Q;
    q->front = q->rear = -1;
    
}

void q_enter(Queue *Q,ElemType E){
    
    Q->rear++;
    Q->data[Q->rear] = E;
    
}

void q_delete(Queue *Q){
    
    if (Q->rear == Q->front) return;
    
    Q->front++;
}

ElemType q_gethead(Queue *Q){
    
    if (Q->rear == Q->front) return 0;
    
    return Q->data[Q->front + 1];
    
}

int q_empty(Queue *Q){
    
    if (Q->front == Q->rear)  return 1;
    
    return 0;
    
}

void q_display(Queue *Q){
    
    for (int i = Q->front + 1; i <= Q->rear; i++) {
        printf("%c,",Q->data[i]);
    }
    printf("\n");
}


