#include <stdio.h>
#include <iostream>
#include "List.h"

using namespace std;

template<class elemType>
struct Node{
    public:
        elemType data;
        Node* next;
        Node(const elemType value, Node* p=NULL){
            data = value;
            next = p;
        }
        Node(Node* p=NULL){
            next = p;
        }
};

template<class elemType>
class LinkList: public List<elemType>{
    private:
        struct Node{
            public:
                elemType data;
                Node* next;
                Node(const elemType value, Node* p=NULL){
                    data = value;
                    next = p;
                }
                Node(Node* p=NULL){
                    next = p;
                }
        };
        Node* head;
        Node* tail;
        int curLength;
        Node* getPosition(int i)const;
    public:
        LinkList();
        ~LinkList();
        void clear();
        bool empty()const{return head->next==NULL;}
        int size()const{return curLength;}
        void insert(int i, const elemType &value);
        void remove(int i);
        int search(const elemType &value)const;
        elemType visit(int i)const;
        void traverse()const;
        void inverse();
        void headCreate();
        void tailCreate();
};

template<class elemType>
class LinkList<elemType>::LinkList(){

}