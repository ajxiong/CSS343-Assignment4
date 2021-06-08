#include "return.h"

Return::Return(){}

Return::~Return(){}

void Return::display(BinTree& comedyTree, BinTree& classicTree, BinTree& dramaTree, int custID, string name, char genre, Hashtable& table)
{
    Customer* customerPtr = nullptr;
    NodeData* moviePtr = nullptr;
    bool foundCustomer = table.find(custID, customerPtr);
    bool foundMovie = false;
    NodeData movie(name);
    int stock;
    switch(genre)
    {
        case 'F' :
        foundMovie = comedyTree.retrieve(movie, moviePtr);
        break;
        case 'D' :
        foundMovie = dramaTree.retrieve(movie, moviePtr);
        break;
        case 'C' :
        foundMovie = classicTree.retrieve(movie, moviePtr);
        break;
        default :
        break;
    }
    if(foundMovie)
        stock = moviePtr->getStock();
    else
        cout << name << " does not exist in movie store" << endl;
    if(foundCustomer)
    {
        bool movieIsDue = customerPtr->checkReturn(name);
        if(movieIsDue)
        {
            customerPtr->addTrans("Returned", name);
            moviePtr->setStock(stock + 1);
        }
        else
            cout << "Customer ID: " << custID << " has never checked out: " << name << endl;
    }
    else
        cout << "Customer ID: " << custID << " does not exist" << endl;
}
