#ifndef DOUBLELINKNODE_H
#define DOUBLELINKNODE_H

#include "BaseNode.h"


class DoubleLinkNode : public BaseNode
{
    public:
        DoubleLinkNode();
        DoubleLinkNode* next;
        DoubleLinkNode* prev;

    protected:

    private:
};

#endif // DOUBLELINKNODE_H
