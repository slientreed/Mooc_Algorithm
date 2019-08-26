//
//  UnionFind3.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/27.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef UnionFind3_h
#define UnionFind3_h
#include<assert.h>

//对UnionFind2的优化，每次合并时候，把元素少的那组集合的根节点，向元素多的那组集合的根节点合并，这样生成的树的层数低；
//维护一个数组，记录每个集合的元素个数
namespace UF3{
    
    class UnionFind{
        
    private:
        int* parent;
        int* size;       //size[i]表示以i为根的集合所表示的树的节点个数是多少
        int count;
        
    public:
        UnionFind(int count){
            parent = new int[count];
            size = new int[count];
            this->count = count;
            for(int i = 0; i < count; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        ~UnionFind(){
            delete[] parent;
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
            
            if(size[qRoot] > size[pRoot]){    //谁的集合元素个数多，谁为根，使得树尽可能低
                parent[pRoot] = qRoot;
                size[qRoot] += size[pRoot];
            }
            else
                parent[qRoot] = pRoot;
                size[pRoot] += size[qRoot];
        }
    };
}


#endif /* UnionFind3_h */
