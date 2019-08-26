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
#include "Component.h"
#include "Path.h"
#include "ShortPath.h"

using namespace std;



int main(){
    

    /*
    // TestG1.txt - g1 and g2
    string filename1 = "/Users/mark/Desktop/慕课网视频学习笔记（12.学好算法和数据结构）/1.程序/Algorithm Learning/Algorithm Learning/testG1.txt";
    SparseGraph g1 = SparseGraph(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename1);
    Component<SparseGraph> component1(g1);
    cout<<"TestG1.txt, Using Sparse Graph, Component Count: "<<component1.count()<<endl;
    */
    
    string filename2 = "/Users/mark/Desktop/慕课网视频学习笔记（12.学好算法和数据结构）/1.程序/Algorithm Learning/Algorithm Learning/testG2.txt";
    SparseGraph g = SparseGraph(7, false);
    ReadGraph<SparseGraph> readGraph(g, filename2);
    g.show();
    cout<<endl;
    
    Path<SparseGraph> path(g,0);
    cout<<"Path from 0 to 6 : " << endl;
    cout<<" DFS:";
    path.showPath(6);
     
    ShortPath<SparseGraph> bfs(g,0);
    cout<<" BFS：";
    bfs.showPath(6);
    
    
    return 0;
}
