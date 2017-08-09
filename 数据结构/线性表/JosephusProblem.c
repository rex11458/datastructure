//
//  JosephusProblem.c
//  DataStructure
//
//  Created by LiuRex on 2017/8/1.
//  Copyright © 2017年 Shanghai Youyou Finance Information Technology Co.,Ltd. All rights reserved.
//

/*
 *  求解约瑟夫问题：n只猴子要选大王，选举方法是：所有猴子按1，2，3....,n编号围坐一圈，
 *  从第一个开始按1，2，3...,m报数，凡报到m号的退出圈外如此循环报数，直到圈内剩下一只猴
 *  子时，这是猴子就是大王。m、n由键盘输入。
 */

#include "JosephusProblem.h"
static int const MAX_SIZE = 50;


void josephus_problem()
{
    int m,n,i,d = 0,count;
    
    printf("总个数：\n");
    scanf("%i",&n);
    printf("退出圈外号码：\n");
    
    scanf("%i",&m);
    
    int A[MAX_SIZE];

    printf("出队前：");
    for (int i = 0; i < n; i++) {
        A[i] = i+1;
        printf("%i,",A[i]);
    }
    printf("\n");
    printf("出队后：");
    d = 0;
    count = 0;
    while (d < n) {
    
        for (i = 0; i < n; i++) {
         
            if (A[i] != 0) {
             
                count++;
                if (count == m) {
                    printf("%d,",A[i]);
                    A[i] = 0;
                    count = 0;
                    d++;
                }
            }
        }
    }
    printf("\n");

}
