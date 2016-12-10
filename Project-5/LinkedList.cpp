#include "LinkedList.h"
#include <fstream>
#include <iostream>

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    //ctor
}

LinkedList::operator--(){
    DoubleLinkNode*hold = head;
    head = hold->getNext();
    head->setPrev(nullptr);
    delete hold;

}

LinkedList::operator--(int){
    DoubleLinkNode*hold = tail;
    tail = hold->getPrev();
    tail->setNext(nullptr);
    delete hold;
}

void LinkedList::print(ofstream & out,DoubleLinkNode*head){
    if(head == nullptr){
        return;
    }
    out << head;
    print(out,head->getNext());
}


LinkedList::~LinkedList()
{
    //deleteL(head);
}



void LinkedList::deleteL(DoubleLinkNode*headd){
    if(headd==tail){
        std:cout << "deleting head";
        delete headd;
        return;
    }
    DoubleLinkNode*hold = headd;
    headd = headd->getNext();
    deleteL(headd);
    delete hold;


}

