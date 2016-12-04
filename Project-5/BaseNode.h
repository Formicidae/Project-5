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
        string roman;
        int arabic;
        getArabic(){return arabic;}
        string getRoman(){return roman;}
        void setArabic(int a){arabic = a;}
        void setRoman(string r){roman = r;}



    protected:

    private:
};

#endif // BASENODE_H
