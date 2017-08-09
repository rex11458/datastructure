//
//  binarytree.h
//  二叉树的基本操作
//
//  Created by LiuRex on 2017/8/4.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

/*
 *  4.1.1)树的定义
         树是包含n个结点的有穷集合K(n>0)，且在K上定义了一个关系R，关系R满足以下条件：
         1.有且仅有一个结点k0属于K，它对于关系R来说没有前驱，结点k0称做树的根。
         2.除结点k0外，K中的每个结点对于关系R来说都有且仅有一个前驱。
         3.除结点k0外的任何属于K的结点k，都存在一个结点序列k0,k1,...,ks,使得k0就是树根，且ks = k，
         有序队小于Ki-1,ki属于R。这样的结点序列称为从根到结点k的一条路径。
         5.2)树的进步术语
         1.结点的度：树中每个结点具有的子树或者后继结点数称为该结点的度。
         2.树的度：树中所有结点的度的最大值称为树的度。
         3.分支结点：度大于0的结点称为分支结点或非终端结点。
         4.叶子结点：度为0的结点。
         5.孩子结点：一个结点的后继结点。
         6.双亲结点：一个结点称为其后继结点的双亲结点。
         7.子孙结点：一个结点的所有子树中的结点称之为该结点的子孙结点。
         8.祖先结点：从树根结点到达一个结点的路径上通过的所有结点称为该结点的祖先结点。
         9.兄弟结点：具有同一双亲的结点。
         10.结点层数：树具有一种层次结构，跟结点为第一层，其孩子结点为第二层，依次类推得到每个结点的层数。
         11.树中结点的最大层数称为树的深度或高度。
         12.有序树和无序树：如果一颗树中结点的各子树从左到右是有次序的，即若交换了某结点各子树的相对位置构成了不同的树，则称这棵树为有序树，反之则为无序树。
         13.森林：0个或多个不相交的树的集合称为森林。
    4.1.2)二叉树的定义
        二叉树是指树的度为2的有序树。
    4.1.3)二叉树的基本操作
    4.1.4）二叉树的遍历
 */


#ifndef binarytree_h
#define binarytree_h

#include <stdio.h>

typedef struct __btree{
  
    char data;
    struct __btree *left,*right;
    
} BTree,*_btree;


void create_tree(_btree *tree,char *str);

void print_tree(_btree tree);

int tree_depth(_btree tree);

int one_son_count(_btree tree);

int two_son_count(_btree tree);

void printtree(_btree tree);

/*
 *  二叉树的遍历
 */

#endif /* binarytree_h */
