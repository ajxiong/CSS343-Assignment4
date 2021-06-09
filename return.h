// ------------------------------------------------ return.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/7/21
// Date of Last Modification 
// 6/9/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of return.h file is to contain the Return class, its methods, encapsulation, polymorphism, and data fields. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// display is a inherited, virtual method from the Transaction base class. 
// --------------------------------------------------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H
#include "transaction.h"

class Return : public Transaction
{
    private:
    public:
    
    // ------------------------------------Return--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: default constructor included as a pre-cautionary measure
    // --------------------------------------------------------------------------------------------------- 
    Return(); //end of Return
    
    // ------------------------------------~Return--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: default destructor included as a pre-cautionary measure
    // --------------------------------------------------------------------------------------------------- 
    ~Return(); //end of ~Return
    
     // ------------------------------------display--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: retrieves movie from its respective tree, decreases its stock, and adds movie and 
    // transaction command to customer history.  
    // --------------------------------------------------------------------------------------------------- 
    void display(BinTree&, BinTree&, BinTree&, Hashtable&, char,int, string); //end of display
};

#endif
