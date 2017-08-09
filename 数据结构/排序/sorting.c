//
//  sort.c
//  数据结构
//
//  Created by LiuRex on 2017/8/8.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "sorting.h"

void printresult(int r[],int n){
    for (int i = 0; i < n; i++) {
        printf("%i,",r[i]);
    }
    printf("\n");
}


/*
 *  插入排序
 */

void insertsort(int r[],int n){
    int i,j;
    int temp = r[0];
    for (i = 1; i < n; i++) {
        j = i - 1;
        temp = r[i];
        while (temp < r[j] && j >= 0) {
            
            r[j+1] = r[j];
            j--;
        }
        r[j + 1] = temp;
        printresult(r,n);
    }
    
}


/*
 *  希尔排序
 */
void shellsort(int r[],int n)
{
    int d = n / 2;
    int i,j;
    int temp = r[0];
    while (d > 0) {
        
        for (i = d; i < n; i ++) {
            j = i - d;
            temp = r[i];
            while (temp < r[j] && j >= 0) {
                
                r[j+d] = r[j];
                j-=d;
            }
            r[j + d] = temp;
        }
        printresult(r,n);

        d = d / 2;
    }
    
}


void selectsort(int r[],int n){
    
    int k = 0;
    
    for (int i = 0; i < n; i++) {
        k = i;
        for (int j = i + 1; j < n; j++) {
            
            if (r[j] < r[k] ) {
                k = j;
            }
        }
        
        int min = r[k];
        r[k] = r[i];
        r[i] = min;
        printresult(r,n);

    }
}

void bubblesort(int r[],int n){
    
    
    for (int i = 0; i < n; i++) {
        
        for (int j = n - 1; j > i; j--) {
            
            if (r[j] < r[j - 1]) {
                
                int temp = r[j];
                r[j] = r[j - 1];
                r[j - 1] = temp;
                printresult(r,n);
            }

        }
    }
}


void fastsort(int r[],int start,int end){
    
    int i = start,j = end;
    
    int temp = r[start];
    
    while (i < j) {
        
        while (j > i && temp < r[j]) j--;
        
        if (i < j) {
            r[i] = r[j];i++;
        }
        
        while (i < j && r[i] < temp) i++;
        if (i < j) {
            r[j] = r[i];j--;
        }
    }
    
    r[i] = temp;
    
    
    if (start < i)  fastsort(r,start,j - 1);
    
    if (i < end)  fastsort(r,j+1,end);
    
}


void mergepass(int r[],int r1[],int n,int l){
    
}

void combinesort(int r[],int r1[],int n){
    
}








