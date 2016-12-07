#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <fstream>

#include "FileFilter.h"

using namespace std;

class Encrypt : public FileFilter
{
    public:
        Encrypt();
        int key = 0;
        Encrypt(int i){key = i;};
        void doFilter(ifstream &in, ofstream &out);
};

#endif // ENCRYPT_H
