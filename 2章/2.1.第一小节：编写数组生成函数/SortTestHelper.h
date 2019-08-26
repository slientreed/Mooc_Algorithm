//
//  SortTestHelper.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/8.
//  Copyright © 2018年 mark. All rights reserved.
//

//该.h文件编写了两个生成数组所用函数

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
    
    
    
}
#endif /* SortTestHelper_h */
