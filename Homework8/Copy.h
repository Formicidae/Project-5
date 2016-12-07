#ifndef COPY_H
#define COPY_H

#include "FileFilter.h"


class Copy : public FileFilter
{
    public:
        Copy(){};
        void doFilter(ifstream &in, ofstream &out);

    protected:

    private:
};

#endif // COPY_H
