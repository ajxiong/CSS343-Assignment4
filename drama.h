#ifndef DRAMA_H
#define DRAMA_H
#include <iostream>
#include <string>
#include "movie.h"
#include "nodedata.h"

using namespace std;

class Drama : public Movie
{
    public:
        Drama();
        ~Drama();
        NodeData* makeNode();
};

#endif