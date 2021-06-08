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
void Inventory::display(BinTree& comedyTree, BinTree& dramaTree, BinTree& classicTree, Hashtable& table, char a, int b, string c)
{
    cout << "--------------MOVIES INVENTORY--------------" << endl << endl;
    cout << "COMEDY MOVIES:" << endl << endl;
    cout << comedyTree << endl;
    cout << "DRAMA MOVIES:" << endl << endl;
    cout << dramaTree << endl;
    cout << "CLASSICS MOVIES:" << endl << endl;
    cout << classicTree << endl;
}
