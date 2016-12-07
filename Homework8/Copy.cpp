#include "Copy.h"
#include <fstream>

using namespace std;

void Copy::doFilter(ifstream &in, ofstream &out){
    char hold;
    while(in.get(hold)){
        if(hold == '\n'){
            out << "\n";
        }
        else{
            out << hold;
        }
    }
}
