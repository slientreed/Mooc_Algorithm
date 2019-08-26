//
//  LazyPrimMST.h
//  Algorithm Learning
//
//  Created by mark on 2018/12/7.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef LazyPrimMST_h
#define LazyPrimMST_h


#include "MinHeap.h"
#include<assert.h>

using namespace std;

template<typename Graph, typename Weight>    //模板类，传入图类型Graph，还要指定有权图类型Weight
class LazyPrimMST{

private:
    Graph &G;    //图的引用
    MinHeap<Edge<Weight>> pq;   //最小堆pq，pq中存储的元素是边
    bool* marked;          //表示节点是否访问过，切分到另外一边
    vector<Edge<Weight>> mst;   //把求得的最下生成树的边放入mst向量类型，每个元素都是一个Edge类型
    Weight mstWeight;        //最小生成树的权值
    
    void visit(int v){
        assert(!marked[v]);
        marked[v] = true;      //从v节点开始访问
        
        typename Graph::adjIterator adj(G,v);   //只用迭代器访问当前节点v的所有领边
        for( Edge<Weight>* e = adj.begin(); !adj.end();e = adj.next() )
            if( !marked[e->other(v)])        //和当前节点v通过领边相连的节点未访问过，则说明该边是横切边，加入最小堆中
                pq.insert(*e);
        
        
    }
    
public:
    LazyPrimMST(Graph &graph):
        G(graph),                                 //对G和最小对初始化
    pq(MinHeap<Edge<Weight>>(graph.E())){         //最小堆开辟边的个数个空间，最差情况下所有边都要进入堆中
        marked = new bool[G.V()];         //开辟空间，大小是顶点的个数
        for(int i = 0;i < G.V(); i++)    //marked初始化
            marked[i] = false;
        mst.clear();   //初始化保证mst开始为空
        
        
        //LazyPrim
        visit(0);      //visit函数，从0节点开始访问
        while(!pq.isEmpty()){   //如果队列不为空的话，说明还有横切边没有判断
            Edge<Weight> e = pq.extractMin();    //去除最小堆中权重最小的边
            if(marked[e.v()] == marked[e.w()]) //判断拿出的权重最小边是不是横切边，在不在同侧
                continue;            //不是横切边，继续循环
            
            mst.push_back(e);    //是最小横切边，放入mst向量中；然后继续找下一个未被遍历的节点
            if( !marked[e.v()] )
                visit(e.v());
            else
                visit(e.w());
        }
        
        mstWeight = mst[0].wt(); //最开始放入0的权值
        for(int i = 0; i < mst.size(); i++)
            mstWeight += mst[i].wt();
        
        
    }
    
    ~LazyPrimMST(){
    
        delete[] marked;
    }
    
    vector<Edge<Weight>> mstEdges(){    //返回最小生成树由哪些边构成
        return mst;
    }
    
    Weight result(){                //返回最小生成树的权值
        return mstWeight;
    }
    
};



#endif /* LazyPrimMST_h */
