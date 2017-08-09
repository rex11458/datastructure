//
//  search.c
//  数据结构
//
//  Created by LiuRex on 2017/8/9.
//  Copyright © 2017年 LiuRex. All rights reserved.
//

#include "search.h"

int seqsearch(int r[],int k,int n){
    

    for (int i = 0; i < n; i++) {
        
        if (r[i] == k) {
            return i;
        }
    }
    
    return -1;
}

int binsearch(int r[],int k,int n){
    
    int i = -1,low = 0,high = n,mid;
    
    while (low <= high && i != -1) {
    
        mid = (low + high) / 2;
        
        if (k < r[mid]) {
            high = mid - 1;
        }else if (k > r[mid]){
            low = mid + 1;
        }else{
            i = mid;
        }
    }

    return i;
}


int blksearch(int r[],struct indexterm idx[],int k,int bn){

    int i = -1,low1 = 1,high1 = bn,mid1,hb;
    
    while (low1 < high1 && i != -1) {
        
        mid1 = (low1 + high1) / 2;
        if (k < idx[mid1].key) {
            high1 = mid1 - 1;
        }else if(k > idx[mid1].key){
            low1 = mid1 + 1;
        }else{
            high1 = mid1 - 1;
            i = mid1;
        }
    }
    
    
    if (low1 < bn) {
        i = idx[low1].low;
        hb = idx[low1].high;
    }
    
    
    for (int j = i; j < bn; j++) {
        
        if (r[j] == k) {
            return j;
        }
    }
    
    
    
    
    return i;
}
