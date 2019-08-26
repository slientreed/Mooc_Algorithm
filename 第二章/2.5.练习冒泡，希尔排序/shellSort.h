//
//  shellSort.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/17.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef shellSort_h
#define shellSort_h

//shell排序分两步：选取间隔，然后在间隔下执行简单插入排序。
//1.shell的间隔如果每次都选n/2,则最坏情况会使O(n^2)，因为2的间隔不是互质的；所以可以选取 gap = 2^k -1；
//2.间隔下的插入排序和简单插入排序不同。有间隔情况下每次循环不是只交换相邻元素，而是可以交换相间隔元素，一次i的for循环完成所有间隔区间内的简单插入；然后改变间隔，直到间隔为0。


//gap取 n/2，然后每次取gap/2的情况
template <typename T>
void shellSort(T arr[],int n){

    int gap,i,j;
    for(gap = n/2;gap > 0;gap /= 2){    //选取不同的间隔
    
        //下面就是insertSort，不同的是插入排序只能交换相邻的元素，shell使得每次交换间隔的元素
        for(i = gap;i < n;i++){
            T e = arr[i];
            for(j = i;j >= gap && e < arr[j-gap];j -= gap){   //想不明白把这个走一遍就知道了
            
                arr[j] = arr[j-gap];
            }
            arr[j] = e;
        }
    }
}


//改变gap的情况;参考：
//https://github.com/liuyubobobo/Play-with-Algorithms/blob/master/02-Sorting-Basic/Course%20Code%20(C%2B%2B)/Optional-03-Shell-Sort/main.cpp#L32

template<typename T>
void shellSort2(T arr[], int n){
    // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int h = 1;
    while( h < n/3 )
        h = 3 * h + 1;
    
    while( h >= 1 ){
        
        // h-sort the array
        for( int i = h ; i < n ; i ++ ){
            
            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
            T e = arr[i];
            int j;
            for( j = i ; j >= h && e < arr[j-h] ; j -= h )
                arr[j] = arr[j-h];
            arr[j] = e;
        }
        
        h /= 3;
    }
}



#endif /* shellSort_h */
