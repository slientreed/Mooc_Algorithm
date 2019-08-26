//
//  quickSort_3Ways.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/20.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef quickSort_3Ways_h
#define quickSort_3Ways_h
#include"insertionSort.h"

//快排改进三：3路快速排序，对于有大量重复元素数组极其快。这里把整个数组在排序的过程中分成三步分;arr[l+1...lt] < v, arr[lt...i] == v, arr[gt...r] > v;
//其中arr[l]作为基准，arr[lt]是小于v的最后一个元素；arr[gt]是大于v的第一个元素；arr[i]为当前考察的元素；在把数组分成三块之后，后面继续递归，对小于v和大于v的两块子数组进行快速排序，而等于v的那一块元素已经在合适的位置上。


template <typename T>
void __quickSort_3Ways(T arr[] ,int l ,int r){

    if(r - l < 16){
    
        insertionSort(arr,l,r);
        return;
    }
    
    // Partition; 因为这里要返回两个位置值，C++在返回多个值时不方便，直接把partition()函数写一起完成排序子程序
    
    swap(arr[l] ,arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    
    int lt = l;         //arr[l+1...lt] < v
    int gt = r + 1;    // arr[gt...r] > v
    int i = l + 1;      // arr[lt+1...i) == v, arr[i]是当前的考察值
    while(i < gt){
        
        if(arr[i] < v){
            swap(arr[i], arr[lt+1]);  //注意刚开始arr[lt] == arr[l]，是基准值，最后一次交换arr[l]和arr[lt]即可，先不用考虑arr[l]
            lt++;
            i++;
        }
        else if(arr[i] > v){
            swap(arr[i],arr[gt-1]);
            gt--;
        }
        else
            i++;
    }
    swap(arr[l], arr[lt]);      //把基准值放到 等于v的位置
    
    __quickSort_3Ways(arr,l,lt-1);  //注意是lt-1,因为上一步没有对lt--，此时lt位置的值是等于v的
    __quickSort_3Ways(arr,gt,r);
}


template <typename T>
void quickSort_3Ways(T arr[], int n){

    srand(time(NULL));
    __quickSort_3Ways(arr, 0, n-1);
}


#endif /* quickSort_3Ways_h */
