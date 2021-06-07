#include "nodedata.h"

NodeData::NodeData()
{
    nodeStock = 0;
}

NodeData::NodeData(const Movie& string, int s) {
    data = string;
    nodeStock = s;
}

NodeData::NodeData(const NodeData& nd2) {
    data = nd2.data;
    nodeStock = nd2.nodeStock;
}

NodeData::NodeData(const Movie& string) {
    data = string;
    nodeStock = 0;
}

NodeData::~NodeData() { }

void NodeData::setStock(int newStock) {
    nodeStock = newStock;
}

int NodeData::getStock() {
    return nodeStock;
}

NodeData& NodeData::operator=(const NodeData& nd2) {
    if (this != &nd2) {
        data = nd2.data;
        nodeStock = nd2.nodeStock;
    }
    return *this;
}

bool NodeData::operator==(const NodeData& nd2) const {
	return (this->data).sortingAttribute() == nd2.data.sortingAttribute();
}

bool NodeData::operator!=(const NodeData& nd2) const {
	return (this->data).sortingAttribute() != nd2.data.sortingAttribute();
}

bool NodeData::operator<(const NodeData& nd2) const {
	return (this->data).sortingAttribute() < nd2.data.sortingAttribute();
}

bool NodeData::operator>(const NodeData& nd2) const {
	return (this->data).sortingAttribute() > nd2.data.sortingAttribute();
}

bool NodeData::operator<=(const NodeData& nd2) const {
	return (this->data).sortingAttribute() <= nd2.data.sortingAttribute();
}

bool NodeData::operator>=(const NodeData& nd2) const {
	return (this->data).sortingAttribute() >= nd2.data.sortingAttribute();
}

ostream& operator<<(ostream& output, const NodeData& nd2) {
	output << nd2.data << " - In Stock : " << nd2.nodeStock << endl;
	return output;
}
