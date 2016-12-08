#ifndef DOUBLELINKNODE_H
#define DOUBLELINKNODE_H

#include "BaseNode.h"


class DoubleLinkNode : public BaseNode
{
    public:
        DoubleLinkNode(){next = nullptr;prev = nullptr;}
        //DoubleLinkNode(string r,int a) {setRoman(r); setArabic(a);}
        void setNext(DoubleLinkNode * d){next = d;}
        void setPrev(DoubleLinkNode * d){prev = d;}
        DoubleLinkNode * getNext(){return next;}
        DoubleLinkNode * getPrev(){return prev;}


    protected:
        DoubleLinkNode *next;
        DoubleLinkNode *prev;
};

#endif // DOUBLELINKNODE_H
