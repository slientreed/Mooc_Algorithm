//
//  main.cpp
//  Algorithm Learning
//
//  Created by mark on 2018/11/8.
//  Copyright © 2018年 mark. All rights reserved.
//

#include <iostream>
#include<algorithm>

#include"Student.h"
#include"SortTestHelper.h"  //双引号可以，<>不行；
using namespace std;


//选择排序算法，O(n^2)
template<typename T>        //使用模板函数，之后函数中的类型可以自由定义为多种,int,float,string等,使得我们的算法更加灵活
void selectionSort(T arr[],int n){
    for(int i = 0;i < n;i++){
        //寻找[i，n)区间内的最小值；
        int minIndex = i;         //当前最最小值的索引；
        for(int j = i + 1;j < n;j++){    //找到当前[i，n）区间内的最小值索引；
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);   //交换当前位置和最小值的位置索引。swap是当前c++标准库的函数
    }
    
}

int main() {
    
    int n = 1000;
    int *arr = SortTestHelper::generateRandomArray(n,0, n);
    
    SortTestHelper::testSort("selectionSort", selectionSort, arr,n);
    delete[] arr;
    
    return 0;
    }
