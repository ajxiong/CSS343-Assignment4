// ------------------------------------------------ transactionfactorymethod.h --------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/9/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of transactionfactorymethod.h file is to contain the TransactionFactoryMethod class, its methods, 
// data fields, and encapsulation. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// TransactionFactoryMethod is a factory method class that returns a transaction pointer based on the command inputted.
// if none of the correct commands are inputted, the pointer returns nullptr. 
// --------------------------------------------------------------------------------------------------------------------

#ifndef TRANSACTIONFACTORYMETHOD_H
#define TRANSACTIONFACTORYMETHOD_H
#include "inventory.h"
#include "history.h"
#include "return.h"
#include "borrow.h"
#include "transaction.h" 

using namespace std;

class TransactionFactoryMethod
{
    private:
    public:
    
    // ------------------------------------createTransaction----------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: method returns a Transaction pointer based on the command inputted. since these 
    // classes are derrived from the Transaction class, any Transaction pointer will point to that 
    // specific derrived class object. 
    // --------------------------------------------------------------------------------------------------- 
    Transaction* createTransaction(const char &command); //end of createTransaction
    
};


#endif
