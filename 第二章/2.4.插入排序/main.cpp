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


//插入排序算法，O(n^2)，在近乎有序的数组中，插入排序效率极高，一个完全有序的数组可以达到O(n)；
template<typename T>        //使用模板函数，之后函数中的类型可以自由定义为多种,int,float,string等,使得我们的算法更加灵活
void insertionSort(T arr[],int n){
    for(int i = 1;i < n;i++){
        
        //寻找元素arr[i]的合适插入位置
        for(int j = i;j > 0;j--){  //最多j考察到arr[1]
            if( arr[j] < arr[j - 1])
                swap(arr[j],arr[j-1]);
            else
                break;         //第二次循环找到当前i的合适位置，结束；
        }
    }
}

template<typename T>
void insertionSort2(T arr[],int n){
    for(int i = 1;i < n;i++){
        
        T e = arr[i];   //每次保存当前arr[i],向前比较，不交换，如果arr[i-1]大，直接把arr[i-1]赋值给arr[i],最后找e的位置赋值即可，省去swap操作
        int j;
        for(j = i;j > 0 && arr[j-1] > e;j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}


int main() {
    
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);    //因为排序函数在数组中原地进行了排序，改变了测试数组，所以要拷贝一个一样的数据进行不同算法对比；
    int *arr3 = SortTestHelper::copyIntArray(arr, n);
    
    //通过对比发现，插入排序比选择排序还慢，因为插入排序中有大量的swap操作，一个swap相当于三次赋值，所以要简化，具体看insertionSort2()函数；
    SortTestHelper::testSort("selectionSort", selectionSort, arr,n);
    SortTestHelper::testSort("insertionSort", insertionSort, arr2,n);
    SortTestHelper::testSort("insertionSort2", insertionSort2, arr3,n);
    
    delete[] arr;
    delete[] arr2;
    return 0;
    }
