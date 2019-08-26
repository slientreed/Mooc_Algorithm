//
//  SortTestHelper.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/8.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef SortTestHelper_h
#define SortTestHelper_h
#include<ctime>
#include<cassert>
using namespace std;
namespace SortTestHelper {      //放入新的命名空间中，方便之后调用里面函数
    
    //生成n个元素的随机数组，每个元素范围是[rangeL，rangeR]
    int* generateRandomArray(int n,int rangeL,int rangeR){
    
        assert(rangeL <= rangeR);
        int *arr = new int[n];     //new方式创建新的数组
        srand(time(NULL));   //设置随机种子，选取当前时间作为随机种子
        for(int i = 0;i < n;i++){
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
    
    
    //输出打印数组函数，main函数中可以直接调用
    template<typename T>  //把print函数声明为一个T类型的模板函数
    void printArray(T arr[],int n){
        for(int i = 0;i < n;i++){
        
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    
    //测试函数，测试排序算法的正确性
    template<typename T>
    bool isSorted(T arr[],int n){
    
        for(int i = 0;i < n - 1;i++){
        
            if(arr[i] > arr[i+1])
                return false;
        }
        return true;
    }
    
    
    //测试排序算法的程序的执行时间
    template<typename T>
    void testSort(string sortName,void(*sort)(T[],int),T arr[],int n){  //第二个参数传入排序算法本身，即传入排序函数的指针，第三个参数是测试用例，传入测试数组
    
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();
        assert( isSorted(arr,n));   //判断是否被正确排序
        cout << sortName << "排序用时: " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;  //打印排序所用的时间
        return;
    }
    
    
    //复制数组函数，为比较不同排序算法使用
    int* copyIntArray(int a[],int n){
    
        int *arr = new int[n];
        copy(a,a+n,arr);             //std中的copy函数，参数分别是：起始指针，结尾指针，要拷贝的数组指针
        return arr;
    }
    
}
#endif /* SortTestHelper_h */
