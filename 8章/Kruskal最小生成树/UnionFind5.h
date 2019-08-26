//
//  UnionFind5.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/27.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef UnionFind5_h
#define UnionFind5_h
#include<assert.h>

//使用路径压缩优化，每次find()时候，把当前元素指向父节点的跟，减少层数
//经过路径压缩之后，时间复杂度近乎为O(1)
namespace UF5{
    
    class UnionFind{
        
    private:
        int* parent;
        int* rank;
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
            
            //第一种压缩方式
            while(p != parent[p]){
                parent[p] = parent[parent[p]];  //只增加了这一句，把当前p节点指向父节点的指针，指向其父亲节点的父亲
                p = parent[p];
            }
            return p;
        
            /*  //另外一种理论上更好的路径压缩方式，把所有集合压缩成两层
            if(p != parent[p])
                parent[p] = find(parent[p]);      //find函数目的是找到某一节点的根节点，递归调用find，最终把p的parent变为根节点
            return parent[p];                    //直接换回p的根节点即可
            */
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
            else{
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
            }
        }
    };
}



#endif /* UnionFind5_h */
