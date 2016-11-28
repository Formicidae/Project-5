#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList
{
    public:
        LinkedList();
        LinkedList(DoubleLinkNode h){head = h; tail = nullptr;}
        DoubleLinkNode*head;
        DoubleLinkNode*tail;


    protected:

    private:
};

#endif // LINKEDLIST_H
