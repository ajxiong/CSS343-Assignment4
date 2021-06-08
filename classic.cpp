#include "classic.h"


Classic::Classic() { }


Classic::~Classic() { }


NodeData* Classic::makeNode() {
    return new NodeData(this->releaseDate + " " + this->majorActor, this->stock);;
}
