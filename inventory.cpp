// ------------------------------------------------ inventory.cpp -------------------------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/7/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of inventory.cpp file is to contain the implementation of the Inventory class's methods.  
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// display is a virtual method that is derived from the Transaction base class. 
// default constructor and default destructor are included as a pre-cautionary measure. 
// --------------------------------------------------------------------------------------------------------------------
#include "inventory.h"

// ------------------------------------ Inventory --------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default constructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Inventory::Inventory() {}

// ------------------------------------ ~Inventory --------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default destructor included as a pre-cautionary measure
// ---------------------------------------------------------------------------------------------------
Inventory::~Inventory() {}

// ------------------------------------display--------------------------------------------------------
// Pre-conditions: Movie trees data must be read from .txt files first 
// Post-conditions: retrieves movies from its tree and display the information of each trees and each movies.
// Description: Inventory will be able to print out the list of movies following by types. 
// --------------------------------------------------------------------------------------------------- 
void Inventory::display(BinTree& comedyTree, BinTree& dramaTree, BinTree& classicTree, Hashtable& table, char a, int b, string c)
{
    cout << endl << "--------------MOVIES INVENTORY--------------" << endl << endl;
    cout << "COMEDY MOVIES:" << endl << endl;
    cout << comedyTree << endl;
    cout << "DRAMA MOVIES:" << endl << endl;
    cout << dramaTree << endl;
    cout << "CLASSICS MOVIES:" << endl << endl;
    cout << classicTree << endl;
}
