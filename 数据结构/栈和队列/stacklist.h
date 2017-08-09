//
//  stacklist.h
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

/*
 *  2.1)栈的定义
        栈是一种能在一端进行插入或者删除操作的线性表。
        表中允许进行插入、删除操作的一段称为栈顶。栈顶的当前位置是动态的，栈顶的当前位置由一个称为栈顶指针的位置指示器指示。
        表的另一端称为栈底。
        当栈中没有数据元素时，称为空栈。
        栈的插入操作通常称为进栈或入栈，栈的删除操作通常称为退栈或出栈。
    栈的主要特点是 “后进先出”。所以栈也称为后进先出表。
  
 *  2.2)栈的顺序存储
 */

#ifndef stacklist_h
#define stacklist_h

#include <stdio.h>

typedef char ElemType;

static int const MAX_SIZE = 100;

typedef struct {
    
    ElemType stack[MAX_SIZE];
    int top;
    
}Stack;

/*
 建立一个空栈
 */
void list_initStack(Stack *stack);

void list_pop(Stack *stack);

void list_push(Stack *stack,ElemType e);

ElemType list_gettop(Stack *stack);

int list_empty(Stack *stack);

#endif /* stacklist_h */
