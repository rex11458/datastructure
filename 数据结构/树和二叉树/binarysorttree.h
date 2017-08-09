//
//  binarysorttree.h
//  二叉排序树
//
//  Created by LiuRex on 2017/8/4.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

/*
 *  4.2）二叉排序树的定义
        1.若他的左子树非空，则左子树上所有结点的关键字均小于跟结点的关键字；
        2.若它的右子树为空，则右子树上所有结点的关键字均大于根结点的关键字。
        3.左右子树本身又是一棵二叉排序树。
 */

#ifndef binarysorttree_h
#define binarysorttree_h

#include <stdio.h>

typedef struct _bstree{
    
    int data;
    struct _bstree *left,*right;
    
}BSTree;

BSTree* creatree(char str[],int n);

//查找元素
BSTree*find(BSTree *tree,int e);

/*
 *  查找值域为e的结点p
    若p所指结点没有左子树，则用右子树的根代替被删的结点。
    若p所指结点右左子树，则在左子树中找到最右结点r代替被删的结点。
 */
void deletenode(BSTree **tree,int e);

#endif /* binarysorttree_h */
