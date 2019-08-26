//
//  Binary_Search_Tree.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/27.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef Binary_Search_Tree_h
#define Binary_Search_Tree_h
#include<cassert>
#include <queue>
#include <vector>
#include <string>


template<typename Key,typename Value>
class BST{        //新建一个新的类
    
private:
    struct Node{             //节点Node这个结构体
        Key key;
        Value value;
        Node *left;
        Node *right;
        
        Node(Key key,Value value){     //给Node节点设立一个构造函数
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
        
        Node(Node* node){               //新的构造函数，便于revome()中赋值节点；Node* successor = new Node(minimum(node->rihgt));
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
        
    };
    
    Node *root;
    int count;
    
public:
    BST(){
        root = NULL;
        count = 0;
    }
    
    ~BST(){
        destory( root );   //析构函数，释放空间，采用后序遍历的思想编写destory函数
    }
    
    int size(){
        return count;
    }
    
    bool isEmpyt(){
        return count == 0;
    }
    
    void insert(Key key, Value value){    //递归调用private中的insert函数，
        root = insert(root, key, value);  //返回插入节点后，得到的二叉搜索树的根
    }
    
    bool contain(Key key){         //查看二叉搜索树中，是否包含有Key为key值的元素
        return contain(root,key);   //递归调用函数，这个函数的参数是一个节点和key，查找以这个节点为根的二叉搜索树中是否包含key；
    }
    
    Value* search(Key key){         //返回Value指针，可以为空；如果返回Value值，则不能为空，key必须存在才行
        return search(root,key);
    }
    
    //前序遍历
    void preOrder(){
        preOrder(root);      //递归进行前序遍历，递归函数写在private中
    }
    
    //中序遍历
    void inOrder(){
        inOrder(root);
    }
    
    //后序遍历
    void postOrder(){
        postOrder(root);
    }
    
    //层序遍历，利用队列，在头文件引用了<queue>
    void levelOrder(){
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            cout<<node->key<<endl;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    
    //寻找二叉搜索树种最小值
    Key minimum(){
        assert(count != 0);
        Node* minNode = minimum( root );   //递归调用minimum函数，写在private中
        return minNode->key;
    }
    
    //寻找二叉搜索树种最大值
    Key maximum(){
        assert(count != 0);
        Node* maxNode = maximum( root );   //递归调用minimum函数，写在private中
        return maxNode->key;
    }
    
    //从二叉搜索树中删除最小值所在的节点
    void removeMin(){
        if(root)
            root = removeMin( root );  //递归调用private中的removeMin函数，删除以当前节点为根的二叉树的最小值，并返回新的根节点
    }
    
    //从二叉搜索树中删除最大值所在节点
    void removeMax(){
        
        if(root)
            root = removeMax( root );
    }
    
    //从二叉树中删除任意键值为key的的节点
    void remove(Key key){
        remove(root, key);
    }
    
private:
    //向以node为跟的二叉搜索树中插入节点（key，value）
    //返回值是插入新节点后二叉搜索树的跟
    Node* insert(Node *node, Key key, Value value){
        
        if(node == NULL){        //递归到底的情况，新建一个Node
            count++;
            return new Node(key, value);
        }
        
        if(key == node->key)
            node->value = value;
        if(key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);
        
        return node;
    }
    
    //递归函数，查看以node为根的二叉搜索树中，是否含有键值为key的节点
    bool contain(Node *node, Key key){
        
        if(node == NULL)       //递归到底的结束条件
            return false;
        
        if(key == node->key)
            return true;
        else if(key < node->key)
            return contain(node->left, key);
        else
            return contain(node->right,key);
    }
    
    //在以node为跟的二叉搜索树中查找key对应的value
    Value* search(Node* node, Key key){
        
        if(node == NULL)
            return NULL;
        
        if(key == node->key)
            return &(node->value);
        else if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right,key);
    }
    
    //以node为根的二叉搜索树进行前序遍历
    void preOrder(Node* node){
        
        if(node != NULL){
            cout<<node->key<<endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    
    //以node为根的二叉搜索树进行中序遍历
    void inOrder(Node* node){
        
        if(node != NULL){
            inOrder(node->left);
            cout<<node->key<<endl;
            inOrder(node->right);
        }
    }
    
    //以node为根的二叉搜索树进行后序遍历
    void postOrder(Node* node){
        
        if(node != NULL){
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->key<<endl;
        }
    }
    
    //类似于后序遍历，进行空间释放，完成析构函数
    void destroy(Node* node){
        
        if(node != NULL){
            destroy(node->left);
            destroy(node->right);
            
            delete node;
            count--;
        }
    }
    
    //在以node为根的二叉搜索树中，返回最小键值的节点
    Node* minimum(Node* node){
        
        if(node->left == NULL)
            return node;
        
        return minimum(node->left);
    }
    
    //在以node为根的二叉搜索树中，返回最大键值的节点
    Node* maximum(Node* node){
        
        if(node->right == NULL)
            return node;
        
        return maximum(node->right);
    }
    
    //删除掉以node为根的二叉搜索树中的最小节点
    //返回删除掉最小节点后新的二叉搜索树的根节点
    Node* removeMin(Node* node){
        
        if(node->left == NULL){    //如果当前节点左孩子为空，则他就是最小节点
            Node* rightNode = node->right;   //当前的右孩子节点取代当前的节点
            delete node;
            count--;
            return rightNode;
        }
        
        node->left = removeMin(node->left);
        return node;
    }
    
    //删除掉以node为根的二叉搜索树中的最大节点
    //返回删除掉最大节点后新的二叉搜索树的根节点
    Node* removeMax(Node* node){
        
        if(node->left == NULL){
            Node* leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }
        
        node->right = removeMax(node->right);
        return node;
    }
    
    //删除掉以node为根的二分搜索树中键值为key的节点
    //返回删除节点后新的二分搜索树的根
    Node* remove(Node* node, Key key){
        if(node == NULL)
            return NULL;
        
        if(key < node->key){
            node->left = remove(node->left, key); //在当前节点中的左孩子中递归remove，删除之后并把node返回给左孩子
            return node;
        }
        else if(key > node->key){
            node->right = remove(node->right, key);
            return node;
        }
        else{           //要删除的key = node->key;
            
            if(node->left == NULL){     //如果node的左孩子为空，只需要把该节点删除，用右节点代替该节点即可
                Node* rightnode = node->right;
                delete node;
                count--;
                return rightnode;
            }
            
            if(node->right == NULL){     //如果node的右孩子为空，只需要把该节点删除，用左节点代替该节点即可
                Node* leftnode = node->left;
                delete node;
                count--;
                return leftnode;
            }
            
            //node->left != NULL && node->right != NULL;node的左右孩子都不为空
            Node* successor = new Node(minimum(node->rihgt));      //复制一个node，以免后面删除removeMin时，找不到节点;在前面node结构体中加入了新的构造函数
            count++;
            
            successor->right = removeMin(node->right);     //给node->right赋值
            successor->left = node->left;                 //给node->left赋值
            
            delete node;
            count--;
            
            return successor;
        }
        
    }
    
    
};


#endif /* Binary_Search_Tree_h */
