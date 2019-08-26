//
//  Edge.h
//  Algorithm Learning
//
//  Created by mark on 2018/12/5.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef Edge_h
#define Edge_h

//对有权图，每个节点的信息会增加，邻接表没有合适的数据类型，创建一个类Edge，每个节点下面就是和这些节点相关的类表示与之相邻的边的信息；
//统一在邻接矩阵也存储Edge，表示每个节点的信息；因此邻接矩阵和邻接表都存储指针来实现

#include<iostream>
using namespace std;

template<typename Weight>     //权值类型不固定，设置为模板类
class Edge{
    
private:
    int a,b;        //参数包含两个边
    Weight weight;   //权值
    
public:
    Edge(int a, int b, Weight weight){     //边的构造函数
        this->a = a;
        this->b = b;
        this->weight = weight;
    }
    
    Edge(){}   //初始化方法
    
    ~Edge(){}   //析构函数
    
    int v(){ return a;}   // 返回两个顶点，和权值
    int w(){ return b;}
    Weight wt(){ return weight;}
    
    int other(int x){  //知道一个顶点，返回另一个顶点
        assert(x == a || x == b);
        return x == a ? b : a;
    }
    
    // 输出边的信息
    friend ostream& operator<<(ostream &os, const Edge &e){
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }
    
    // 重载，边的大小比较, 是对边的权值的大小比较
    bool operator<(Edge<Weight>& e){
        return weight < e.wt();
    }
    bool operator<=(Edge<Weight>& e){
        return weight <= e.wt();
    }
    bool operator>(Edge<Weight>& e){
        return weight > e.wt();
    }
    bool operator>=(Edge<Weight>& e){
        return weight >= e.wt();
    }
    bool operator==(Edge<Weight>& e){
        return weight == e.wt();
    }
    
};


#endif /* Edge_h */
