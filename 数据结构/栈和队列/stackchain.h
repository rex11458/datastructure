//
//  stack.h
//  二叉树的基本操作
//
//  Created by LiuRex on 2017/8/4.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

/*
 * 2.3）栈的链式存储
 */
#ifndef stack_h
#define stack_h

#include <stdio.h>
#include "binarytree.h"

typedef BTree*  ElemType;
typedef struct _stack{
    
    ElemType data;
    struct _stack *next;
    
}Stack;

void initStack(Stack **node);

int empty(Stack **node);

ElemType gettop(Stack *node);

void push(Stack **node,ElemType e);

void pop(Stack **node);

#endif /* stack_h */
