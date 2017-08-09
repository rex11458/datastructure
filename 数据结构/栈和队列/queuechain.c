//
//  queuechain.c
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "queuechain.h"
#include <stdlib.h>


void c_initQueue(Queue *Q){
    
    
    Q->front = Q->rear = NULL;
    
}

void c_enter(Queue *Q,ElemType e){
    
    Node *node = malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    
    if (Q->rear == NULL) {
        Q->front = Q->rear = node;
    }{
        Q->rear->next = node;
        Q->rear = node;
    }
}

void c_delete(Queue *Q){
    if (Q->rear == Q->front) return;
    
    Node *n = Q->front;
    Q->front = Q->front->next;
    free(n);
}

ElemType c_gethead(Queue *Q){
    
    if (Q->rear == Q->front) return 0;
    
    return Q->front->data;
    
}

int c_empty(Queue *Q){
    
    if (Q->rear == Q->front) return 1;
    
    return 0;
}

void c_display(Queue *Q){
    
    Node *n = Q->front;
    
    while (n != NULL) {
        printf("%c,",n->data);
        
        n = n->next;
    }
}
