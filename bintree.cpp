#include <string>
#include <iostream>
#include "bintree.h"

using namespace std;

ostream &operator<< (ostream &os, const BinTree &bst) {
    bst.inorderHelper(bst.root);
    os << endl;
    return os;
}

BinTree::BinTree() {
    this->root = nullptr;
}

BinTree::BinTree(const BinTree &b2) {
    this->root = nullptr;
    *this = b2;
}

BinTree::~BinTree() {
    this->makeEmpty();
}

bool BinTree::isEmpty() const{
    return this->root == nullptr;
}

void BinTree::makeEmpty() {
    makeEmpty(root);
}

void BinTree::makeEmpty(Node* &current)
{
    if (current != nullptr) {   // post order traversal
        makeEmpty(current->left); // left
        makeEmpty(current->right);    // right

        if (current->data != nullptr) {
            delete current->data;   // deletes the data
            current->data = nullptr;
        }

        delete current; // sets pointer to NULL
        current = nullptr;
    }
}

BinTree& BinTree::operator= (const BinTree &b2) {
    if (*this == b2) { // check if both trees are the same
        return *this;
    }
    this->makeEmpty();  // deletes the left tree
    assignmentHelper(b2.root, this->root);
    return *this;   // returns lTree when its the same as rTree
}

void BinTree::assignmentHelper(Node* b2, Node* &thisTree)
{
    if (b2 != nullptr) {// preorder traverse right tree
        thisTree = new Node;   // new node for left tree
        NodeData *current = new NodeData(*b2->data);    //copies rTree NodeData to temp
        thisTree->data = current; // set left tree data to temp

        assignmentHelper(b2->left, thisTree->left); // left
        assignmentHelper(b2->right, thisTree->right);   //right
    } else {
        thisTree = nullptr;  // copy empty tree
    }
}

bool BinTree::operator== (const BinTree& b2) const{
    if (this->root == nullptr && b2.root == nullptr) {
        return true;
    } else {
        return equalHelper(this->root, b2.root);
    }
}

bool BinTree::operator!= (const BinTree& b2) const{
    return !(*this == b2);
}

bool BinTree::insert(NodeData* data) {
    return insertHelper(this->root, data);
}

bool BinTree::retrieve(const NodeData &nodeData, NodeData* &otherNodeData) const {
    //Uses the helper method to retrieve.
    retrieveHelper(root, nodeData, otherNodeData);
    if (otherNodeData != nullptr)
    {
        return true;    // NodeData found
    }
    return false;   // NodeData not in tree
}

void BinTree::bstreeToArray(NodeData* arrayNode[]) {
    //This is foe the current size of the array.
    int index = 0;
    //Put the nodes in the array in order and increment
    //the size.
    if (this->root != nullptr) {
        bstreeToArrayHelper(arrayNode, index, this->root);
    }
    //Empty the tree
    this->makeEmpty();
}

void BinTree::bstreeToArrayHelper(NodeData* arrayNode[], int &index, Node* current) {
    if(current->left != nullptr) {
        bstreeToArrayHelper(arrayNode, index, current->left);
    }
    NodeData* temp;
    temp = current->data;
    current->data = nullptr;
    arrayNode[index++] = temp;
    temp = nullptr;

    if(current->right != nullptr) {
        bstreeToArrayHelper(arrayNode, index, current->right);
    }
}

void BinTree::arrayToBSTree(NodeData* arrayNode[]) {
    this->makeEmpty();
    int last = 0;
    for(int i = 0; i < 99; i++)
        if(arrayNode[i] == nullptr)
        {
            last = i - 1;
            break;
        }

    root = arrayToTreeHelper(arrayNode, 0, last);

    for(int i = 0; i < 100; i++)
        arrayNode[i] = nullptr;

}

BinTree::Node* BinTree::arrayToTreeHelper(NodeData* arrayNode[], int first, int last) {
    if(first > last)
        return nullptr;

    int newRoot = first + (last - first) / 2;
    Node *node = new Node;

    node->data = arrayNode[newRoot];
    node->left = arrayToTreeHelper(arrayNode, first, newRoot - 1);
    node->right = arrayToTreeHelper(arrayNode, newRoot + 1, last);

    return node;
}

bool BinTree::equalHelper(Node* b1Node, Node* b2Node) const {
    if (b1Node == nullptr && b2Node == nullptr) {
        return true;
    } else if (b1Node == nullptr || b2Node == nullptr) {
        return false;
    } else if (*b1Node->data == *b2Node->data
        && b1Node->left == nullptr && b1Node->left == nullptr
        && b2Node->right == nullptr && b2Node->right == nullptr) {
            return true;
    } else {
        return (*b1Node->data == *b2Node->data
            && equalHelper(b1Node->left, b2Node->left)
            && equalHelper(b1Node->right, b2Node->right));
    }
}

bool BinTree::insertHelper(Node* &current, NodeData* insertData) {
    if (current == NULL)    // insert new node here
    {
        current = new Node;   // new node created
        current->data = insertData;   // NodeData set to node
        current->left = nullptr;   // left child set to NULL
        current->right = nullptr;  // right child set to NULL
    }
    else if (*insertData < *current->data)
    {
        insertHelper(current->left, insertData);  // traverse left
    }
    else if (*insertData > *current->data)
    {
        insertHelper(current->right, insertData); // traverse right
    }
    else
    {
        return false;   // node already exists and is not inserted
    }

    return true;    // node inserted
}

bool BinTree::retrieveHelper(Node* current, const NodeData &nodeData, NodeData* &otherNodeData) const {
    if (current == nullptr) {    // NodeData is not found
        otherNodeData = nullptr;   // return pointer set to NULL
        return false;
    } else if (*current->data == nodeData) {  // NodeData found
        otherNodeData = current->data;  // return pointer set to NodeData
        return true;
    } else if (*current->data < nodeData) {
        return retrieveHelper(current->right, nodeData, otherNodeData);  // traverse right
    } else if (*current->data > nodeData) {
        return retrieveHelper(current->left, nodeData, otherNodeData);   // traverse left
    } else {
        return false;   // NodeData not found
    }
}

int BinTree::getHeight(const NodeData &nodeData) const {
    return getHeightHelper(nodeData, this->root);
}

int BinTree::getHeightHelper(const NodeData &nodeData, Node* current) const {
    if (current == nullptr)
    {
        return 0;   // node is not in tree, return height = 0
    }
    else if (*current->data == nodeData)
    {
        return recursiveGetHeightHelper(current);   // node found
    }
    else
    {
        int left = getHeightHelper(nodeData, current->left);  // search left
        int right = getHeightHelper(nodeData, current->right);    // search right

        return max(left, right);
    }
}

int BinTree::recursiveGetHeightHelper(Node* current) const {
    if (current == nullptr) {
        return 0;   // have reached a leaf node
    } else {
        // counts the amount of levels in the tree from root node
        return 1 + max(recursiveGetHeightHelper(current->left), recursiveGetHeightHelper(current->right));
    }
}

void BinTree::inorderHelper(Node* current) const{
    if (current != nullptr)  // traverse and print data
    {
        inorderHelper(current->left);
        cout << *current->data << "";
        inorderHelper(current->right);
    }
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != nullptr) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}
