#include "comedy.h"

Comedy::Comedy() { }


Comedy::~Comedy() { }

NodeData* Comedy::makeNode() {
    return new NodeData(title + " " + this->year, this->stock);
}
