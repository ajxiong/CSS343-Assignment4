#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include "transaction.h"
#include "hashtable.h"
using namespace std;

class Inventory : public Transaction
{
    private:
    public:
        Inventory();
        ~Inventory();
        void perform(BinTree& , int, string, char, Hashtable&);
};

#endif
