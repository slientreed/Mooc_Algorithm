//
//  main.cpp
//  Algorithm Learning
//
//  Created by mark on 2018/11/8.
//  Copyright © 2018年 mark. All rights reserved.
//

//该main文件主要用于测试数组生成的.h文件

#include <iostream>

#include"SortTestHelper.h"  //双引号可以，<>不行；
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n = 1000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    
    SortTestHelper::printArray(arr, n);
    
    delete[] arr;  //使用delete把new的空间释放，由于arr是数组，用delete[];
    
    return 0;
}
