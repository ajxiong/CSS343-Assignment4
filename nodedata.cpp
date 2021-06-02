#include "nodedata.h"

NodeData::NodeData()
{
    data = "";
    nodeStock = 0;
}

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
	return data == nd2.data;
}

bool NodeData::operator!=(const NodeData& nd2) const {
	return data != nd2.data;
}

bool NodeData::operator<(const NodeData& nd2) const {
	return data < nd2.data;
}

bool NodeData::operator>(const NodeData& nd2) const {
	return data > nd2.data;
}

bool NodeData::operator<=(const NodeData& nd2) const {
	return data <= nd2.data;
}

bool NodeData::operator>=(const NodeData& nd2) const {
	return data >= nd2.data;
}

bool NodeData::setData(istream& infile) {
	getline(infile, data);
	return !infile.eof();
}

ostream& operator<<(ostream& output, const NodeData& nd2) {
	output << nd2.data << " - In Stock : " << nd2.nodeStock;
	return output;
}
