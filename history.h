#ifndef HISTORY_H
#define HISTORY_H
#include "transaction.h"

class History : public Transaction
{
    private:
    public:
    History();
    ~History();
    void display(BinTree&, BinTree&, BinTree&, int, string, char, Hashtable&);
};

#endif