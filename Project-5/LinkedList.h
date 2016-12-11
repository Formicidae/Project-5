#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "DoubleLinkNode.h"
#include <iostream>


class LinkedList
{
    public:
        LinkedList();
        LinkedList(DoubleLinkNode* h){head = h; tail = h;}
        DoubleLinkNode* getHead(){return head;}
        DoubleLinkNode* getTail(){return tail;}
        setHead(DoubleLinkNode* &h){head = h;}
        setTail(DoubleLinkNode* &t){tail = t;}
        void print(ofstream & out,DoubleLinkNode*head);
        operator+=(DoubleLinkNode* n){
            if(!getHead()){
                setHead(n);
                setTail(n);
            }
            else if(head->getRoman() == "" && head->getArabic() == 0){
                setHead(n);
                setTail(n);
            }
            else{
            tail->setNext(n);
            n->setPrev(tail);
            tail = n;
            n->setNext(nullptr);}}
        //prefix
        operator--();
        //postfix
        operator--(int);
        void deleteL(DoubleLinkNode*headd);
        ~LinkedList();




    protected:


    private:
        DoubleLinkNode*head;
        DoubleLinkNode*tail;
};

#endif // LINKEDLIST_H
