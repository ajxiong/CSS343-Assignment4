#include "drama.h"


Drama::Drama() { }


Drama::~Drama() { }


NodeData* Drama::makeNode() {
    return new NodeData(this, this->stock);;
}

string Drama::sortingAttribute() const {
    return "B" + this->director + " " + this->title;
}
