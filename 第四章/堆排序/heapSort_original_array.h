//
//  heapSort_original_array.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/22.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef heapSort_original_array_h
#define heapSort_original_array_h
template<typename T>
void __shiftDown(T arr[], int n, int k);

//第二次改进，原地堆排序，在原数组上进行堆排序，每次把第一个最大元素和数组尾部元素交换，最大元素就放到适当位置；然后再对交换的位置元素shiftDown()操作，变为maxheap；
//原地堆排序比之前两个要快一点，因为在原数组上操作，不需要开辟空间，也不用往新空间复制操作，节省时间；
template<typename T>
void heapSort(T arr[], int n){
    
    //heapity操作，生成maxheap；
    for(int i = (n-1)/2; i >= 0; i--)
        __shiftDown(arr,n,i);        //没法引用之前的Heap，所以要传入数组参数arr,n;
    
    for(int i = n-1;i > 0;i--){
        swap(arr[0],arr[i]);        //交换最大位置
        __shiftDown(arr,i,0);      //对arr[0]元素shiftDown操作，是arr[0,i]数组变成maxheap；
    }
}


//重新编写shiftDown函数，因为堆是从arr[1]开始的，数组是从0开始的，注意下标和节点之间的规律；
template<typename T>
void __shiftDown(T arr[], int n, int k){
    
    while(2*k+1 < n){     //判断当前条件是该节点有子节点，存在左节点即可
        int j = 2*k + 1;                              //在此轮循环，data[k]和data[j]交换位置；左节点和右节点谁大谁和data[k]交换
        if(j + 1 < n && arr[j+1] > arr[j])   //j表示左节点，如果右节点存在，且右节点大，k+1准备和右节点交换
            j += 1;
        if(arr[k] >= arr[j])
            break;
        
        swap(arr[k],arr[j]);
        k = j;
    }
}



#endif /* heapSort_original_array_h */
