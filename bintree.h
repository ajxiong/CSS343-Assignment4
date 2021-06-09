
// ------------------------------------------------ bintree.cpp -------------------------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of bintree.cpp file is to contain the BinTree class methods implementation. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// to build and keep track the movie, we use a binary search tree. 
// instructions for bst insertion are as follows:
/*
   With each type of movie, we build a different tree.
   To store the data in the tree, the items should be arranged as follows:
-	comedy movies (‘F’) sorted by Title, then Year it released 
-	dramas (‘D’) are sorted by Director, then Title 
-	classics (‘C’) are sorted by Release date, then Major actor
*/
// --------------------------------------------------------------------------------------------------------------------
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
