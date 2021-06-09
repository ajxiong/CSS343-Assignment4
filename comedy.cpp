
// ------------------------------------------------ comedy.cpp -------------------------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/7/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of comedy.cpp file is to contain the implementation of the Comedy class's methods.  
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// makeNode is a method that is derived from the Movie base class. 
// default constructor and default destructor are included as a pre-cautionary measure. 
// --------------------------------------------------------------------------------------------------------------------

#include "comedy.h"

// ------------------------------------ Comedy --------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default constructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Comedy::Comedy() { }

// ------------------------------------ ~Comedy --------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default destructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Comedy::~Comedy() { }

// ------------------------------------makeNode--------------------------------------------------------
// Pre-conditions: Movie trees must be read from .txt files first 
// Post-conditions: make a Node from stored data in movie class
// Description: This class helps to build a classic tree.
// --------------------------------------------------------------------------------------------------- 
NodeData* Comedy::makeNode() {
    return new NodeData(title + " " + this->year, this->stock);;
}
