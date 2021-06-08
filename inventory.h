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
        void display(BinTree&, BinTree&, BinTree&, Hashtable&, char, int, string);
};

#endif
