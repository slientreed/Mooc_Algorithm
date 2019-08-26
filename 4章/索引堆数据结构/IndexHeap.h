//
//  IndexHeap.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/22.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef IndexHeap_h
#define IndexHeap_h


//索引最大堆的构建，在每个元素增加一个索引值，元素比较的时候比较data[]数据，在做元素交换的时候交换元素的索引值。这样避免如果元素不是数字，构建堆的时候要移动大量数据
template<typename Item>
class IndexMaxHeap{
    
private:
    Item* data;      //堆类的数据用指针数组存储
    int* indexes;
    int* reverse;   //维护一个数组，reverse[i]表示数组i这个索引在堆中的位置j,便于后面change()函数找到j；indexes[i]=j,reverse[j]=i.
    int count;      //记录堆中有几个元素;调用者不能直接修改count；
    int capacity;
    
    //向上调整，插入的子节点和根节点比较，如果大于根节点则交换，一直到满足最大堆条件或者到root节点为止
    void shiftUp(int k){       //把方法声明为private，调用者不用调用这个函数
        while(k > 1 && data[indexes[k/2]] < data[indexes[k]]){   //判断当前插入节点和父节点大小
            swap(indexes[k/2],indexes[k]);
            reverse[indexes[k/2]] = k/2;     //更新reverse[]的值
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }
    
    //向下调整，根节点和左右子节点中较大值交换，一直到满足最大堆条件为止：根节点大于左右子节点
    void shiftDown(int k){
        while(2*k <= count){     //判断当前条件是该节点有子节点，存在左节点即可
            int j = 2 * k;                              //在此轮循环，data[k]和data[j]交换位置；左节点和右节点谁大谁和data[k]交换
            if(j + 1 <= count && data[indexes[j+1]] > data[indexes[j]])   //j表示左节点，如果右节点存在，且右节点大，k+1准备和右节点交换
                j += 1;
            if(data[indexes[k]] >= data[indexes[j]])
                break;
            
            swap(indexes[k],indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }
    
public:
    //1.建堆，一个一个插入数组中的元素，在插入过程中不断调整新插入进来的元素，保持最大堆性质，时间复杂度是O(nlogn);同时把数组中元素放到堆中，又开辟了堆的空间，空间复杂度O(n)
    IndexMaxHeap(int capacity){      //类的一个构造函数，对最大堆类进行初始化，即开辟空间
        data = new Item[capacity + 1];  //因为堆中的元素是从1开始的，不是0，所以开辟空间大小要加1；从1开始便于子节点和父节点之间找到规律
        indexes = new int[capacity + 1];  //开辟索引空间，都为int型
        reverse = new int[capacity + 1];
        for(int i = 0;i <= capacity; i++)  //把reverse[i]全都初始化为0，说明一开始堆不存在，堆没有元素
            reverse[i] = 0;
        
        count = 0;
        this->capacity = capacity;
    }
    
    ~IndexMaxHeap(){        //在析构函数中，把构造函数的data开辟的空间释放掉
        delete [] data;
        delete [] indexes;
        delete [] reverse;
    }
    
    int size(){      //成员函数，返回堆中有几个元素
        return count;
    }
    
    bool isEmpty(){   //成员函数，返回堆是否为空
        return count == 0;
    }
    
    //传入的i对于用户而言，是从0开始索引的
    void insert(int i,Item item){     //定义成员函数insert()，在原有堆中插入元素,其中元素的索引为i
        assert(count + 1 <= capacity);  //保证count+1小于用户传入的堆大小;(最好办法是当插入越界时，可以动态开辟空间)
        assert(i+1 >= 1 && i+1 <= capacity);  //元素索引从1开始，且小于数组容量
        
        i += 1;
        data[i] = item;    //堆中的索引是从1开始的，和0开始有区别；（但是存在count+1越界的问题）
        indexes[count+1] = i;  //data[]和indexes[]数组内存储的差别，一个是元素，一个是该元素对应的索引值
        reverse[i] = count + 1;
        
        count++;
        shiftUp(count);       //shiftUp()函数开始新插入的函数仍然保持最大二叉堆的特性
    }
    
    Item extractMax(){
        assert(count > 0);
        
        Item result = data[indexes[1]];
        swap(indexes[1],indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        
        shiftDown(1);
        return result;
    }
    
    int extractMaxIndex(){     //返回一个Item类型的对象的索引
        assert(count > 0);
        
        int res = indexes[1] - 1;
        
        swap(indexes[1],indexes[count]);   //交换使得仍然是堆仍然是最大二叉树
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        
        shiftDown(1);           //使得最大二叉树仍然满足根节点大于子节点
        return res;
    }
    
    bool contain(int i){
        assert(i + 1 >= 1 && i + 1 <= capacity);
        return reverse[i+1] != 0;       //用reverse数组检查i是否存在于堆中
    }
    
    Item getItem(int i){    //返回第i个索引的值
        assert(contain(i)); //保证i的索引存在于堆中，i的取值范围在capacity中，并不代表其存在于堆中
        return data[i+1];
    }
    
    void change(int i, Item newItem){    //把数组中第i个元素换成newItem值
        
        assert(contain(i));   //保证i的索引存在于堆中，i的取值范围在capacity中，并不代表其存在于堆中
        i += 1;
        data[i] = newItem;
        
        /*
         //上面改变了数组中第i个元素值，我们要维持最大堆，就要找到data[i]的索引值j，用shiftUp或者shiftDown保持最大堆
         //找到indexes[j] = i,j就表示data[i]在堆中的位置；之后shiftUp(j),shiftDown(j);
         for(int j = 1; j <= count; j++ ){        //这个for循环遍历查找j的时间复杂度为O(n)
         if(indexes[j] == i){
         shiftUp(j);
         shiftDown(j);
         return;
         }
         }
         */
        int j = reverse[indexes[i]];       //维护了一个reverse[]数组，里面表示i对应的堆中索引j的值，代替上面的for循环,查找j的时间复杂度变为O(1).
        shiftUp(j);
        shiftDown(j);
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


#endif /* IndexHeap_h */
