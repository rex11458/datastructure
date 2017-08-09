//
//  binarysorttree.c
//  二叉排序树
//
//  Created by LiuRex on 2017/8/4.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "binarysorttree.h"
#include <stdlib.h>
BSTree* creatree(char str[],int n){

    BSTree *tree = NULL,*p,*s;
    
    for (int i = 0; i < n; i++) {
        
        s = malloc(sizeof(BSTree));
        s->data = str[i];
        s->left = s->right = NULL;
        p = tree;
        if (p == NULL) {
            tree = s;
        }else{
            
            while (p->left !=s && p->right != s) {
                
                if (s->data < p->data) {
                    
                    if (p->left != NULL) {
                        p = p->left;
                    }else{
                        p->left = s;
                    }
                }else{
                    if (p->right != NULL) {
                        p = p->right;
                    }else{
                        p->right = s;
                    }
                }
            }
        }
    }
    
    return tree;
}

BSTree*find(BSTree *tree,int e)
{
    BSTree *p = tree;
    while (p != NULL && p->data != e) {
        
        if (e < p->data) {
            p = p->left;
        }else{
            p = p->right;
        }
    }
    return p;
}

void deletenode(BSTree **tree,int e){
    
    BSTree *p = *tree;
    BSTree *q = NULL,*r,*t;
    while (p != NULL && p->data != e) {
        
        if (e < p->data) {
            q = p ;p = p->left;
        }else{
            q = p ;p = p->right;
        }
    }

    
    if (p == NULL)
        printf("未发现数据域为%d的结点\n",e);
    else if(p->left == NULL){
        
        if (q == NULL)
            t = p->right;
        else if (q->left == p)
            q->left = p->right;
        else
            q->right = p->right;
        
    }else{
        
        /*查找被删结点的左子树中的最右结点，即刚好小于e的结点*/
        r = p->left;
        while (r->right != NULL) {
            r = r->right;
            r->right = p->right;
            r->right=  p->right;
        }
        if (q == NULL) t = p->left;
        else if (q->left == p) q->left = p->left;
        else q->right = p->left;
        
    }
}
