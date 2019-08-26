//
//  UnionFind2.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/27.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef UnionFind2_h
#define UnionFind2_h
#include<assert.h>

//改进的版本，使用父节点，采用类似数形结构存储同一组元素；当合并两组元素时，需要把其中一个元素的组值放在另一个根下面
namespace UF2{

    class UnionFind{
    
    private:
        int* parent;
        int count;
        
    public:
        UnionFind(int count){
            parent = new int[count];
            this->count = count;
            for(int i = 0; i < count; i++)
                parent[i] = i;
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
            
            parent[pRoot] = qRoot;     //合并时，把其中一个parent指向另一个的根节点，就把两个合并了
        }
    };
}


#endif /* UnionFind2_h */
