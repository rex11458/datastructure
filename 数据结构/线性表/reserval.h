//
//  reserval.h
//
//
//  Created by LiuRex on 2017/8/1.
//  Copyright © 2017年 Shanghai Youyou Finance Information Technology Co.,Ltd. All rights reserved.
//

#ifndef reserval_h
#define reserval_h

#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

void reserval(struct Node *p);

#endif /* reserval_h */
