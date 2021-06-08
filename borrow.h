// ------------------------------------------------ borrow.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/7/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of borrow.h file is to contain the Borrow class, it's methods, encapsulation, and inheritance. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// display is a virtual method that is derived from the Transaction base class. 
// default constructor and default destructor are included as a pre-cautionary measure. 
// --------------------------------------------------------------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H
#include "transaction.h"

class Borrow : public Transaction
{
    private:
    public:
    
    // ------------------------------------Borrow--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: default constructor included as a pre-cautionary measure
    // --------------------------------------------------------------------------------------------------- 
    Borrow();// end of Borrow
    
    // ------------------------------------~Borrow--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: default destructor included as a pre-cautionary measure
    // --------------------------------------------------------------------------------------------------- 
    ~Borrow();// end of ~Borrow
    
    // ------------------------------------display--------------------------------------------------------
    // Pre-conditions: Movie trees and customer hash tables data must be read from .txt files first 
    // Post-conditions: retrieves movie from its respective tree and adds movie and command action to
    // customer history vector, while decreasing that movie's stock.
    // Description: Borrow allows a customer to borrow a movie, adding the movie and comand action to their
    // history and decreasing movie stock. 
    // --------------------------------------------------------------------------------------------------- 
    void display(BinTree&, BinTree&, BinTree&, Hashtable&, char, int, string); //end of display
};

#endif
