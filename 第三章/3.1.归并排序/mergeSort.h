//
//  mergeSort.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/19.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef mergeSort_h
#define mergeSort_h
#include"insertionSort.h"

//自顶向下的归并排序方法，进行递归

//将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l , int mid , int r ){

    T aux[r - l + 1];     //创建一个临时空间aux，把当前arr中的元素全都复制进去；
    for( int i = l; i <= r; i++){
    
        aux[i-l] = arr[i];
    }
    int i = l,j = mid + 1;     //i,j分别指向两个子数组开头位置
    for(int k = l; k <= r;k++){
    
        if(i > mid){            //用i判断第一个子数组是否到尾
        
            arr[k] = aux[j-l];
            j++;
        }
        else if(j > r){       //用j判断第二个子数组是否到尾
        
            arr[k] = aux[i-l];
            i++;
        }
        else if(aux[i-l] < aux[j-l] ){   //比较两个子数组相应位置的大小
        
            arr[k] = aux[i-l];
            i++;
        }
        else{
            arr[k] = aux[j-l];
            j++;
        }
    }
}


//mergeSort()函数递归使用的归并子函数进行排序，对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l ,int r){     //注意参数，边界问题

    if(l >= r)
        return;
    
  /*                        //第二个优化：当子序列比较小的时候，默认比较有序，直接使用插入排序会提高速度；
    if(r - l < 16){         //子序列多大时候采用直接插入排序，是个思考的问题
    
        insertionSort(arr, l,r);
        return;
    }
    */
    
    int mid = (l+r) / 2;     //（l+r）导致溢出怎么办？
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if(arr[mid] > arr[mid+1] )  //第一个优化：我们保证了两个子序列是有序的，当arr[mid] < arr[mid+1]时候，说明这两个子序列放在一起也已经有序了，不用在进行递归合并
        __merge(arr,l,mid,r);   //所以如果数组基本有序，效率不高；改进后对上面两个__mergeSort()已经排序好的两部分进行一次merge()操作，完成整个归并排序
}

template<typename T>
void mergeSort(T arr[],int n){

    __mergeSort(arr, 0 , n-1 );       //merge本质是一个连续递归，表示私有函数，被mergeSort()函数调用，不要被用户调用;参数是字符串，开始位置，结束位置
}



#endif /* mergeSort_h */
