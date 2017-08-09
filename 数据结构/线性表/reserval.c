//
//  reserval.c
//  
//
//  Created by LiuRex on 2017/8/1.
//  Copyright © 2017年 Shanghai Youyou Finance Information Technology Co.,Ltd. All rights reserved.
//
/*
 *  将结点数据依次是A1,A2,...,An的单链表逆置
 */
#include "reserval.h"

int length(struct Node *p){
    
    int i = 1;
    while (p->next) {
        i++;
        p = p->next;
    }
    return i;
}

struct Node*  node(struct Node *head, int index){
    
    int len = length(head);
    
    if (index >= len) {
        
        return NULL;
        
    }
    
    int i = 0;
    
    struct Node *p = head;
    while (i < len) {
        if (i == index) {
            
            return p;
        }
        
        p = p->next;
        i++;
    }

    return NULL;
}

void display(struct Node *head){
    struct Node *p = head;
    do{
        printf("%i,",p->data);
        p = p->next;
    }
    while (p->next != NULL) ;
    printf("%i",p->data);
    printf("\n");
    
}

void reserval(struct Node *head){
    
    printf("翻转前:");
    display(head);
    
    int len = length(head);
    
    int i = 0;
    int j = 0;
    while (i < len / 2) {
        j = len - i - 1;
        struct Node *p,*q;
        p = node(head, i);
        q = node(head, j);
        
        int temp = p->data;
        p->data = q->data;
        q->data = temp;
        
        
        i++;
    }
    printf("翻转后:");
    display(head);
}

