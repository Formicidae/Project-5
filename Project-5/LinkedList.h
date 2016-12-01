#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "DoubleLinkNode.h"


class LinkedList
{
    public:
        LinkedList();
        LinkedList(DoubleLinkNode h){head = h; tail = nullptr;}
        DoubleLinkNode* getHead(){return head;}
        DoubleLinkNode* getTail(){return tail;}
        setHead(DoubleLinkNode* &h){head = h;}
        setTail(DoubleLinkNode* &t){tail = t;}
        print();
        operator+=(DoubleLinkNode n){tail.setNext(n);n.setPrev(tail);tail = n;n.setNext(nullptr);}
        //prefix
        operator--();
        //postfix
        operator--(int);




    protected:


    private:
        DoubleLinkNode*head;
        DoubleLinkNode*tail;
};

#endif // LINKEDLIST_H
