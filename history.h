
// ------------------------------------------------ history.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/7/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of history.h file is to contain the history class, it's methods, encapsulation, and inheritance. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// display is a virtual method that is derived from the Transaction base class. 
// default constructor and default destructor are included as a pre-cautionary measure. 
// --------------------------------------------------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H
#include "transaction.h"

class History : public Transaction
{
    private:
    public:
    History(); // constructor
    ~History(); // destructor
    void display(BinTree&, BinTree&, BinTree&, Hashtable&, char, int, string); // display customer's transactions
};

#endif
