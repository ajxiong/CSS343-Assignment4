#ifndef TRANSACTIONFACTORYMETHOD_H
#define TRANSACTIONFACTORYMETHOD_H
#include "inventory.h"
#include "history.h"
#include "return.h"
#include "borrow.h"
#include "transaction.h" //may not need here, can include transaction.h file in the
// TransactionFactoryMethod.cpp file?

using namespace std;

class TransactionFactoryMethod
{
    private:
    public:
    Transaction* createTransaction(const char &command);
    
};


#endif