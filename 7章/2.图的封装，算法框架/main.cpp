//
//  main.cpp
//  Algorithm Learning
//
//  Created by mark on 2018/11/8.
//  Copyright © 2018年 mark. All rights reserved.
//

#include<iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

using namespace std;



int main(){
    
    // 使用两种图的存储方式读取testG1.txt文件
    string filename = "/Users/mark/Desktop/慕课网视频学习笔记（12.学好算法和数据结构）/1.程序/Algorithm Learning/Algorithm Learning/testG1.txt";
    SparseGraph g1( 13 , false );
    ReadGraph<SparseGraph> readGraph1( g1 , filename );
    cout<<"test G1 in Sparse Graph:" << endl;
    g1.show();
    cout<<endl;
    
    
    
    DenseGraph g2(13, false);
    ReadGraph<DenseGraph> readGraph2(g2 , filename);
    g2.show();
    
    
    return 0;
}
