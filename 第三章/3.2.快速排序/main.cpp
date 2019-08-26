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
#include"selectionSort.h"
#include"insertionSort.h"
#include"bubbleSort.h"
#include"shellSort.h"
#include"mergeSort.h"
#include"mergeSort_BU.h"
#include"quickSort.h"
#include"quickSort_advance.h"
#include"quickSort_2Ways.h"
#include"quickSort_3Ways.h"

using namespace std;

int main() {
    
    
    int n = 1000000;
    
    // 测试1 一般性数组测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);
    int* arr3 = SortTestHelper::copyIntArray(arr1,n);
    
    SortTestHelper::testSort("mergeSort",mergeSort,arr1,n);
    SortTestHelper::testSort("quickSort_2Ways", quickSort_2Ways, arr2, n);
    SortTestHelper::testSort("quickSort_3Ways", quickSort_3Ways, arr3, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    cout<<endl;
    
    // 测试2 测试近乎有序的数组
    cout<<"Test for nearly ordered array, size = "<<n<<endl;
    int* arr4 = SortTestHelper::generateNearlyOrderedArray(n,100);
    int* arr5 = SortTestHelper::copyIntArray(arr4, n);
    int* arr6 = SortTestHelper::copyIntArray(arr4, n);
    
    SortTestHelper::testSort("Merge Sort", mergeSort, arr4, n);
    SortTestHelper::testSort("quickSort_2Ways", quickSort_2Ways, arr5, n);
    SortTestHelper::testSort("quickSort_3Ways", quickSort_3Ways, arr6, n);
    
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    
    cout<<endl;
    
    // 测试3 测试存在包含大量相同元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    int* arr7 = SortTestHelper::generateRandomArray(n,0,10);
    int* arr8 = SortTestHelper::copyIntArray(arr7, n);
    int* arr9 = SortTestHelper::copyIntArray(arr7, n);
    
    SortTestHelper::testSort("Merge Sort", mergeSort, arr7, n);
    SortTestHelper::testSort("quickSort_2Ways", quickSort_2Ways, arr8, n);
    SortTestHelper::testSort("quickSort_3Ways", quickSort_3Ways, arr9, n);
    
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    
    
    //SortTestHelper::testSort("bubbleSort",bubbleSort,arr2,n);
    //SortTestHelper::testSort("shellSort",shellSort,arr,n);
    //SortTestHelper::testSort("shellSort2",shellSort2,arr2,n);  //改进后的shell排序
    
    //SortTestHelper::testSort("mergeSort",mergeSort,arr,n);
    //SortTestHelper::testSort("mergeSort_BU", mergeSortBU, arr3, n);
    //SortTestHelper::testSort("quickSort", quickSort, arr, n);
    //SortTestHelper::testSort("quickSort_advance", quickSort_advance, arr2, n);
    //SortTestHelper::testSort("quickSort_2Ways", quickSort_2Ways, arr2, n);
    //SortTestHelper::testSort("quickSort_3Ways", quickSort_3Ways, arr3, n);
    
    //SortTestHelper::printArray(arr, n);    //显示排序后的结果
    
    
    //int *arr2 = SortTestHelper::copyIntArray(arr, n);    //因为排序函数在数组中原地进行了排序，改变了测试数组，所以要拷贝一个一样的数据进行不同算法对比；
    //int *arr3 = SortTestHelper::copyIntArray(arr, n);
    
        //通过对比发现，插入排序比选择排序还慢，因为插入排序中有大量的swap操作，一个swap相当于三次赋值，所以要简化，具体看insertionSort2()函数；
    //SortTestHelper::testSort("selectionSort", selectionSort, arr,n);
    //SortTestHelper::testSort("insertionSort", insertionSort, arr2,n);
    //SortTestHelper::testSort("insertionSort2", insertionSort, arr4,n);
    
    //delete[] arr;
    //delete[] arr2;
    //delete [] arr3;
    //delete [] arr4;
    //delete [] arr5;
     return 0;
    }
