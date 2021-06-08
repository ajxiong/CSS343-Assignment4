#include "drama.h"


Drama::Drama() { }


Drama::~Drama() { }


NodeData* Drama::makeNode() {
    return new NodeData(director + " " + this->title, this->stock);;
}