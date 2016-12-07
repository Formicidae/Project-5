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
