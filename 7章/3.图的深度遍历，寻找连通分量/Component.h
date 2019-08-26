//
//  Component.h
//  Algorithm Learning
//
//  Created by mark on 2018/12/1.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef Component_h
#define Component_h

#include <iostream>
#include <cassert>
using namespace std;


#include<iostream>
#include<cassert>
using namespace std;

//使用深度优先遍历方法，可以求得图中的连通分量，因为一个连通分量在深度优先遍历过程中
template <typename Graph>
class Component{
    
private:
    Graph &G;      //所有的图的操作都设置成了一个Graph模板，这里定义一个Graph模板类
    bool *visited;  //记录节点是否被访问过
    int ccount;     //记录一个图中有多少个连通分量
    int* id;        //记录每两个节点是否相连，相连的节点id取相同的值
    void dfs( int v){
        visited[v] = true;
        id[v] = ccount;               //在每次调用dfs时，给id赋ccount的值，这样每次相同的联通分量的id会被赋相同的值
        typename Graph::adjIterator adj(G,v);      //使用Iterator遍历v的所有节点；typename说明Graph是一个类型而不是成员变量
        for( int i = adj.begin(); !adj.end(); i = adj.next() ){
            if(!visited[i])
                dfs(i);
        }
    }
    
public:
    Component(Graph &graph):G(graph){    //构造函数，初始化G
        visited = new bool[G.V()];    //给visited数组开辟空间，大小为图的大小；
        id = new int[G.V()];
        ccount = 0;
        for(int i = 0; i < G.V();i++){  //初始化visited数组
            visited[i] = false;
            id[i] = -1;
        }
        
        for(int i = 0; i < G.V();i++){
            if(!visited[i] ){
                dfs(i);         //如果当前节点没有访问过，则dfs深度遍历该节点；如果已经遍历过，则存在于另外的连通分量中；
                ccount++;      //记录图中有多少个连通分量
            }
        }
    }
    
    ~Component(){
        delete[] visited;
        delete[] id;
    }
    
    int count(){         //用户在调用时，调用完构造函数， 运行到这里，返回ccount,得到有几个连通分量
        return ccount;
    }
    
    bool isConnected(int v, int w){         //检查两个节点之间是否相连，但是没法给出路径
        assert( v >= 0 && v < G.V() );
        assert( w >= 0 && w < G.V() );
        return id[v] == id[w];
    }
};


#endif /* Component_h */
