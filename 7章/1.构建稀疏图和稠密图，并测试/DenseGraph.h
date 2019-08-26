//
//  DenseGraph.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/28.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef DenseGraph_h
#define DenseGraph_h

#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

//稠密图 - 使用邻接矩阵
class DenseGraph{

private:
    int n, m;    //n,m分别存放点数，边数
    bool directed;    //判断是否是有向图
    vector<vector<bool>> g;    //二维邻接矩阵，判断是否有边

public:
    DenseGraph(int n, bool directed ){        //构造函数
    
        this->n = n;     //顶点数n就是传来的n值
        this->m = 0;     //开始时每个图边数为0
        this->directed = directed;
        
        for(int i = 0; i < n; i++)
            g.push_back( vector<bool>(n, false) ); //在g里再放一个n维，初始值为false的向量；创建了一个n*n，名为g的矩阵，且矩阵初始值为false；
    }
    
    ~DenseGraph(){      //析构函数，没有new空间，不需要释放
    
    }
    
    int V(){       //返回图中有多少个顶点
        return n ;
    }
    
    int E(){      //返回图中有多少个边
        return m;
    }
    
    void addEdge(int v, int w ){
    
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);
        
        if( hasEdge(v,w)  )
            return;
        
        g[v][w] = true;
        if( !directed )
            g[w][v] = true;
        m++;
    }
    
    bool hasEdge(int v,int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        
        return g[v][w];
    }
    
    
    class adjIterator{
    private:
        DenseGraph &G;
        int v;
        int index;
        
    public:
        adjIterator(DenseGraph &graph, int v):G(graph){
            this->v = v;
            this->index = -1;
        }
        
        ~adjIterator(){
        
        }
        
        int begin(){
            index = -1;
            return next();
        }
        
        int next(){
            for(index += 1;index < G.V(); index++)
                if( G.g[v][index] )
                    return index;
            return -1;
        }
        
        bool end(){
            return index >= G.V();   //index是否大于顶点的个数 
        }
    };
};



#endif /* DenseGraph_h */
