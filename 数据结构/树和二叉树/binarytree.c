//
//  binarytree.c
//  二叉树的基本操作
//
//  Created by LiuRex on 2017/8/4.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "binarytree.h"
#include <stdlib.h>
#include "stackchain.h"
/*
 *  根据括号表示法建立一棵二叉树 A(B(D,E(H,I)),C(G))
 */
void create_tree(_btree *tree,char *str){
    BTree *p = NULL;
    int i = 0,k = 0;
    char ch = str[i];
    Stack *stack;
    initStack(&stack);
    while (ch != '\0') {
        switch (ch) {
            case '(':
                k = 1; push(&stack, p);
                break;
            case ',':
                k = 2;
                break;
            case ')':
                pop(&stack);
                break;
            default:
                p = malloc(sizeof(BTree));
                p->data = ch;
                p->left = p->right = NULL;
            
                if (*tree == NULL) {
                    *tree = p;
                }
                BTree *bt = gettop(stack);
                switch (k) {
                    case 1:
                        bt->left = p;
                        break;
                     case 2:
                        bt->right = p;
                        break;
                    default:
                        break;
                }
                break;
        }
        i++;
        ch = str[i];
    }
}

/*
 *  凹入法显示一颗二叉树
A----------
 B---------
  D--------
  E--------
   H-------
   I-------
 C---------
  G--------
 */

static int const MAX_WIDTH = 10;

void print_line(char ch,int width);

void print_tree(_btree tree)
{
    if (tree == NULL) return;
    int width = 1;
    BTree *p;
    Stack *stack;
    initStack(&stack);
    
    push(&stack, tree);
 //A(B(D,E(H,I)),C(G))
    int level[MAX_WIDTH],top = 1,n = 0;
    p = gettop(stack);
    level[top] = 0;
    while (p != NULL) {
        
        n = level[top];
        print_line(p->data, n);
        pop(&stack);
        top--;
        if (p->right) {
            top++;
            push(&stack, p->right);
            level[top] = n + width;
        }
        
        if (p->left) {
            top++;
            push(&stack, p->left);
            level[top] = n + width;
        }
        
        p = gettop(stack);

    }
    printf("\n");
}

void print_line(char ch,int n){
    
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
    
    printf("%c",ch);
    for (int i = n; i < MAX_WIDTH; i++) {
        printf("-");
    }
    printf("\n");
}


/*
 *  二叉树深度
 */
int tree_depth(_btree tree){
    
    if (tree == NULL) {
        return 0;
    }
    //A(B(D,E(H,I)),C(G))
    
    int leftdep = tree_depth(tree->left);
    
    int rightdep = tree_depth(tree->right);
    
    if (leftdep > rightdep) {
        return (leftdep + 1);
    }else{
        return (rightdep +1);
    }
    
}

/*
 *  结点数
 */
int node_count(_btree tree){
    if (tree == NULL) {
        return 0;
    }

    return node_count(tree->left) + node_count(tree->right) + 1;
}

/*
 *  叶子结点数
 */
int leaf_count(_btree tree){
    
    if (tree == NULL) {
        return 0;
    }else if (tree->left == NULL && tree->right == NULL){
        return 1;
    }else{
        return (leaf_count(tree->left) + leaf_count(tree->right));
    }
}

/*
 *  非叶子结点个数
 */
int noleaf_count(_btree tree){
    
    if (tree == NULL) {
        return 0;
    }else if (tree->left == NULL && tree->right == NULL){
        return 0;
    }else{
        return (noleaf_count(tree->left) + noleaf_count(tree->right));
    }
}

/*
 *  只有一个孩子的结点个数
 */
int one_son_count(_btree tree){
    
    
    if (tree == NULL) {
        return 0;
    }else if ((tree->left == NULL && tree->right != NULL) ||
              (tree->left != NULL && tree->right == NULL)){
        return (one_son_count(tree->left) + one_son_count(tree->right) + 1);
    }else{
        return (one_son_count(tree->left) + one_son_count(tree->right));
    }
}

/*
 *  只有两个个孩子的结点个数
 */
int two_son_count(_btree tree){
    if (tree == NULL) {
        return 0;
    }else if(tree->left != NULL && tree->right != NULL){
        return (two_son_count(tree->left) + two_son_count(tree->right) + 1);
    }else{
        return (two_son_count(tree->left) + two_son_count(tree->right) );
    }
}

/*
 *  括号表示法显示二叉树
 */
void printtree(_btree tree){
    if (tree != NULL) {
        printf("%c",tree->data);
        if (tree->left != NULL || tree->right != NULL) {
            printf("(");
            printtree(tree->left);
            if (tree->right != NULL) {
                printf(",");
            }
            printtree(tree->right);
            printf(")");
        }
    }
}

/*
 -------------二叉树的遍历-----------------
 */

void _preorder(BTree *tree){
    
    if (tree != NULL) {
        
        printf("%i,",tree->data);
        
        _preorder(tree->left);
        _preorder(tree->right);
    }
}

//中序遍历
void _inorder(BTree *tree){
    
    if (tree != NULL) {
        _preorder(tree->left);
        printf("%i,",tree->data);
        _preorder(tree->right);
    }
}

//后序遍历
void _postorder(BTree *tree){
    
    if (tree != NULL) {
        _preorder(tree->left);
        _preorder(tree->right);
        printf("%i,",tree->data);
    }
}



