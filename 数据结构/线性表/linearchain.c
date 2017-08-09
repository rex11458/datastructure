//
//  linearchain.c
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "linearchain.h"
#include <stdlib.h>
/*
 *  置空表
 */
void chain_setnull(struct LNode **head){
    *head = NULL;
}

/*
 *  表长度
 */
int chain_length(struct LNode *head){
    
    int len = 0;
    
    while (head->next != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

/*
 *  查找结点
 */
ElemType chain_search(struct LNode *head,int index)
{
    int j = 0;
    struct LNode *p = head;
    while (j < index && p != NULL) {
        j++;
        p = p->next;
    }
    
    if (p == NULL) {
        printf("位置不正确");
        return -1;
    }else{
        return p->data;
    }
}

/*
 *  按值查找
 */
int chain_locate(struct LNode *head,ElemType e)
{
    int n = 0;
    struct LNode *p = head;
    while (p->data != e && p != NULL) {
        n++;
        p = p->next;
    }
    
    if (p == NULL) {
        printf("位置不正确");
        return -1;
    }else{
        return n;
    }
}
/*
 *  插入结点
 */
void chain_insert(struct LNode **head,ElemType e,int index)
{
    int j = 0;
    struct LNode *s, *q;
    q = *head;
    s = malloc(sizeof(struct LNode));
    
    s->data = e;
    
    if (index == 0) {
        s->next = q;
        *head = s;
    }else{
        
        while (j < index && q->next != NULL) {

            q = q->next;j++;
        }
        
        if (j == index) {
            s->next = q->next;
            q->next = s;
        }else{
            printf("位置不正确");
        }
    }
}
/*
 *  删除结点
 */
void chain_del(struct LNode **head,int index)
{

    if (*head == NULL) printf("表为空");

    struct  LNode *p = *head,*t;
    if (index == 0) {
    
        *head = p->next;
        t = p;
        free(p);
        
    }else{
        int j = 0;
        while (j < index - 1 && p->next != NULL) {
            
            j++;
            p = p->next;
        }
        
        if (p->next != NULL && j == index - 1 ) {
            
            t = p->next;
            p->next = t->next;
            
            
        }else{
            printf("位置不正确");
        }
    }
    
    if (t != NULL) {
       free(t);
    }
}
/*
 *  显示线性表
 */
void chain_display(struct LNode *head)
{
    struct LNode *p = head;
    
    printf("单链表显示：");
    if (p == NULL) {
        printf("链表为空");
    }
    else {
        
        while (p->next != NULL) {
            printf("%c,",p->data);
            p = p->next;
        }
    }
    printf("\n");
}
