#include "borrow.h"

Borrow::Borrow(){}
Borrow::~Borrow(){}

void Borrow::display(BinTree& comedyTree, BinTree& classicTree, BinTree& dramaTree, int custID, string name, char genre, Hashtable& table)
{
    Customer* customerPtr = nullptr;
    NodeData* moviePtr = nullptr;
    bool foundCustomer = table.find(custID, customerPtr);
    bool foundMovie = false;
    NodeData movie(name);
    int stock = 0;
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
        if(stock > 0)
        {
            moviePtr->setStock(stock - 1);
            customerPtr->addTrans("Borrowed", name);
        }
        else
            cout << name <<  " is currently out of stock" << endl;
    }
    else
        cout << "customer ID: " << custID <<  " could not be found" << endl;
}
