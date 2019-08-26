//
//  ShortPath.h
//  Algorithm Learning
//
//  Created by mark on 2018/12/1.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef ShortPath_h
#define ShortPath_h


#include <vector>
#include <queue>
#include <iostream>
#include <cassert>

using namespace std;

// 路径查询
template <typename Graph>
class ShortPath{
    
private:
    Graph &G;   // 图的引用
    int s;      // 起始点,类中的源点s
    bool* visited;  // 记录dfs的过程中节点是否被访问
    int * from;     // 记录路径, from[i]表示查找的路径上i的上一个节点,维护一个数组，记录当前访问的节点，表示 是从哪一个节点过来的
    int* ord;   //记录从s到每一个节点的最短距离是多少
    
    
public:
    // 构造函数, 寻路算法, 寻找图graph从s点到其他点的路径
    ShortPath(Graph &graph, int s):G(graph){
        
        // 算法初始化
        assert( s >= 0 && s < G.V() );
        
        visited = new bool[G.V()];
        from = new int[G.V()];
        ord = new int[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }
        this->s = s;
        
        //使用广度优先遍历， 找到从s到任意点的最短路径算法
        queue<int> q;
        
        q.push(s);
        visited[s] = true;
        ord[s] = 0;    //源点到自己的距离为0；
        while( !q.empty() ){
            
            int v = q.front();    //取出队首元素，并移除出队
            q.pop();
            
            typename Graph::adjIterator adj(G,v);        //使用之前写的迭代器，找到所有和源节点相邻的节点，并放入队中
            for(int i = adj.begin(); !adj.end(); i = adj.next() ){
                if( !visited[i] ){     //如果节点未被访问过
                    q.push(i);
                    visited[i] = true;
                    from[i] = v;
                    ord[i] = ord[v] + 1;
                }
            }
        }
    }
    
    // 析构函数
    ~ShortPath(){
        
        delete [] visited;
        delete [] from;
        delete [] ord;
    }
    
    // 查询从s点到w点是否有路径
    bool hasPath(int w){
        assert( w >= 0 && w < G.V() );
        return visited[w];
    }
    
    // 查询从s点到w点的路径, 存放在vec中
    void path(int w, vector<int> &vec){
        
        assert( hasPath(w) );
        
        // 通过from数组逆向查找到从s到w的路径, 存放到栈中
        stack<int> s;
        int p = w;
        while( p != -1 ){
            s.push(p);
            p = from[p];
        }
        
        // 从栈中依次取出元素, 获得顺序的从s到w的路径
        vec.clear();    //清空向量
        while( !s.empty() ){
            vec.push_back( s.top() );   //从stack顶开始把元素一个个存入vec向量中
            s.pop();
        }
    }
    
    // 打印出从s点到w点的路径
    void showPath(int w){
        
        assert( hasPath(w) );
        
        vector<int> vec;
        path( w , vec );
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i];
            if( i == vec.size() - 1 )
                cout<<endl;
            else
                cout<<" -> ";
        }
    }
    
    int length(int w){       //返回最短路径的值
        assert( w >= 0 && w < G.V() );
        return ord[w];
    }
};



#endif /* ShortPath_h */
