//
//  quickSort_2Ways.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/20.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef quickSort_2Ways_h
#define quickSort_2Ways_h


//快速排序改进2：2路快速排序
//快速排序中，如果有大量重复排序，__partition2函数又会把数组分成两个极不平衡的数组，是的复杂度退化为O(n^2);改进使用2路快速排序，把小于基准元素v的值arr[i]和大于v的元素arr[j]分别放在两端，i向后走到碰到不小于v的，j向前走到碰到不大于v的，然后交换arr[i]和arr[j];i,j再各加1，继续判断；这样就把等于v的平分成两部分，两个子数组大小平衡。


//对arr[l...r]操作，返回p位置，使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition3(T arr[], int l, int r){
    
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    
    //改进三：使得大于等于v和小于等于v的元素分成平衡的两块
    // arr[l+1...i) <= v; arr(j...r] >= v
    int i = l + 1, j = r;
    while(true){
        while(i <= r && arr[i] < v) i++;
        while(j >= l + 1 && arr[j] > v) j--;
        if(i > j) break;     //循环结束，跳出
        swap(arr[i] ,arr[j] );   //循环没结束，交换arr[i]和arr[j]值，使得分成两块
        i++;
        j--;
    }
    swap(arr[l],arr[j]);  //把v放到位置上使得j前面位置元素都 <= v;后面元素都 >= v;
    return j;
}


//递归调用的排序子函数，对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort3(T arr[], int l, int r){
    
    //if( l >= r)
    //  return ;
    
    if(r - l < 16){
        insertionSort(arr, l, r);
        return;
    }
    
    int p = __partition3(arr,l,r);
    __quickSort3(arr,l,p-1);
    __quickSort3(arr,p+1,r);
}



template <typename T>
void quickSort_2Ways(T arr[], int n){
    
    srand(time(NULL));
    __quickSort3(arr,0,n-1);
}




#endif /* quickSort_2Ways_h */
