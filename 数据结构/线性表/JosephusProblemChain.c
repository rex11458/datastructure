//
//  JosephusProblemChain.c
//  约瑟夫问题 循环单链表求解
//
//  Created by LiuRex on 2017/8/1.
//  Copyright © 2017年 Shanghai Youyou Finance Information Technology Co.,Ltd. All rights reserved.
//

#include "JosephusProblemChain.h"

#define len sizeof(struct Node)

struct Node {
    int data;
    struct Node *next;
} ;

void josephus_problem_chain(){
    
    int m,n;
    
    printf("总个数：\n");
    scanf("%i",&n);
    printf("退出圈外号码：\n");
    
    scanf("%i",&m);
    
    struct Node *head = malloc(len);
    head->data = 1;
    
    struct Node *p = head,*t;
    
    for (int i = 1 ; i < n; i++) {
        struct Node *node = malloc(len);
        node->data = i + 1;
        p->next = node;
        p = node;
    }
    p->next = head;
    p->data = n;
    
    p = head;
    printf("出队前:");
    printf("%i,",p->data);
    do{
        p = p->next;
        printf("%i,",p->data);
    }
    while (p->next != head);
    
    printf("\n");
    printf("出队后:");

    p = head;
    int count = 0;
    do{
        count++;
        
        if (count == m - 1) {
            t = p->next;
            p->next = t->next;
            count = 0;
            printf("%i,",t->data);
        }
        p = p->next;
        
    }while (p->next != p);
    printf("%i",p->data);
    
    printf("\n");

    
    
}
