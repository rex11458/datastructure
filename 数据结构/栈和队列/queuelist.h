//
//  queuelist.h
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

/*
 *  2.4)队列的定义
       队列简称队，它也是一种运算受限的线性表，其限制仅允许在表的一端进行插入，而在表的另一端进行删除。把进行插入的一端称做
    队尾(rear)，进行删除的一端称做队首(front)。向队列中插入新元素称做进队或入队，新元素进队后就称为新的队尾元素；从队列中
    删除元素称为离队或出队，元素离队后，其后继元素就成为队首元素。
    2.5）队列的基本操作
 */


#ifndef queuelist_h
#define queuelist_h

#include <stdio.h>

static int const MAX_SIZE = 5;
typedef char ElemType;

typedef struct {
    
    ElemType data[MAX_SIZE];
    int front;
    int rear;
    
}Queue;

void q_initQueue(Queue *Q);
void q_enter(Queue *Q,ElemType E);

void q_delete(Queue *Q);

ElemType q_gethead(Queue *Q);

int q_empty(Queue *Q);

void q_display(Queue *Q);

#endif /* queuelist_h */
