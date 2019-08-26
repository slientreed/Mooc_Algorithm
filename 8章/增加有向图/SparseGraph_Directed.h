//
//  SparseGraph_Directed.h
//  Algorithm Learning
//
//  Created by mark on 2018/12/5.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef SparseGraph_Directed_h
#define SparseGraph_Directed_h

#include<iostream>
#include<vector>
#include<assert.h>
#include "Edge.h"

using namespace std;

//稀疏图  - 邻接表存储
template <typename Weight>
class SparseGraph{
    
private:
    int n, m;
    bool directed;
    vector<vector<Edge<Weight> *>> g;   //Edge<Weight>类型的指针，g[i]存储所有和i顶点相连的顶点编号
    
public:
    SparseGraph(int n, bool directed ){
        
        this->n = n;
        this->m = n;
        this->directed = directed;
        for(int i = 0; i < n; i++ )
            g.push_back( vector<Edge<Weight> *>() );  //初始化，每个g[i]里面都是空的向量 ；这里使用了向量存储（也可以使用链表，便于删除）
    }
    
    ~SparseGraph(){    //析构函数，释放开辟的空间
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < g[i].size();j++)
                delete g[i][j];
        }
    }
    
    int V(){
        return n;
    }
    
    int E(){
        return m;
    }
    
    void addEdge(int v, int w, Weight weight){
        
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);
        
        g[v].push_back(new Edge<Weight>(v,w,weight));   //在v的邻接表中添加w进去
        if( !directed )
            g[w].push_back(new Edge<Weight>(w, v , weight));
        
        m++;
    }
    
    bool hasEdge(int v, int w){
        
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        
        for( int i = 0 ; i < g[v].size() ; i ++ )
            if( g[v][i]->other(v) == w )    //看是否存在一条从v到w的边
                return true;
        return false;
    }
    
    void show(){     //把图以邻接表的形式打印出来
        
        for(int i = 0;i < n;i++){
            cout<<"vertex"<<i<<":\t";
            for(int j = 0;j < g[i].size();j++)
                cout<<"( to:"<<g[i][j]->w()<<",wt:"<<g[i][j]->wt()<<")\t";   //打印出来到哪条边，以及权重
            cout<<endl;
        }
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
        Edge<Weight>* begin(){
            index = 0;
            if( G.g[v].size() )
                return G.g[v][index];       //如果size不为0，返回g[v]中的第一个分量
            return NULL;
        }
        
        // 返回图G中与顶点v相连接的下一个顶点
        Edge<Weight>* next(){       //当前迭代元素下一个元素
            index++;                       //index++，访问下一个元素
            if( G.g[v].size() )
                return G.g[v][index];
            return NULL;
        }
        
        // 查看是否已经迭代完了图G中与顶点v相连接的所有顶点
        int end(){        //迭代是否结束
            return index >= G.g[v].size();       //是否越界
        }
    };
};


#endif /* SparseGraph_Directed_h */
