// ------------------------------------------------ history.cpp -------------------------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/7/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of history.cpp file is to contain the implementation of the History class's methods.  
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// display is a virtual method that is derived from the Transaction base class. 
// default constructor and default destructor are included as a pre-cautionary measure. 
// --------------------------------------------------------------------------------------------------------------------
#include "history.h"
#include <iostream>
#include <string>

// ------------------------------------ History --------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default constructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
History::History(){}

// ------------------------------------ ~History --------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default destructor included as a pre-cautionary measure
// ---------------------------------------------------------------------------------------------------
History::~History(){}

// ------------------------------------display--------------------------------------------------------
// Pre-conditions: Movie trees and customer hash tables data must be read from .txt files first 
// Post-conditions: retrieves customer from its hashtable and display their names/ID and their old transactions.
// Description: History will be able to print out the transaction history of customers. 
// --------------------------------------------------------------------------------------------------- 
void History::display(BinTree& comedyTree, BinTree& dramaTree, BinTree& classicTree, Hashtable& table, char genre, int custID, string name)
{
    Customer* customer;
    bool customerIn = table.find(custID, customer);

    if (customerIn) {
        cout << "--------------------------------------" << endl;
        cout << customer->getFirstName() << " " << customer->getLastName() << " - "
            << "ID: " <<customer->getID() << endl << endl;
        cout << "Transaction History: " << endl;
        customer->display();
        cout << endl;
    }
    else {
        cout << "There no customer with this ID/ name" << endl;
    }
}
