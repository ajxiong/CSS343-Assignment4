
// ------------------------------------------------ borrow.cpp -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/7/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of borrow.cpp file is to contain the implementation of the Borrow class's methods.  
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// display is a virtual method that is derived from the Transaction base class. 
// default constructor and default destructor are included as a pre-cautionary measure. 
// --------------------------------------------------------------------------------------------------------------------

#include "borrow.h"

// ------------------------------------Borrow--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default constructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Borrow::Borrow(){} //end of Borrow

// ------------------------------------~Borrow--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default destructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Borrow::~Borrow(){} //end of ~Borrow

// ------------------------------------display--------------------------------------------------------
// Pre-conditions: Movie trees and customer hash tables data must be read from .txt files first 
// Post-conditions: retrieves movie from its respective tree and adds movie and command action to
// customer history vector, while decreasing that movie's stock.
// Description: Borrow allows a customer to borrow a movie, adding the movie and comand action to their
// history and decreasing movie stock. 
// --------------------------------------------------------------------------------------------------- 
void Borrow::display(BinTree& comedyTree, BinTree& classicTree, BinTree& dramaTree, Hashtable& table, char genre, int custID, string name)
{
    Customer* customerPtr = nullptr;
    NodeData* moviePtr = nullptr;
    bool foundCustomer = table.find(custID, customerPtr);
    bool foundMovie = false;
    NodeData movie(name);
    int stock = 0;
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
    {
        cout << name << " does not exist in movie store" << endl;
        return;
    }
    if(foundCustomer)
    {
        if(stock > 0)
        {
            moviePtr->setStock(stock - 1);
            customerPtr->addTrans("Borrowed", name);
        }
        else
            cout << name <<  " is currently out of stock" << endl;
    }
    else
        cout << "customer ID: " << custID <<  " could not be found" << endl;
} //end of display
