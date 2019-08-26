//
//  quickSort.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/19.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef quickSort_h
#define quickSort_h


//对arr[l...r]操作，返回p位置，使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r){

    T v = arr[l];
    
    // arr[l+1...j] < v;arr[j+1...i] > v
    int j = l;    //j的目的是作为分界点，作为最后arr[l]的位置，也是我们要返回的值
    for(int i = l+1; i <= r; i++){
        
        if(arr[i] < v){
            swap(arr[j+1],arr[i]);  // i为当前正在考察的元素位置，j位置之后的值都大于arr[v],之前位置的值都小于v
            j++;
        }
    }
    
    swap(arr[l], arr[j]);  //把基准值arr[l]放到位置上去
    return j;
}


//递归调用的排序子函数，对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r){

    if( l >= r)
        return ;
    
    int p = __partition(arr,l,r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}



template <typename T>
void quickSort(T arr[], int n){

    __quickSort(arr,0,n-1);     //内部调用函数，递归调用
}



#endif /* quickSort_h */
