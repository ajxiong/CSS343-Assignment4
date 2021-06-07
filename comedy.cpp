#include "comedy.h"

Comedy::Comedy() { }


Comedy::~Comedy() { }

NodeData* Comedy::makeNode() {
    return new NodeData(this, this->stock);;
}

string Comedy::sortingAttribute() const{
    return "A" + this->title + " " + this->year;
}
