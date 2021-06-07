#ifndef BUSINESS_H
#define BUSINESS_H
#include "transaction.h"
#include "transactionfactorymethod.h"
#include "hashtable.h"
#include "nodedata.h"
#include "bintree.h"
#include "movie.h"
#include "moviefactory.h"
#include "inventory.h"
#include <vector>
#include <fstream>

class Business
{
    private:
    Hashtable table;
    public:
    Business();
    ~Business();
    void buildMovies(BinTree BSTree);
    void buildCustomers();
    void processTrans();
};

#endif