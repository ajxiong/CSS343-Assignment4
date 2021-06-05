#include "transactionfactorymethod.h"
#include <iostream>

using namespace std;

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