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
    if(head == tail){
        head->setRoman("");
        head->setArabic(0);
        return 0;
    }
    DoubleLinkNode*hold = head;
    head = hold->getNext();
    head->setPrev(nullptr);
    delete hold;

}

LinkedList::operator--(int){
    if(head == tail){
        head->setRoman("");
        head->setArabic(0);
        return 0;
    }
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
        delete headd;
        return;
    }
    DoubleLinkNode*hold = headd;
    headd = headd->getNext();
    deleteL(headd);
    delete hold;


}

