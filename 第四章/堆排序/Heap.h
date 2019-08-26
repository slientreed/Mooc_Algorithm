//
//  HeapSort.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/22.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef HeapSort_h
#define HeapSort_h

//该文件主要是一个堆构造函数和对操作函数，实现一个Heap；


//最大二叉堆的两个特点：1.是满二叉树；2.父节点值一定大于子节点
//新建一个最大堆，实现一个最大堆类，把整个类都作为模板类Item
//时间复杂度，一个个生成堆遍历了整个数组，复杂度是O(n),然后每个操作shiftUP或者shiftDown时间复杂度是log（n），总的时间复杂度是 nlog(n);

template<typename Item>
class MaxHeap{
    
private:
    Item* data;      //堆类的数据用指针数组存储
    int count;      //记录堆中有几个元素;调用者不能直接修改count；
    int capacity;
    
    //向上调整，插入的子节点和根节点比较，如果大于根节点则交换，一直到满足最大堆条件或者到root节点为止
    void shiftUp(int k){       //把方法声明为private，调用者不用调用这个函数
        while(k > 1 && data[k/2] < data[k]){   //判断当前插入节点和父节点大小
            swap(data[k/2],data[k]);
            k /= 2;
        }
    }
    
    //向下调整，根节点和左右子节点中较大值交换，一直到满足最大堆条件为止：根节点大于左右子节点
    void shiftDown(int k){
        while(2*k <= count){     //判断当前条件是该节点有子节点，存在左节点即可
            int j = 2 * k;                              //在此轮循环，data[k]和data[j]交换位置；左节点和右节点谁大谁和data[k]交换
            if(j + 1 <= count && data[j+1] > data[j])   //j表示左节点，如果右节点存在，且右节点大，k+1准备和右节点交换
                j += 1;
            if(data[k] >= data[j])
                break;
            
            swap(data[k],data[j]);
            k = j;
        }
    }
    
public:
    //1.建堆，一个一个插入数组中的元素，在插入过程中不断调整新插入进来的元素，保持最大堆性质，时间复杂度是O(nlogn);同时把数组中元素放到堆中，又开辟了堆的空间，空间复杂度O(n)
    MaxHeap(int capacity){      //类的一个构造函数，对最大堆类进行初始化，即开辟空间
        data = new Item[capacity + 1];  //因为堆中的元素是从1开始的，不是0，所以开辟空间大小要加1；从1开始便于子节点和父节点之间找到规律
        count = 0;
        this->capacity = capacity;
    }
    
    //heapify建堆过程和上面1不同，这个是直接假设数组为堆，然后从第一个非叶子节点（count/2）开始操作，使堆变成最大堆，直接省去了一半节点的操作，时间复杂度是O(n)；开辟了堆的空间，空间复杂度O(n)
    MaxHeap(Item arr[], int n){
        data = new Item[n+1];          //数组指针开辟空间
        capacity = n;
        for(int i = 0;i < n;i++){
            data[i+1] = arr[i];          //把数组相应的元素赋值给data[],直接生成一个堆，不要一个一个insert();
        }
        count = n;
        for(int i = count / 2;i >= 1;i--)    //从第一个非叶子节点开始循环，把堆变成maxheap；
            shiftDown(i);
    }
    
    ~MaxHeap(){        //在析构函数中，把构造函数的data开辟的空间释放掉
        delete [] data;
    }
    
    int size(){      //成员函数，返回堆中有几个元素
        return count;
    }
    
    bool isEmpty(){   //成员函数，返回堆是否为空
        return count == 0;
    }
    
    void insert(Item item){     //定义成员函数insert()，在原有堆中插入元素
        assert(count + 1 <= capacity);  //保证count+1小于用户传入的堆大小;(最好办法是当插入越界时，可以动态开辟空间)
        
        data[count+1] = item;    //堆中的索引是从1开始的，和0开始有区别；（但是存在count+1越界的问题）
        count++;
        shiftUp(count);       //shiftUp()函数开始新插入的函数仍然保持最大二叉堆的特性
    }
    
    Item extractMax(){     //返回一个Item类型的对象
        assert(count > 0);
        
        Item result = data[1];
        
        swap(data[1],data[count]);   //交换使得仍然是堆仍然是最大二叉树
        count--;
        
        shiftDown(1);           //使得最大二叉树仍然满足根节点大于子节点
        return result;
    }
    
    
public:
    void testPrint(){
        cout<<"Data in the max heap: ";
        cout<<endl;
        for( int i = 1 ; i <= size() ; i ++ ){
            cout<<data[i]<<" ";             //一个疑问：为什么data放到main（）函数里面显示未定义，前面不是调用new data了吗？看一下public函数怎么调用的
        }
        cout<<endl;
        cout<<endl;
    }
    
};





#endif /* HeapSort_h */
