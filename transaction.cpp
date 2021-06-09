
// ------------------------------------------------ transaction.cpp -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/4/21
// Date of Last Modification 
// 6/9/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of transaction.cpp file is to contain the Transaction class method implementation
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// Transaction class is a base class that Borrow, Inventory, History, and Return classes derive from. additionally,
// since Transaction also includes bintree.h, customer.h, and hashtable.h files, all of its derrived classes also
// inherit those included class files as well. 
// --------------------------------------------------------------------------------------------------------------------

#include "transaction.h"

// ------------------------------------Transaction---------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default constructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Transaction::Transaction() { } //end of Transaction

// ------------------------------------~Transaction---------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default destructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Transaction::~Transaction() { } //end of ~Transaction
