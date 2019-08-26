//
//  quickSort_advance.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/20.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef quickSort_advance_h
#define quickSort_advance_h
#include"insertionSort.h"

/*
 这个程序是对快速排序的优化：(1.数组接近有序情况；2.数组有大量重复元素情况)
 1.第一个优化：当接近于 r-l 比较小，趋向于有序的时候，选用直接插入排序
 2.快速排序有个问题，当排序数组是接近有序的时候，时间复杂度会变为O(n^2).因为快排和归并类似，也是不断把数组分成两段，在分别排序；
   但是归并永远是平均分成两段，分段复杂度O(logn),每段内的时间复杂度是O(n),总的是Nlog(n);但是快排如果完全有序，每次选取第一个元素作为基准，则分段是O(n),每段内是O(n)，复杂度是O(n^2);为了解决这个问题，可以随机选取一个元素作为基准，这样复杂度期望就是O(Nlog(n))了；
 
 */


//对arr[l...r]操作，返回p位置，使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition2(T arr[], int l, int r){
    
    swap(arr[l], arr[rand()%(r-l+1)+l]);   // 改进二：随机选取元素作为和arr[l]交换，作为基准
    T v = arr[l];
    
    int j = l;
    for(int i = l+1; i <= r; i++){
        
        if(arr[i] < v){
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    
    swap(arr[l], arr[j]);
    return j;
}



//递归调用的排序子函数，对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort2(T arr[], int l, int r){
    
    //if( l >= r)
      //  return ;
    
    if(r - l < 16){             //改进一：当r-l子数组小到一定时，默认有序，用插入排序
        insertionSort(arr, l, r);
        return;
    }
    
    int p = __partition2(arr,l,r);
    __quickSort2(arr,l,p-1);
    __quickSort2(arr,p+1,r);
}



template <typename T>
void quickSort_advance(T arr[], int n){
    
    srand(time(NULL)); //改进二：随机选取基准
    __quickSort2(arr,0,n-1);
}



#endif /* quickSort_advance_h */
