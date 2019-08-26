//
//  main.cpp
//  Algorithm Learning
//
//  Created by mark on 2018/11/8.
//  Copyright © 2018年 mark. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<cmath>
#include<cassert>


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
#include"Heap.h"
#include"heapSort.h"
#include"heapSort_original_array.h"

using namespace std;

int main() {
    
    int n = 1000000;
    
    // 测试1 一般性数组测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);
    int* arr3 = SortTestHelper::copyIntArray(arr1,n);
    
    SortTestHelper::testSort("heapSort",heapSort,arr1,n);
    SortTestHelper::testSort("heapSort1", heapSort1, arr2, n);
    SortTestHelper::testSort("heapSort2", heapSort2, arr3, n);
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    cout<<endl;
    
    // 测试2 测试近乎有序的数组
    cout<<"Test for nearly ordered array, size = "<<n<<endl;
    int* arr4 = SortTestHelper::generateNearlyOrderedArray(n,100);
    int* arr5 = SortTestHelper::copyIntArray(arr4, n);
    int* arr6 = SortTestHelper::copyIntArray(arr4, n);
    
    SortTestHelper::testSort("heapSort", heapSort, arr4, n);
    SortTestHelper::testSort("heapSort1", heapSort1, arr5, n);
    SortTestHelper::testSort("heapSort2", heapSort2, arr6, n);
    
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    
    cout<<endl;
    
    // 测试3 测试存在包含大量相同元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    int* arr7 = SortTestHelper::generateRandomArray(n,0,10);
    int* arr8 = SortTestHelper::copyIntArray(arr7, n);
    int* arr9 = SortTestHelper::copyIntArray(arr7, n);
    
    SortTestHelper::testSort("heapSort", heapSort, arr7, n);
    SortTestHelper::testSort("heapSort1", heapSort1, arr8, n);
    SortTestHelper::testSort("heapSort2", heapSort2, arr9, n);
    
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    
    return 0;
}
