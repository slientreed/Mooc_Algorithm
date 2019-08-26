//
//  DenseGraph_Directed.h
//  Algorithm Learning
//
//  Created by mark on 2018/12/5.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef DenseGraph_h
#define DenseGraph_h

#include<iostream>
#include<vector>
#include<cassert>
#include "Edge.h"

using namespace std;

//稠密图 - 使用邻接矩阵
template <typename Weight>
class DenseGraph{
    
private:
    int n, m;
    bool directed;
    vector<vector<Edge<Weight> *>> g;    //二维空间存储Edge<Weight>类型的指针，用来方便表示边的信息和邻接矩阵中的空
    
public:
    DenseGraph(int n, bool directed ){        //构造函数
        
        this->n = n;
        this->m = 0;
        this->directed = directed;
        
        for(int i = 0; i < n; i++)
            g.push_back( vector<Edge<Weight> *>(n, NULL) ); //在g里再放一个n维，的Edge<Weight>类型的指针，初始值为NULL；
    }
    
    ~DenseGraph(){      //析构函数，修改后如果g[v][w]有边，就new了一片新的空间，这里需要释放掉
        
        for(int i = 0;i < n;i++){
            for(int j = 0; j < n; j++)
                if(g[i][j] != NULL)
                    delete g[i][j];
        }
        
    }
    
    int V(){       //返回图中有多少个顶点
        return n ;
    }
    
    int E(){      //返回图中有多少个边
        return m;
    }
    
    void addEdge(int v, int w ,Weight weight ){
        
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);
        
        if( hasEdge(v,w) ){       //在增加边的过程中可能原来已经有边了，会重复，那么这里就删掉原来的边，用下面新的边代替
            delete g[v][w];
            if( !directed )
                delete g[w][v];
            
            m--;
        }
        
        g[v][w] = new Edge<Weight>(v,w,weight);
        if( !directed )
            g[w][v] = new Edge<Weight>(w,v,weight);
        m++;
    }
    
    bool hasEdge(int v,int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        
        return g[v][w] != NULL;
    }
    
    void show(){     //把图以邻接表的形式打印出来
        
        for(int i = 0;i < n;i++){
            cout<<"vertex"<<i<<":\t";
            for(int j = 0;j < g[i].size();j++)
                if(g[i][j])
                    cout<<g[i][j]->wt()<<"\t";
                else
                    cout<<"NULL\t";
            cout<<endl;
        }
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
        
        Edge<Weight> begin(){      //返回的类型改变了
            index = -1;
            return next();
        }
        
        Edge<Weight> next(){
            for(index += 1;index < G.V(); index++)
                if( G.g[v][index] )
                    return G.g[v][index];    //不只返回序列号，而是返回边所有的信息
            return NULL;
        }
        
        bool end(){
            return index >= G.V();   //index是否大于顶点的个数
        }
    };
};



#endif /* DenseGraph_h */
