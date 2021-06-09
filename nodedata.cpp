
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

//------------------------------------------ostream------------------------------------------
//Description: Displays node.
//-------------------------------------------------------------------------------------------
//Pre-condition: The parameters that are passed in are an existing object.
//Post-condition: Print out the node
//-------------------------------------------------------------------------------------------
ostream& operator<<(ostream& output, const NodeData& nd2) {
	output << nd2.data << " ___ " << nd2.nodeStock << " movies left." << endl;
	return output;
}

//------------------------------------------NodeData------------------------------------------
//Description: Default Constructor that creates a node.
//-------------------------------------------------------------------------------------------
//Pre-condition: None
//Post-condition: Creates an empty node.
//-------------------------------------------------------------------------------------------
NodeData::NodeData()
{
    data = " ";
    nodeStock = 0;
}

//----------------------------------------~NodeData------------------------------------------
//Description: Destroys the node.
//-------------------------------------------------------------------------------------------
//Pre-condition: None
//Post-condition: None
//-------------------------------------------------------------------------------------------
NodeData::~NodeData() { }

//------------------------------------------NodeData------------------------------------------
//Description: Default Constructor that creates a node.
//-------------------------------------------------------------------------------------------
//Pre-condition: The parameter is valid
//Post-condition: Creates an node with string value.
//-------------------------------------------------------------------------------------------
NodeData::NodeData(const string& string) {
    data = string;
    nodeStock = 0;
}

//------------------------------------------NodeData------------------------------------------
//Description: Default Constructor that creates a node.
//-------------------------------------------------------------------------------------------
//Pre-condition: The parameters are valid
//Post-condition: Creates an node with string value and stock value.
//-------------------------------------------------------------------------------------------
NodeData::NodeData(const string& string, int s) {
    data = string;
    nodeStock = s;
}

//-------------------------------------Copy Constructor--------------------------------------
//Description: Copy Constructor that copies another node with this one.
//-------------------------------------------------------------------------------------------
//Pre-condition: The parameter that is passed in is an existing object.
//Post-condition: Performs a deep copy of the other node to this node.
//-------------------------------------------------------------------------------------------
NodeData::NodeData(const NodeData& nd2) {
    data = nd2.data;
    nodeStock = nd2.nodeStock;
}

//------------------------------------------getStock------------------------------------------
//Description: Return stock of node.
//-------------------------------------------------------------------------------------------
//Pre-condition: none
//Post-condition: none
//-------------------------------------------------------------------------------------------
int NodeData::getStock() {
    return nodeStock;
}

//------------------------------------------setStock------------------------------------------
//Description: store the stock value.
//-------------------------------------------------------------------------------------------
//Pre-condition: none
//Post-condition: none
//-------------------------------------------------------------------------------------------
void NodeData::setStock(int newStock) {
    nodeStock = newStock;
}

//----------------------------------------opersator=-----------------------------------------
//Description: Basically a Copy Constructor that copies another tree
// with this one. Except that it uses the assignment operator
//-------------------------------------------------------------------------------------------
//Pre-condition: The parameter that is passed in is an existing object.
//Post-condition: Performs a deep copy of the other node to this node.
//-------------------------------------------------------------------------------------------
NodeData& NodeData::operator=(const NodeData& nd2) {
    if (this != &nd2) {
        data = nd2.data;
        nodeStock = nd2.nodeStock;
    }
    return *this;
}

//----------------------------------------operator==-----------------------------------------
//Description: Checks if one node is the same as another.
//-------------------------------------------------------------------------------------------
//Pre-condition: The parameter that is passed in is an existing object.
//Post-condition: Returns true if the two nodes are the same. False otherwise.
//-------------------------------------------------------------------------------------------
bool NodeData::operator==(const NodeData& nd2) const {
	return (this->data) == nd2.data;
}

//----------------------------------------operator!=-----------------------------------------
//Description: Checks if one node is not the same as another.
//-------------------------------------------------------------------------------------------
//Pre-condition: The parameter that is passed in is an existing object.
//Post-condition: Returns true if the two nodes are not the same. False otherwise.
//-------------------------------------------------------------------------------------------
bool NodeData::operator!=(const NodeData& nd2) const {
	return (this->data) != nd2.data;
}

//----------------------------------------operator<-----------------------------------------
//Description: Checks if this node is smaller than another.
//-------------------------------------------------------------------------------------------
//Pre-condition: The parameter that is passed in is an existing object.
//Post-condition: Returns true if this node is smaller than another. False otherwise.
//-------------------------------------------------------------------------------------------
bool NodeData::operator<(const NodeData& nd2) const {
	return (this->data) < nd2.data;
}

//----------------------------------------operator>-----------------------------------------
//Description: Checks if this node is larger than another.
//-------------------------------------------------------------------------------------------
//Pre-condition: The parameter that is passed in is an existing object.
//Post-condition: Returns true if this node is larger than another. False otherwise.
//-------------------------------------------------------------------------------------------
bool NodeData::operator>(const NodeData& nd2) const {
	return (this->data) > nd2.data;
}

//----------------------------------------operator<=-----------------------------------------
//Description: Checks if this node is equal or smaller than another.
//-------------------------------------------------------------------------------------------
//Pre-condition: The parameter that is passed in is an existing object.
//Post-condition: Returns true if this node is equal or smaller than another. False otherwise.
//-------------------------------------------------------------------------------------------
bool NodeData::operator<=(const NodeData& nd2) const {
	return (this->data) <= nd2.data;
}

//----------------------------------------operator>=-----------------------------------------
//Description: Checks if this node is equal or larger than another.
//-------------------------------------------------------------------------------------------
//Pre-condition: The parameter that is passed in is an existing object.
//Post-condition: Returns true if this node is equal or larger than another. False otherwise.
//-------------------------------------------------------------------------------------------
bool NodeData::operator>=(const NodeData& nd2) const {
	return (this->data) >= nd2.data;
}
