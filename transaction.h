
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
#include "bintree.h"
#include "customer.h"
#include "hashtable.h"
using namespace std;

class Transaction
{
    private:
    public:
        Transaction();
        ~Transaction();
        virtual void display(BinTree&, BinTree&, BinTree&, int, string, char, Hashtable&) { }
};

#endif
