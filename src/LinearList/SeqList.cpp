#include <stdio.h>
#include <iostream>
#include "List.h"

using namespace std;

/********线性表的顺序表示********/
template<class elemType>
class SeqList: public List<elemType>{
    private:
        elemType *data;
        int curLength;
        int maxSize;
        void resize();
    public:
        SeqList(int initSize=10);
        SeqList(SeqList &sl);
        ~SeqList(){delete [] data;}
        void clear(){curLength = 0;};
        bool empty()const{return curLength == 0;}
        int size()const{return curLength;}
        void insert(int i, const elemType &value);
        void remove(int i);
        int search(const elemType &value)const;
        elemType visit(int i)const;
        void traverse()const;
        void inverse();
};

// 扩大表空间
template<class elemType>
void SeqList<elemType>::resize(){
    elemType *p = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for(int i=0; i<curLength; i++)
        data[i] = p[i];
    delete [] p;
}

// 构造函数
template<class elemType>
SeqList<elemType>::SeqList(int initSize){
    if(initSize <= 0)
        throw BadSize();
    maxSize = initSize;
    data = new elemType[maxSize];
    curLength = 0;
}

// 拷贝构造函数
template<class elemType>
SeqList<elemType>::SeqList(SeqList &sl){
    maxSize = sl.maxSize;
    curLength = sl.curLength;
    data = new elemType[maxSize];
    for(int i=0; i<curLength; i++)
        data[i] = sl.data[i];
}

// 插入运算
template<class elemType>
void SeqList<elemType>::insert(int i, const elemType &value){
    if(i<0||i>curLength)
        throw OutOfRange();
    if(curLength==maxSize) resize();
    for(int j=curLength; j>i; j--)
        data[j] = data[j-1];
    data[i] = value;
    curLength += 1;
}

// 删除运算
template<class elemType>
void SeqList<elemType>::remove(int i){
    if(i<0||i>curLength-1)
        throw OutOfRange();
    for(int j=i; j<curLength-1; j++)
        data[j] = data[j+1];
    curLength -= 1;
}

// 查找运算
template<class elemType>
int SeqList<elemType>::search(const elemType &value)const{
    for(int i=0; i<curLength; i++)
        if(data[i]==value)
            return i;
    return -1;
}

// 访问运算
template<class elemType>
elemType SeqList<elemType>::visit(int i)const{
    if(i<0||i>curLength-1)
        throw OutOfRange();
    return data[i];
}

// 遍历顺序表
template<class elemType>
void SeqList<elemType>::traverse()const{
    if(empty())
        cout<<"Is Empty!"<<endl;
    else{
        cout<<"Output element:\n";
        for(int i=0; i<curLength; i++)
            cout<<data[i]<<" ";
        cout<<endl;
    }
}

// 逆置运算
template<class elemType>
void SeqList<elemType>::inverse(){
    elemType temp;
    for(int i=0; i<curLength/2; i++){
        temp = data[i];
        data[i] = data[curLength-1-i];
        data[curLength-1-i] = temp;
    }
}

int main(){
    cout<<"Testing SeqList"<<endl;
    char c[15] = {'a', 'b', 'c', 'd', 'e',
                  'f', 'g', 'h', 'i', 'j',
                  'k', 'l', 'm', 'n', 'o'};
    SeqList<char> sl0(15);                   // 构造线性表

    cout<<"Is empty ? :"<<sl0.empty()<<endl; // 判断是否为空

    for(int i=0; i<15; i++)
        sl0.insert(i, c[i]);                 // 插入数据

    cout<<"Insert data"<<endl;
    cout<<"Size of List:"<<sl0.size()<<endl;

    sl0.traverse();

    SeqList<char> sl1 = sl0;                // 拷贝构造线性表

    cout<<"Clear sl0"<<endl;
    sl0.clear();
    sl0.traverse();

    cout<<"Inverse sl1"<<endl;
    sl1.inverse();                           // 逆置线性表
    sl1.traverse();

    cout<<"Search 'a' :"<<sl1.search('a')<<endl;

    cout<<"Visit 14th element:"<<sl1.visit(14)<<endl;

    cout<<"Inverse 'P' in 10th"<<endl;
    sl1.insert(10, 'P');
    cout<<"Size of List:"<<sl1.size()<<endl;
    sl1.traverse();

    cout<<"Remove 0th data"<<endl;
    sl1.remove(0);
    sl1.traverse();
}
