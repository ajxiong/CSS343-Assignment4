// ------------------------------------------------ transaction.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/4/21
// Date of Last Modification 
// 6/9/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of transaction.h file is to contain the Transaction class, its methods, encapsulation, polymorphism, and 
// data fields. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// Transaction class is a base class that Borrow, Inventory, History, and Return classes derive from. additionally,
// since Transaction also includes bintree.h, customer.h, and hashtable.h files, all of its derrived classes also
// inherit those included class files as well. 
// --------------------------------------------------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
#include "bintree.h"
#include "customer.h"
#include "hashtable.h"
using namespace std;

class Transaction
{
    private:
    public:
    
        // ------------------------------------Transaction---------------------------------------------------
        // Pre-conditions: none
        // Post-conditions: none
        // Description: default constructor included as a pre-cautionary measure
        // --------------------------------------------------------------------------------------------------- 
        Transaction(); //end of Transaction
    
        // ------------------------------------~Transaction---------------------------------------------------
        // Pre-conditions: none
        // Post-conditions: none
        // Description: default destructor included as a pre-cautionary measure
        // --------------------------------------------------------------------------------------------------- 
        ~Transaction(); //end of ~Transaction
    
        // ------------------------------------display---------------------------------------------------
        // Pre-conditions: none
        // Post-conditions: none
        // Description: base class pure virtual method. any derrived classes will inherit this method. 
        // --------------------------------------------------------------------------------------------------- 
        virtual void display(BinTree&, BinTree&, BinTree&, Hashtable&, char, int, string) {
            cout << "Display Transaction" << endl;
        } //end of display
};

#endif
