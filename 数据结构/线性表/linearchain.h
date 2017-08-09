//
//  linearchain.h
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

/*
 1.3）线性表的链式存储--链表
    * 链式存储中每个结点同时包含数据域和指针域。
      数据域存储元素本身的信息。
      指针域存储前驱结点和后继结点的地址信息。
    *第一个元素为表头结点，最后一个为表尾结点，其余为中间结点。
    *优点：不需要事先分配空间，插入、删除操作速度快。
     缺点：单个结点带有指针域，存储空间上比顺序存储付出代价更大。
 */

#ifndef linearchain_h
#define linearchain_h
#include <stdio.h>
typedef char ElemType;

/*定义单链表结点*/
struct LNode {
    ElemType data;
    struct LNode *next;
};

/*定义单链表结点*/
struct DNode {
    ElemType data;
    struct DNode *left;
    struct DNode *right;
};

/*
 *  置空表
 */
void chain_setnull(struct LNode **head);

/*
 *  表长度
 */
int chain_length(struct LNode *head);

/*
 *  查找结点
 */
ElemType chain_search(struct LNode *head,int index);

/*
 *  按值查找
 */
int chain_locate(struct LNode *head,ElemType e);
/*
 *  插入结点
 */
void chain_insert(struct LNode **head,ElemType e,int index);
/*
 *  删除结点
 */
void chain_del(struct LNode **head,int index);
/*
 *  显示线性表
 */
void chain_display(struct LNode *head);



#endif /* linearchain_h */
