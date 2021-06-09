  
// ------------------------------------------------ return.cpp -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/7/21
// Date of Last Modification 
// 6/9/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of return.cpp file is to contain the Return class's method implementation. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// display is a inherited, virtual method from the Transaction base class. 
// --------------------------------------------------------------------------------------------------------------------

#include "return.h"

// ------------------------------------Return--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default constructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Return::Return() {} //end of Return

// ------------------------------------~Return--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default destructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Return::~Return() {} //end of ~Return

// ------------------------------------display--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: retrieves movie from its respective tree, decreases its stock, and adds movie and 
// transaction command to customer history.  
// --------------------------------------------------------------------------------------------------- 
void Return::display(BinTree& comedyTree, BinTree& classicTree, BinTree& dramaTree, Hashtable& table, char genre, int custID, string name)
{
    Customer* customerPtr = nullptr;
    NodeData* moviePtr = nullptr;
    bool foundCustomer = table.find(custID, customerPtr);
    bool foundMovie = false;
    NodeData movie(name);
    int stock;
    switch(genre)
    {
        case 'F' :
        foundMovie = comedyTree.retrieve(movie, moviePtr);
        break;
        case 'D' :
        foundMovie = dramaTree.retrieve(movie, moviePtr);
        break;
        case 'C' :
        foundMovie = classicTree.retrieve(movie, moviePtr);
        break;
        default :
        break;
    }
    if(foundMovie)
        stock = moviePtr->getStock();
    else
        cout << name << " does not exist in movie store" << endl;
    if(foundCustomer)
    {
        bool movieIsDue = customerPtr->checkReturn(name);
        if(movieIsDue)
        {
            customerPtr->addTrans("Returned", name);
            moviePtr->setStock(stock + 1);
        }
        else
            cout << "Customer ID: " << custID << " has never checked out: " << name << endl;
    }
    else
        cout << "Customer ID: " << custID << " does not exist" << endl;
} //end of display
