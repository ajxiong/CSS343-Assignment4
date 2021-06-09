
// ------------------------------------------------ nodedata.cpp -------------------------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of nodedata.cpp file is to contain the Nodedata class methods implementation. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// Node has string and stock to contain the information of movies and we use binary search tree to handle nodes of movies.
// --------------------------------------------------------------------------------------------------------------------

#include "nodedata.h"

ostream& operator<<(ostream& output, const NodeData& nd2) {
	output << nd2.data << " ___ " << nd2.nodeStock << " movies left." << endl;
	return output;
}

NodeData::NodeData()
{
    data = " ";
    nodeStock = 0;
}

NodeData::~NodeData() { }

NodeData::NodeData(const string& string, int s) {
    data = string;
    nodeStock = s;
}

NodeData::NodeData(const NodeData& nd2) {
    data = nd2.data;
    nodeStock = nd2.nodeStock;
}

NodeData::NodeData(const string& string) {
    data = string;
    nodeStock = 0;
}

int NodeData::getStock() {
    return nodeStock;
}

void NodeData::setStock(int newStock) {
    nodeStock = newStock;
}

NodeData& NodeData::operator=(const NodeData& nd2) {
    if (this != &nd2) {
        data = nd2.data;
        nodeStock = nd2.nodeStock;
    }
    return *this;
}

bool NodeData::operator==(const NodeData& nd2) const {
	return (this->data) == nd2.data;
}

bool NodeData::operator!=(const NodeData& nd2) const {
	return (this->data) != nd2.data;
}

bool NodeData::operator<(const NodeData& nd2) const {
	return (this->data) < nd2.data;
}

bool NodeData::operator>(const NodeData& nd2) const {
	return (this->data) > nd2.data;
}

bool NodeData::operator<=(const NodeData& nd2) const {
	return (this->data) <= nd2.data;
}

bool NodeData::operator>=(const NodeData& nd2) const {
	return (this->data) >= nd2.data;
}
