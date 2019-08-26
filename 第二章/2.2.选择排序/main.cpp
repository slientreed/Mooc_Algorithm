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
    
    int a[10] = {10,9,8,7,6,5,4,3,2,1};  //排序int类型
    selectionSort(a, 10);
    SortTestHelper::printArray(a, 10);
    
    float b[4] = {4.4,4.3,2.3,1.3};   //排序float类型
    selectionSort(b, 4);
    SortTestHelper::printArray(b, 4);
    
    string c[4] = {"f","c","e","a"};   //排序string类型
    selectionSort(c, 4);
    SortTestHelper::printArray(c, 4);
    
    // 测试模板函数，传入自定义结构体Student数组
    Student d[4] = { {"D",90} , {"C",100} , {"B",95} , {"A",95} };
    selectionSort(d,4);
    SortTestHelper::printArray(d, 4);
    
    return 0;
    }
