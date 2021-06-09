// ------------------------------------------------ nodedata.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of nodedata.cpp file is to contain the NodeData class, its methods. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// Node has string and stock to contain the information of movies and we use binary search tree to handle nodes of movies.
// --------------------------------------------------------------------------------------------------------------------

#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
using namespace std;

class NodeData {
    friend ostream & operator<<(ostream &, const NodeData &); //display

    private:
        string data;
        int nodeStock;

    public:
        NodeData(); //constructor
        ~NodeData(); //destructor
        NodeData(const string &); //constructor with 1 parameter
        NodeData(const string&, int); //constructor with 2 parameter
        NodeData(const NodeData &); // copy constructor
        
        //getter and setter
        int getStock();
        void setStock(int);
        
        //overloading operator
        NodeData& operator=(const NodeData &);
        bool operator==(const NodeData &) const;
        bool operator!=(const NodeData &) const;
        bool operator<(const NodeData &) const;
        bool operator>(const NodeData &) const;
        bool operator<=(const NodeData &) const;
        bool operator>=(const NodeData &) const;
};
#endif
