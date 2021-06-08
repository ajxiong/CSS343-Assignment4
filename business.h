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
    BinTree comedyTree;
    BinTree classicTree;
    BinTree dramaTree;

    public:
    Business();
    ~Business();
    void buildMovies();
    void buildCustomers();
    void processTrans();
};

#endif