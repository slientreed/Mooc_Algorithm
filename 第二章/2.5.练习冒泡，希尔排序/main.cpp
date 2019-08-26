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

using namespace std;

int main() {
    
    /*
    int n = 3;
    int arr[n];
    arr[0] = 3;
    arr[1] = 2;
    arr[2] = 1;
    */
    
    
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    
    //SortTestHelper::testSort("bubbleSort",bubbleSort,arr2,n);
    SortTestHelper::testSort("shellSort",shellSort,arr,n);
    SortTestHelper::testSort("shellSort2",shellSort2,arr2,n);
    
    //SortTestHelper::printArray(arr, n);
    
    
    //int *arr2 = SortTestHelper::copyIntArray(arr, n);    //因为排序函数在数组中原地进行了排序，改变了测试数组，所以要拷贝一个一样的数据进行不同算法对比；
    //int *arr3 = SortTestHelper::copyIntArray(arr, n);
    
        //通过对比发现，插入排序比选择排序还慢，因为插入排序中有大量的swap操作，一个swap相当于三次赋值，所以要简化，具体看insertionSort2()函数；
    //SortTestHelper::testSort("selectionSort", selectionSort, arr,n);
    //SortTestHelper::testSort("insertionSort", insertionSort, arr2,n);
    //SortTestHelper::testSort("insertionSort2", insertionSort2, arr3,n);
    
    //delete[] arr;
    //delete[] arr2;
    return 0;
    }
