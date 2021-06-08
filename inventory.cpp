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
void Inventory::display(BinTree& comedyTree, BinTree& dramaTree, BinTree& classicTree, CustomerHash& customerTable,char a, int b, string c) {
    cout << "MOVIE INVENTORY LIST-------------------" << endl << endl;
    cout << "COMEDY MOVIES: " << endl;
    cout << comedyTree << endl;
    cout << "DRAMA MOVIES: " << endl;
    cout << dramaTree << endl;
    cout << "CLASSICS MOVIES: " << endl;
    cout << classicTree << endl;
}
