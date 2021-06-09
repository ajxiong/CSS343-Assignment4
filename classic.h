// ------------------------------------------------ classic.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/7/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of classic.h file is to contain the Classic class and its methods, encapsulation, and inheritance.  
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// makeNode is a method that is derived from the Movie base class. 
// default constructor and default destructor are included as a pre-cautionary measure. 
// --------------------------------------------------------------------------------------------------------------------

#ifndef CLASSIC_H
#define CLASSIC_H
#include <iostream>
#include <string>
#include "movie.h"
#include "nodedata.h"

using namespace std;

class Classic : public Movie
{
    public:
    
        Classic(); //constructor
        
        ~Classic(); //destructor

        NodeData* makeNode(); //making a new node

};

#endif
