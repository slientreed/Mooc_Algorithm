//
//  Path.h
//  Algorithm Learning
//
//  Created by mark on 2018/12/1.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef Path_h
#define Path_h


#include <vector>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

// 路径查询
template <typename Graph>
class Path{
    
private:
    Graph &G;   // 图的引用
    int s;      // 起始点,类中的源点s
    bool* visited;  // 记录dfs的过程中节点是否被访问
    int * from;     // 记录路径, from[i]表示查找的路径上i的上一个节点,维护一个数组，记录当前访问的节点，表示 是从哪一个节点过来的
    
    // 图的深度优先遍历
    void dfs( int v ){
        
        visited[v] = true;
        
        typename Graph::adjIterator adj(G, v);
        for( int i = adj.begin() ; !adj.end() ; i = adj.next() ){
            if( !visited[i] ){
                from[i] = v;          //这里访问的i节点是从v节点过来的
                dfs(i);
            }
        }
    }
    
public:
    // 构造函数, 寻路算法, 寻找图graph从s点到其他点的路径
    Path(Graph &graph, int s):G(graph){
        
        // 算法初始化
        assert( s >= 0 && s < G.V() );
        
        visited = new bool[G.V()];
        from = new int[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;
        
        //找到从s到任意点的路径算法
        dfs(s);     //深度遍历一次s，维护from数组即可
    }
    
    // 析构函数
    ~Path(){
        
        delete [] visited;
        delete [] from;
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
};



#endif /* Path_h */
