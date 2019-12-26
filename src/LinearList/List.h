#ifndef _LIST_H_
#define _LIST_H_

using namespace std;

class OutOfRange: public exception{
    public:
        const char* what()const throw(){
            return "ERROR! OUT OF RANGE.\n";
        }
};

class BadSize: public exception{
    public:
        const char* what()const throw(){
            return "ERROR! BAD SIZE.\n";
        }
};

/********线性表的基类********/
template<class elemType>
class List{
    public:
        virtual void clear()=0;                       // 清空线性表
        virtual bool empty()const=0;                  // 判断是否为空
        virtual int size()const=0;                    // 求线性表长度
        virtual void insert(int i, const elemType &value)=0; // 在位序i插入值为value的元素
        virtual void remove(int i)=0;                 // 移除位序i的元素
        virtual int search(const elemType &value)const=0;    // 查找值为value元素的位序
        virtual elemType visit(int i)const=0;                // 查找位序为i的元素
        virtual void traverse()const=0;               // 遍历线性表
        virtual void inverse()=0;                     // 逆置线性表
        virtual ~List() {};
};

#endif