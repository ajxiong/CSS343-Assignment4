#include "customer.h"
#include <iostream>

Customer::Customer()
{
    firstName = " ";
    lastName = " ";
    id = 0;
}

Customer::Customer(string first, string last, int custID)
{
    firstName = first;
    lastName = last;
    id = custID;
}

Customer::~Customer(){}

void Customer::setCustomer()
{

}

void Customer::display()
{

}

void Customer::addTrans()
{
    
}

void Customer::setID(const int &ID)
{
    id = ID;
}

int Customer::getID() const
{
    return id;
}

string Customer::getFirstName() const
{
    return firstName;
}

string Customer::getLastName() const
{
    return lastName;
}

Customer& Customer::operator=(const Customer &other)
{
    //cout << "operator= " << other.getID() << endl;
    id = other.id;
    firstName = other.firstName;
    lastName = other.lastName;
    return *this;
}