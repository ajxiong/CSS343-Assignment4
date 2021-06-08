#ifndef BINTREE_H
#define BINTREE_H

#include "nodedata.h"
#include <string>
#include <iostream>

using namespace std;

class BinTree {				
    friend ostream &operator<< (ostream &os, const BinTree &bst);

    public:
        BinTree();								// constructor
        BinTree(const BinTree& b2);				// copy constructor
        ~BinTree();								// destructor, calls makeEmpty

        bool isEmpty() const;					// true if tree is empty, otherwise false
        void makeEmpty();						// make the tree empty so isEmpty returns true
        BinTree& operator= (const BinTree& b2);
        bool operator== (const BinTree &) const;
        bool operator!= (const BinTree &) const;
        bool insert(NodeData*);
        bool retrieve(const NodeData &nodeData, NodeData* &otherNodeData) const;
        int getHeight(const NodeData &nodeData) const;
        void bstreeToArray(NodeData* arrayNode[]);
        void arrayToBSTree(NodeData* arrayNode[]);
        void displaySideways() const;			// provided below, displays the tree sideways

    private:
	    struct Node {
            NodeData* data;						// pointer to data object
            Node* left;							// left subtree pointer
            Node* right;						// right subtree pointer
        };
        Node* root;	// root of the tree

        void assignmentHelper(Node* b2, Node* &thisTree);
        bool equalHelper(Node* b1Node, Node* b2Node) const;
        bool insertHelper(Node* &node, NodeData* insertata);
        bool retrieveHelper(Node* current, const NodeData &nodeData, NodeData* &otherNodeData) const;
        int getHeightHelper(const NodeData &nodeData, Node* current) const;
        int recursiveGetHeightHelper(Node* current) const;
        void bstreeToArrayHelper(NodeData* arrayNode[], int &index, Node* current);
        Node* arrayToTreeHelper(NodeData* arrayNode[], int first, int last);
        void inorderHelper(Node* current) const;
        void sideways(Node*, int) const;  // provided below, helper for displaySideways()
        void makeEmpty(Node* &current);

};
#endif //BINTREE_H
