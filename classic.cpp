#include "classic.h"


Classic::Classic() { }


Classic::~Classic() { }


NodeData* Classic::makeNode() {
    return new NodeData(this, this->stock);;
}

string Classic::sortingAttribute() const {
    return "C" + this->year + " " + this->month + " " + this->first + " " + this->last;
}
