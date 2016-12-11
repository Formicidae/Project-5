#ifndef BASENODE_H
#define BASENODE_H
#include <string>


using namespace std;


class BaseNode
{
    public:
        BaseNode(){roman = ""; arabic = 0;};
        BaseNode(string r,int a) {roman = r; arabic = a;}
        BaseNode( const BaseNode &node){roman = node.roman;arabic = node.arabic;}
        int getArabic(){return arabic;}
        virtual string getRoman()= 0;
        void setArabic(int a){arabic = a;}
        void setRoman(string r){roman = r;}

        friend void operator<<(ostream & out, BaseNode*ptr);
        friend void operator>>(istream & input, BaseNode *node);

    protected:
        string roman;
        int arabic;
};

#endif // BASENODE_H
