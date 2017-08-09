//
//  stack.c
//  二叉树的基本操作
//
//  Created by LiuRex on 2017/8/4.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "stackchain.h"
#include <stdlib.h>

void initStack(Stack **node){
    *node = NULL;
}

int empty(Stack **node){
    
    return (*node == NULL);
}

ElemType gettop(Stack *node){
    if (node == NULL) {
        return NULL;
    }

    return node->data;
}


void push(Stack **node,ElemType e){
    
    Stack *snode = malloc(sizeof(Stack));
    snode->data = e;
    snode->next = *node;
    
    *node = snode;
    
}

void pop(Stack **node){
    
    if ( *node == NULL) {
        return;
    }
    Stack *t = *node;
    *node = (*node)->next;
    free(t);
}
