// ------------------------------------------------ transactionfactorymethod.cpp --------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/9/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of transactionfactorymethod.cpp file is to contain the method implementation for the TransactionFactoryMethod
// class. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// TransactionFactoryMethod is a factory method class that returns a transaction pointer based on the command inputted.
// if none of the correct commands are inputted, the pointer returns nullptr. 
// --------------------------------------------------------------------------------------------------------------------

#include "transactionfactorymethod.h"
#include <iostream>

using namespace std;

// ------------------------------------createTransaction----------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: method returns a Transaction pointer based on the command inputted. since these 
// classes are derrived from the Transaction class, any Transaction pointer will point to that 
// specific derrived class object. 
// --------------------------------------------------------------------------------------------------- 
Transaction* TransactionFactoryMethod::createTransaction(const char &command)
{
    if(command == 'I')
        return new Inventory();
    else if(command == 'H')
        return new History();
    else if(command == 'R')
        return new Return();
    else if(command == 'B')
        return new Borrow();
    else
        return nullptr;
}
