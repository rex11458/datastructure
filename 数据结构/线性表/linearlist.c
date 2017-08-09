//
//  linearlist.c
//  数据结构
//
//  Created by LiuRex on 2017/8/4.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "linearlist.h"



/*
 *  置空表
 */
void setnull(struct Line *line)
{
    line->size = 0;
}


/*
 *  表长度
 */
int length(struct Line *line)
{
    return line->size;
}

/*
 *  查找结点
 */
ElemType search(struct Line *line,int index)
{
    if (index > line->size || index < 0) {
        printf("没有查找到");
        return -1;
    }
    
    return line->list[index];
}

/*
 *  按值查找
 */
int locate(struct Line *line,ElemType e)
{
    for (int i = 0; i < line->size; i++) {
        ElemType ee = line->list[i];
        if (ee == e) {
            return i;
        }
    }
    return -1;
}
/*
 *  插入结点
 */
void insert(struct Line *line,ElemType e,int index)
{
    if (index < 0 || index > line->size) {
        printf("插入位置不正确");
        return ;
    }
    
    line->size++;
    for (int i = line->size - 1; i > index; i--) {
        
        line->list[i] = line->list[i - 1];
        
    }
    line->list[index] = e;
}
/*
 *  删除结点
 */
void del(struct Line *line,int index)
{
    if (index < 0 || index > line->size) {
        printf("位置不正确");
        return ;
    }
    
    for (int i = index; i < line->size - 1; i++) {
        
        line->list[i + 1] = line->list[i];
        
    }
    line->size--;
    
}
/*
 *  显示线性表
 */
void display(struct Line *line)
{
    if (line->size == 0) {
        printf("表为空");
    }
    
    for (int i = 0; i < line->size; i++) {
        printf("%c,",line->list[i]);
    }
}
