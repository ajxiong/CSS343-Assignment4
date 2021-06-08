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

void Customer::display()
{
    if (movieHistory.size() == 0) {
        cout << "[No transactions]" << endl;
    }
    for(int i = 0; i < movieHistory.size(); i++)
        cout << movieHistory[i] << endl;
}

void Customer::addTrans(string command, string movieTitle)
{
    movieHistory.push_back(command + " " + movieTitle);
    if(command == "Returned")
        movieDue.pop_back();
    else if(command == "Borrowed")
        movieDue.push_back(movieTitle);
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

bool Customer::checkReturn(const string& name)
{
    for(int i = 0; i < movieDue.size(); i++)
    {
        if(movieDue[i] == name)
        {
            string temp = movieDue.back();
            movieDue.pop_back();
            movieDue.push_back(movieDue[i]);
            movieDue[i] = temp;
            return true;
        }
    }
    return false;
}

Customer& Customer::operator=(const Customer &other)
{
    //cout << "operator= " << other.getID() << endl;
    id = other.id;
    firstName = other.firstName;
    lastName = other.lastName;
    return *this;
}
