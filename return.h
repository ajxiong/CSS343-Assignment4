#ifndef RETURN_H
#define RETURN_H
#include "transaction.h"

class Return : public Transaction
{
    private:
    public:
    void display(BinTree&, BinTree&, BinTree&, int, string, char, Hashtable&);
};

#endif