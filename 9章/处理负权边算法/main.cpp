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
#include "KruskalMST.h"
#include "Dijkstra.h"
#include "BellmanFord.h"

using namespace std;



int main(){
    

    string filename = "/Users/mark/Desktop/testG3.txt";
    //string filename = "testG_negative_circle.txt";
    int V = 5;
    
    SparseGraph<int> g = SparseGraph<int>(V, true);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);
    
    cout<<"Test Bellman-Ford:"<<endl<<endl;
    
    int s = 0;
    BellmanFord<SparseGraph<int>, int> bellmanFord(g, s);
    if( bellmanFord.negativeCycle() )
        cout<<"The graph contain negative cycle!"<<endl;
    else
        for( int i = 0 ; i < V ; i ++ ) {
            if(i == s)
                continue;
            
            if (bellmanFord.hasPathTo(i)) {
                cout << "Shortest Path to " << i << " : " << bellmanFord.shortestPathTo(i) << endl;
                bellmanFord.showPath(i);
            }
            else
                cout << "No Path to " << i << endl;
            
            cout << "----------" << endl;
        }
    
    return 0;
}
