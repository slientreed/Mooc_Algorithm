//
//  main.cpp
//  Algorithm Learning
//
//  Created by mark on 2018/11/8.
//  Copyright © 2018年 mark. All rights reserved.
//

#include<iostream>
#include<assert.h>
#include "SparseGraph.h"
#include "DenseGraph.h"

using namespace std;



int main(){
    
    int N = 20;   //20个节点，100条边
    int M = 100;
    
    srand( time(NULL) );
    
    //Sparse Graph
    SparseGraph g1(N, false);      //生成N个节点的稀疏图
    for( int i = 0; i < M; i++){   //循环M次，每次都随机把a,b两个节点添加到一条边
    
        int a = rand()%N;
        int b = rand()%N;
        g1.addEdge(a,b);
    }
    
    for(int v = 0; v < N; v++){     //遍历N个节点
        cout<<v<<" : ";
        SparseGraph::adjIterator adj(g1,v);    //对于每个节点，都声明一个g1这个图对于v这个节点的迭代器
        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
            cout<<w<<" ";
        cout<<endl;
    }
    
    
    // Dense Graph
    DenseGraph g2(N , false);
    for( int i = 0 ; i < M ; i ++ ){
        int a = rand()%N;
        int b = rand()%N;
        g2.addEdge( a , b );
    }
    
    // O(V^2)
    for( int v = 0 ; v < N ; v ++ ){
        cout<<v<<" : ";
        DenseGraph::adjIterator adj( g2 , v );
        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
            cout<<w<<" ";
        cout<<endl;
    }
    
    
    return 0;
}
