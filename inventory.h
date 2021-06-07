#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include "transaction.h"
#include "customerhash.h"
using namespace std;

class Inventory : public Transaction
{
    private:
    public:
        Inventory();
        ~Inventory();
        void perform(BinTree& , int, string, char, CustomerHash&);
};

#endif