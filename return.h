#ifndef RETURN_H
#define RETURN_H
#include "transaction.h"

class Return : public Transaction
{
    private:
    public:
    Return();
    ~Return();
    void display(BinTree&, BinTree&, BinTree&, Hashtable&, char,int, string);
};

#endif
