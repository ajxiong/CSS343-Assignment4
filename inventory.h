#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include "transaction.h"

using namespace std;

class Inventory : public Transaction
{
    private:
    public:
        Inventory();
        ~Inventory();
        void display(BinTree&, BinTree&, BinTree&, CustomerHash&, char, int, string);
};

#endif