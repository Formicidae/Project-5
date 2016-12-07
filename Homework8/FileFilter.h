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
