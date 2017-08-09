//
//  huffmantree.h
//  数据结构
//
//  Created by LiuRex on 2017/8/7.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

/*
 *  4.3.1) 哈夫曼树的定义
        设二叉树具有n个带权值的叶子结点，那么从根结点到各个叶子结点的路径长度与相应结点权值的乘积之和叫作二叉树的带权路径长度。
    哈夫曼树是一种特殊的二叉树，这种树的所有叶子结点都带有权值，从中构造出来带权路径长度最短的二叉树，即哈夫曼树。
    4.3.2）哈夫曼编码
        树中从根到每个叶子都有一条路径，对路径上的各分支阅读指向左子树的分支表示“0”码，指向右子树的分支表示“1”码，取每条路径上的“0”或“1”
    的序列作为和各个叶子对应的字符的编码，这个就是哈夫曼编码。
 */

#ifndef huffmantree_h
#define huffmantree_h

#include <stdio.h>

static int const MAX_SIZE = 50;

typedef struct {
    char data;  /*结点值*/
    int weight; /*权重*/
    int parent; /*父结点*/
    int left;   /*左结点*/
    int right;  /*右结点*/
}huffnode;

typedef struct {
    char cd[MAX_SIZE];
    int start;
}huffcode;

void createhuffman(huffnode ht[],int n);

void createhfcode(huffnode ht[],huffcode hcd[],int n);

void displayhuffman(huffnode ht[],huffcode hcd[],int n);

#endif /* huffmantree_h */
