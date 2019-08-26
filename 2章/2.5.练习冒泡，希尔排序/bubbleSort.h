//
//  bubbleSort.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/15.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef bubbleSort_h
#define bubbleSort_h


//冒泡排序算法
template<typename T>
void bubbleSort(T arr[],int n){
    
    while(n > 0){
        for(int j = 1;j < n;j++){
            if(arr[j] < arr[j-1])
                swap(arr[j],arr[j-1]);
        }
        
        n--;   //每次不用比较最后一个元素
    }
}






#endif /* bubbleSort_h */
