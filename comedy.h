#ifndef COMEDY_H
#define COMEDY_H
#include <iostream>
#include <string>
#include "movie.h"
#include "nodedata.h"
using namespace std;

class Comedy : public Movie
{
    public:
        Comedy();
        ~Comedy();

        NodeData* makeNode();

};

#endif