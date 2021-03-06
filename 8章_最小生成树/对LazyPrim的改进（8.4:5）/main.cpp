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
#include "LazyPrimMST.h"
#include "PrimMst.h"

using namespace std;



int main(){
    


    string filename = "/Users/mark/Desktop/testG1.txt";
    int V = 8;          //有8个节点
    cout<<fixed<<setprecision(2);    //输出的精度是两位小数
    
    
    SparseGraph<double> g = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph(g, filename);
    
    // Test Lazy Prim MST
    cout<<"Test Lazy Prim MST:"<<endl;
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
    vector<Edge<double>> mst = lazyPrimMST.mstEdges();
    for( int i = 0 ; i < mst.size() ; i ++ )
        cout<<mst[i]<<endl;
    cout<<"The MST weight is: "<<lazyPrimMST.result()<<endl;
    
    cout<<endl;
    
    // Test Prim MST
    cout<<"Test Prim MST:"<<endl;
    PrimMST<SparseGraph<double>, double> primMST(g);
    mst = primMST.mstEdges();
    for( int i = 0 ; i < mst.size() ; i ++ )
        cout<<mst[i]<<endl;
    cout<<"The MST weight is: "<<primMST.result()<<endl;
    
    
    cout<<endl;
    
    return 0;}
