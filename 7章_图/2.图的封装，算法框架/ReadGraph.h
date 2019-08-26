//
//  ReadGraph.h
//  Algorithm Learning
//
//  Created by mark on 2018/12/1.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef ReadGraph_h
#define ReadGraph_h

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cassert>

using namespace std;

//从文件中把我们的测试用例读取到程序中
//把图的算法封装到一个模板类类中，抽象为graph，稀疏图和稠密图都可以
template <typename Graph>
class ReadGraph{

public:
    ReadGraph(Graph &graph, const string &filename){    //构造函数，传入一个图和一个文件名称（引用）
    
        ifstream file(filename);     //把filename读进file中来
        string line;             //一行行读取
        int V ,  E;
        
        assert( file.is_open() );   //保证file文件被打开
        
        assert( getline(file, line) );      //读取文件中的第一行
        stringstream ss(line);       //把line这行字符串放到stringstream中
        ss>>V>>E;             //把stringstream相应的解析出V，E
        
        assert( V == graph.V() );  //确认文件里读出的节点数V，和我们图的点数一致；
        
        for(int i = 0; i < E; i++){     //循环E次，每次读取文件中的一行
        
            assert( getline(file,line) );  //读取文件中的一行
            stringstream ss(line);
            
            int a,b;
            ss>>a>>b;                   //把ss中变量放入a,b中，在a，b两个之间建立一个节点
            assert( a >= 0 && a < V);
            assert( b >= 0 && b < V);
            graph.addEdge(a,b);
            
        }
        
    }
    
};


#endif /* ReadGraph_h */
