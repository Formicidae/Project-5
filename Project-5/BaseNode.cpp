#include "BaseNode.h"
#include <string>
#include <fstream>
#include <sstream>
#include <ctype.h>


void operator<<(ostream & out, BaseNode*ptr){

    out << ptr->roman;
    for(int i = 0; i + ptr->roman.length() < 20;i++){
            out << " ";
    }
    out << ptr->arabic << "\n";
    //return out;
}

void operator>>(istream & input, BaseNode *node){
    string num;
    input >> num;
    if(!isdigit(num[0])){
        node->setRoman(num);
        return;
    }
    stringstream myStream(num);
    int i;
    myStream >> i;
    node->setArabic(i);




}
