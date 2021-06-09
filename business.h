// ------------------------------------------------ business.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong - Phuong Phan CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of business.h file is to contain the business class, it's methods, encapsulation, data fields,
// and include other .h files. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// each method takes a .txt file and reads in data from that .txt file. 
// --------------------------------------------------------------------------------------------------------------------

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
    
    // ------------------------------------Business--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: default constructor included as a pre-cautionary measure
    // --------------------------------------------------------------------------------------------------- 
    Business(); //end of Business
    
    // ------------------------------------~~Business---------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: default destructor included as a pre-cautionary measure
    // --------------------------------------------------------------------------------------------------- 
    ~Business(); //end of ~Business
    
    // ------------------------------------buildMovies--------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: assigns each movie genre type to its respective genre binary search tree. 
    // Description: buildMovies reads in movie data and assigns each movie to a tree based on genre 
    // type. method also takes in any data error reading. 
    // --------------------------------------------------------------------------------------------------- 
    void buildMovies(); //end of buildMovies
    
    // ------------------------------------buildCustomers--------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: assigns customer information to hash table object. 
    // Description: buildCustomers takes in customer information and inserts them as NodeData into
    // the hash table object. 
    // --------------------------------------------------------------------------------------------------- 
    void buildCustomers(); //end of buildCustomers
    
    // ------------------------------------processTrans--------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: modifies movie trees and customer history based on transaction commands and 
    // other information
    // Description: processTrans takes in transaction commands and other information to modify movie
    // trees and customer history. method also takes in any data error reading. 
    // --------------------------------------------------------------------------------------------------- 
    void processTrans(); //end of processTrans
};

#endif
