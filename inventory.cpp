#include "inventory.h"

Inventory::Inventory() {}

Inventory::~Inventory() {}

void Inventory::perform(BinTree& comedyTree, BinTree& dramaTree, BinTree& classicTree, int a, string b, char c, Hashtable& customerTable)
{
    cout << "----------COMEDY MOVIES----------" << endl;
    cout << comedyTree << endl;
    cout << "----------DRAMA MOVIES----------" << endl;
    cout << dramaTree << endl;
    cout << "----------CLASSICS MOVIES----------" << endl;
    cout << classicTree << endl;
}
