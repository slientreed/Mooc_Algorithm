//
//  UnionFind4.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/27.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef UnionFind4_h
#define UnionFind4_h
#include<assert.h>

//使用节点元素个数使得层数最少不一定准确，比如某一集合某一层元素非常多，另一个集合树很深；
//改进方法是我们维护一个记录各个集合树的层数rank数组来判断，解决极端情况

namespace UF4{
    
    class UnionFind{
        
    private:
        int* parent;
        int* rank;         //rank[i]表示以i为根的集合所表示的树的层数
        int count;
        
    public:
        UnionFind(int count){
            parent = new int[count];
            rank = new int[count];
            this->count = count;
            for(int i = 0; i < count; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }
        
        ~UnionFind(){
            delete[] parent;
            delete[] rank;
        }
        
        int find(int p){
            
            assert(p >= 0 && p < count);
            while(p != parent[p])         //直到p的parent是自己时候，为根节点，找到组
                p = parent[p];
            
            return p;
        }
        
        bool isConnected(int q,int p){
            return find(p) == find(q);
        }
        
        void unionElements(int p, int q){
            
            int pRoot = find(p);
            int qRoot = find(q);
            
            if(pRoot == qRoot)
                return;
            
            if(rank[qRoot] > rank[pRoot]){
                parent[pRoot] = qRoot;
            }
            else if(rank[qRoot] < rank[pRoot])
                parent[qRoot] = pRoot;
            else                        //两者层数相等时候
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;        //只需要把为父节点的那个集合rank加1即可
        }
    };
}



#endif /* UnionFind4_h */
