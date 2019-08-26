//
//  UnionFind1.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/27.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef UnionFind1_h
#define UnionFind1_h

#include<iostream>
#include<assert.h>

using namespace std;


//第一个版本的并查集，采用数组存放元素和对应的组；查找比较快，但是并操作比较慢

namespace UF1{

    class UnionFind{

    private:
        int* id;
        int count;  //记录UnionFind中有多少个元素
        
    public:
        
        //查找id很快，时间复杂度是O(1)
        UnionFind( int n ){      //构造函数,每个id 值不一样，表示是否为同一组元素
            count = n;
            id = new int[n];
            for(int i = 0; i < n; i++)
                id[i] = i;
        }
        
        ~UnionFind(){
            delete [] id;
        }
        
        int find(int p){               //查找p对应的所属组
            assert( p >= 0 && p < count);
            return id[p];
        }
        
        bool isConnected(int p, int q ){
            return find(q) == find(p);
        }
        
        //合并元素的时间复杂度是O(n)，要遍历整个数组
        void unionElements(int p, int q ){
            int pID = find(p);
            int qID = find(q);
            
            if(pID == qID)
                return;
            
            for(int i = 0;i < count; i++)
                if( id[i] == pID)
                    id[i] = qID;
        }
    };
}



#endif /* UnionFind1_h */
