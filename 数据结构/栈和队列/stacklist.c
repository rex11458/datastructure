//
//  stacklist.c
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "stacklist.h"


void list_initStack(Stack *stack){
    stack->top = -1;
}

void list_pop(Stack *stack){
    if (list_empty(stack) == 1) {
        return ;
    }
    
    stack->top--;
    
}

void list_push(Stack *stack,ElemType e){
    if (stack->top == MAX_SIZE) {
        return;
    }
    stack->top++;
    stack->stack[stack->top] = e;
}

ElemType list_gettop(Stack *stack){
    if (stack->top == -1) {
        return 0;
    }
    
    return stack->stack[stack->top];
}

int list_empty(Stack *stack){
    
    if (stack->top == -1) {
        return 1;
    }
    return 0;
    
}
