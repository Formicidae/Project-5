//Edward Bates emb160030 1337.002
Main
#include <iostream>
#include "Encrypt.h"
#include "Upper.h"
#include "Copy.h"

using namespace std;

int main()
{
    ifstream filei ("input.txt");
    ofstream fileo ("output.txt");

    Encrypt* filter = new Encrypt(5);
    filter->doFilter(filei, fileo);

    Upper* up = new Upper();
    up->doFilter(filei, fileo);

    Copy* cop = new Copy();
    cop->doFilter(filei, fileo);

    cout << "Hello world!" << endl;
    return 0;
}

==============================
FileFiler.h
==============================
#ifndef FILEFILTER_H
#define FILEFILTER_H
#include <fstream>

using namespace std;

class FileFilter
{
    public:
        virtual void doFilter(ifstream &in, ofstream &out) = 0;
};

#endif // FILEFILTER_H

==============================
Encrypt.h
==============================

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
==============================
Encrypt.cpp
==============================
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
==============================
Upper.h
==============================
#ifndef UPPER_H
#define UPPER_H
#include "FileFilter.h"

class Upper : public FileFilter
{
    public:
        Upper(){};
        void doFilter(ifstream &in, ofstream &out);
};
#endif // UPPER_H
==============================
Upper.cpp
==============================

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
==============================
Copy.h
==============================
#ifndef COPY_H
#define COPY_H

#include "FileFilter.h"

class Copy : public FileFilter
{
    public:
        Copy(){};
        void doFilter(ifstream &in, ofstream &out);
};
#endif // COPY_H
==============================
Copy.cpp
==============================
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
//Edward Bates emb160030 1337.002

