#include "classic.h"


Classic::Classic() { }


Classic::~Classic() { }


NodeData* Classic::makeNode() {
    return new NodeData(this->year + " " + this->month + " " + this->firstName + " " + this->lastName, this->stock);;
}
