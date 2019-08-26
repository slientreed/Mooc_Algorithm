//
//  SparseGraph.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/28.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef SparseGraph_h
#define SparseGraph_h

#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;

//稀疏图  - 邻接表存储

class SparseGraph{

private:
    int n, m;
    bool directed;
    vector<vector<int>> g;   //int类型，g[i]存储所有和i顶点相连的顶点编号
    
public:
    SparseGraph(int n, bool directed ){
    
        this->n = n;
        this->m = n;
        this->directed = directed;
        for(int i = 0; i < n; i++ )
            g.push_back( vector<int>() );  //初始化，每个g[i]里面都是空的向量 ；这里使用了向量存储（也可以使用链表，便于删除）
    }
    
    ~SparseGraph(){
    
    }
    
    int V(){
        return n;
    }
    
    int E(){
        return m;
    }
    
    void addEdge(int v, int w){
        
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);
        
        g[v].push_back(w);   //在v的邻接表中添加w进去
        if( !directed )
            g[w].push_back(v);
        
        m++;
    }
    
    bool hasEdge(int v, int w){
    
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        
        for( int i = 0 ; i < g[v].size() ; i ++ )
            if( g[v][i] == w )
                return true;
        return false;
    }
    
    
    class adjIterator{
    private:
        SparseGraph &G;   //存储图的引用
        int v;
        int index;    //显示迭代到哪里
    public:
        
        //迭代器的构造函数，第一个参数是图的引用，第二个参数是要迭代哪个顶点相邻的边
        adjIterator(SparseGraph &graph, int v):G(graph){      //G是一个引用，使用构造列表的方式初始化
            this->v = v;
            this->index = 0;
        
        }
        
        ~adjIterator(){
            
        }
        
        // 返回图G中与顶点v相连接的第一个顶点
        int begin(){
            index = 0;
            if( G.g[v].size() )
                return G.g[v][index];       //如果size不为0，返回g[v]中的第一个分量
            return -1;
        }
        
        // 返回图G中与顶点v相连接的下一个顶点
        int next(){       //当前迭代元素下一个元素
            index++;                       //index++，访问下一个元素
            if( G.g[v].size() )
                return G.g[v][index];
            return -1;
        }
        
        // 查看是否已经迭代完了图G中与顶点v相连接的所有顶点
        int end(){        //迭代是否结束
            return index >= G.g[v].size();       //是否越界
        }
        
        
    };
                
                
};


#endif /* SparseGraph_h */
