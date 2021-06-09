// ------------------------------------------------ inventory.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/7/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of inventory.h file is to contain the inventory class, it's methods, encapsulation, and inheritance. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// display is a virtual method that is derived from the Transaction base class. 
// default constructor and default destructor are included as a pre-cautionary measure. 
// --------------------------------------------------------------------------------------------------------------------

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
        Inventory(); //constructor
        ~Inventory(); //destructor
        void display(BinTree&, BinTree&, BinTree&, Hashtable&, char, int, string); //displaying 3 trees
};

#endif
