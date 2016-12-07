#include "Encrypt.h"
#include <fstream>

using namespace std;

void Encrypt::doFilter(ifstream &in, ofstream &out){
    char hold;
    while(in.get(hold)){
        if(hold == '\n'){
            out << "\n";
        }
        else{
            hold += key;
            out << hold;
        }
    }
}
