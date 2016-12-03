#ifndef DOUBLELINKNODE_H
#define DOUBLELINKNODE_H

#include "BaseNode.h"


class DoubleLinkNode : public BaseNode
{
    public:
        DoubleLinkNode(){next = nullptr;prev=nullptr;};
        //DoubleLinkNode(string r,int a) {setRoman(r); setArabic(a);}
        DoubleLinkNode*next = new DoubleLinkNode();
        DoubleLinkNode*prev = new DoubleLinkNode();
        void setNext(DoubleLinkNode * d){next = d;};
        void setPrev(DoubleLinkNode * d){prev = d;};


    protected:

    private:
};

#endif // DOUBLELINKNODE_H
