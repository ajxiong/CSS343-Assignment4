#ifndef CLASSIC_H
#define CLASSIC_H
#include <iostream>
#include <string>
#include "movie.h"
#include "nodedata.h"

using namespace std;

class Classic : public Movie
{
    public:
        Classic();
        ~Classic();

        NodeData* makeNode();
        string sortingAttribute() const;
};

#endif