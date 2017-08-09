//
//  linearlist.h
//  数据结构
//
//  Created by LiuRex on 2017/8/4.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

/*
 1.1.1）线性表的定义：
    线性表是具有相同特性的数据元素的一个有限序列。该序列中所含元素个数表示该线性表的长度。
    (a1,a2,...,ai,ai+1,...,an);
    其中a1为第一个元素，称作表头元素，an为最后一个元素，称作表尾。
 */


#ifndef linearlist_h
#define linearlist_h

#include <stdio.h>

/*
 1.2）线性表的顺序存储
 */
static int const MAX_SIZE = 50;
typedef char ElemType;
struct Line {
    ElemType list[MAX_SIZE];
    int size;
};

/*
 *  置空表
 */
void setnull(struct Line *line);

/*
 *  表长度
 */
int length(struct Line *line);

/*
 *  查找结点
 */
ElemType search(struct Line *line,int index);

/*
 *  按值查找
 */
int locate(struct Line *line,ElemType e);
/*
 *  插入结点
 */
void insert(struct Line *line,ElemType e,int index);
/*
 *  删除结点
 */
void del(struct Line *line,int index);
/*
 *  显示线性表
 */
void display(struct Line *line);

#endif /* linearlist_h */
