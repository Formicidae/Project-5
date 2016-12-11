#ifndef DOUBLELINKNODE_H
#define DOUBLELINKNODE_H

#include "BaseNode.h"


class DoubleLinkNode : public BaseNode
{
    public:
        DoubleLinkNode(){next = nullptr;prev = nullptr;}
        //DoubleLinkNode(string r,int a) {setRoman(r); setArabic(a);}
        DoubleLinkNode( const DoubleLinkNode &node) : BaseNode(node){prev = node.prev;next = node.next;};
        void setNext(DoubleLinkNode * d){next = d;}
        void setPrev(DoubleLinkNode * d){prev = d;}
        DoubleLinkNode * getNext(){return next;}
        DoubleLinkNode * getPrev(){return prev;}
        string getRoman(){return roman;}


    protected:
        DoubleLinkNode *next;
        DoubleLinkNode *prev;
};

#endif // DOUBLELINKNODE_H
