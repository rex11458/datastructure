//
//  huffmantree.c
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "huffmantree.h"

void createhuffman(huffnode ht[],int n){
    
    int i,k,l,r,m1,m2;
    
    for (i = 0; i < 2 * n -1; i++)
        ht[i].parent = ht[i].left = ht[i].right = 0;
    
    for (i = n; i< 2 * n - 1; i++) {
        m1 = m2 = 32767;//int max
        
        l = r = 0;
        
        for (k = 0; k < i - 1; k++)
        {
            if (ht[k].parent == 0)
            {
                if (ht[k].weight < m1) {
                    
                    m2 = m1;r = 1;
                    m1 = ht[k].weight ;l = k;
                }else if(ht[k].weight < m2){
                    m2 = ht[k].weight; r = k;
                }
            }
        }
        
        ht[l].parent = i;ht[r].parent = i;
        ht[i].weight = ht[l].weight + ht[r].weight;
        ht[i].left = l;ht[i].right = r;
        
    }
    
}

void createhfcode(huffnode ht[],huffcode hcd[],int n){
    
    int i,f,c;
    huffcode d;
    for (i = 0; i < n;i++) {
        d.start = n+1;c = i;
        f = ht[i].parent;
        while (f != 0) {
            if (ht[f].left == c) {
                d.cd[--d.start] = '0';
            }else{
                d.cd[--d.start] = '1';
            }
            c = f;f = ht[f].parent;
        }
        hcd[i] = d;
    }
}

void displayhuffman(huffnode ht[],huffcode hcd[],int n){
    
    int i,k;
    printf("输出哈夫曼编码：\n");
    for (i = 0; i < n; i++) {
        printf(" %c: ",ht[i].data);
        
        for (k = hcd[i].start; k <= n; k++) {
            printf("%c",hcd[i].cd[k]);
        }
        printf("\n");
    }
    
}



