//
//  heapSort.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/22.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef heapSort_h
#define heapSort_h
#include"Heap.h"

//生成一个堆，根据数组元素一个一个插入生成；
template<typename T>
void heapSort1(T arr[], int n){
    
    MaxHeap<T> maxheap = MaxHeap<T>(n);  //开辟额外的堆空间
    for( int i = 0;i < n;i++)
        maxheap.insert(arr[i]);
    
    for(int i = n-1;i >= 0;i--)
        arr[i] = maxheap.extractMax();
}


//改进后的heapSort，和上一个生成堆的方式不同，从第一个非叶子节点开始shiftDown(),保持最大堆；
template<typename T>
void heapSort2(T arr[], int n){
    
    MaxHeap<T> maxheap = MaxHeap<T>(arr,n);
    for(int i = n-1;i >= 0;i--)
        arr[i] = maxheap.extractMax();
}


#endif /* heapSort_h */
