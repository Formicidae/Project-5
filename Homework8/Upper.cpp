#include "Upper.h"
#include <fstream>
#include <ctype.h>

using namespace std;

void Upper::doFilter(ifstream &in, ofstream &out){
    char hold;
    while(in.get(hold)){
        if(hold == '\n'){
            out << "\n";
        }
        else{
            hold = toupper(hold);
            out << hold;
        }
    }
}
