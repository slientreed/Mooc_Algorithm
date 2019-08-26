//
//  mergeSort_BU.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/19.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef mergeSort_BU_h
#define mergeSort_BU_h
#include"mergeSort.h"         //用到其中的__merge()函数；

//自底向上的进行归并排序，只需要进行迭代，不用递归
//这个没有使用数组的特性通过索引直接获取元素，所以可以很方便的应用于链表的排序


template<typename T>
void mergeSortBU(T arr[], int n){

    for(int size = 1;size <= n;size += size){       //每次merge后，下次merge的小增加一倍，即使size增量是自身
        for(int i = 0;i+size < n; i += size + size)      //每次合并两个size大小数组，i的每次增量是2*size
            //对arr[i...i+size-1]和arr[i+size ... i+2*size-1]进行归并
            __merge(arr,i,i+size-1,min(i+size+size-1,n-1));   //当i+size+size-1 > n-1时，取n-1；
    }
}




#endif /* mergeSort_BU_h */
