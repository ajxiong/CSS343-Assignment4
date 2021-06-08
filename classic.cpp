#include "classic.h"


Classic::Classic() { }


Classic::~Classic() { }


NodeData* Classic::makeNode() {
    return new NodeData(year + " " + this->month + " " + this->first + " " + this->last, this->stock);;
}
