//
//  main.cpp
//  Algorithm Learning
//
//  Created by mark on 2018/11/8.
//  Copyright © 2018年 mark. All rights reserved.
//

#include<iostream>
#include<iomanip>
#include "ReadGraph_Directed.h"
#include "DenseGraph_Directed.h"
#include "SparseGraph_Directed.h"

using namespace std;



int main(){
    


    string filename = "/Users/mark/Desktop/testG1.txt";
    int V = 8;          //有8个节点
    cout<<fixed<<setprecision(2);    //输出的精度是两位小数
    
    //测试稠密图
    DenseGraph<double> g1 = DenseGraph<double>(V,false);
    ReadGraph<DenseGraph<double>,double> readGraph1(g1, filename);
    g1.show();
    cout<<endl;
    
    //测试稀疏图
    SparseGraph<double> g2 = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>,double> readGraph2(g2, filename);
    g2.show();
    cout<<endl;
    
    
    
    return 0;
}
