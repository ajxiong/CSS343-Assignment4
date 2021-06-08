#include "inventory.h"

// ------------------------------------constructor-----------------------------------------------
// Description:
// -------------------------------------------------------------------------------------------------------------
Inventory::Inventory() {}

// ------------------------------------destructor-----------------------------------------------
// Description:
// -------------------------------------------------------------------------------------------------------------
Inventory::~Inventory() {}

// ------------------------------------perform-----------------------------------------------
// Description: displays all movies and their stocks
// -------------------------------------------------------------------------------------------------------------
void Inventory::display(BinTree& comedyTree, BinTree& dramaTree, BinTree& classicTree, CustomerHash& customerTable, char c, int a, string b)
{
    cout << "--------------MOVIES INVENTORY--------------" << endl << endl;
    cout << "COMEDY MOVIES:" << endl << endl;
    cout << comedyTree << endl;
    cout << "DRAMA MOVIES:" << endl << endl;
    cout << dramaTree << endl;
    cout << "CLASSICS MOVIES:" << endl << endl;
    cout << classicTree << endl;
}
