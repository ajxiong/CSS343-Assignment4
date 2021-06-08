// ------------------------------------------------ customer.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of customer.cpp file is to contain the implementation of the Customer class's methods. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// to keep track of customer movie history and due movies, we use vectors. 
// --------------------------------------------------------------------------------------------------------------------

#include "customer.h"
#include <iostream>

// ------------------------------------Customer--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: assigns default values to Customer data fields
// Description: default constructor initializes default values to class variables
// --------------------------------------------------------------------------------------------------- 
Customer::Customer()
{
    firstName = " ";
    lastName = " ";
    id = 0;
}//end of Customer

 // ------------------------------------Customer--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: assigns parameter values to Customer data fields
// Description: parameterized constructor sets parameter values to class variables
// --------------------------------------------------------------------------------------------------- 
Customer::Customer(string first, string last, int custID)
{
    firstName = first;
    lastName = last;
    id = custID;
} //end of Customer

// ------------------------------------~Customer--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default destructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Customer::~Customer(){} //end of ~Customer

// ------------------------------------display--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: displays customer movie and transaction history 
// --------------------------------------------------------------------------------------------------- 
void Customer::display()
{
    if (movieHistory.size() == 0) {
        cout << "[No transactions]" << endl;
    }
    for(int i = 0; i < movieHistory.size(); i++)
        cout << movieHistory[i] << endl;
} //end of display

// ------------------------------------addTrans--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: adds movie and transaction to movieHistory vector
// --------------------------------------------------------------------------------------------------- 
void Customer::addTrans(string command, string movieTitle)
{
    movieHistory.push_back(command + " " + movieTitle);
    if(command == "Returned")
        movieDue.pop_back();
    else if(command == "Borrowed")
        movieDue.push_back(movieTitle);
} //end of addTrans

// ------------------------------------setID--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: sets customer ID 
// Description: takes parameter value and assigns it to Customer id class variable 
// --------------------------------------------------------------------------------------------------- 
void Customer::setID(const int &ID)
{
    id = ID;
} //end of setID

// ------------------------------------getID--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: returns customer ID
// --------------------------------------------------------------------------------------------------- 
int Customer::getID() const
{
    return id;
}//end of getID


// ------------------------------------getFirstName--------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: returns customer's first name
// ---------------------------------------------------------------------------------------------------
string Customer::getFirstName() const
{
    return firstName;
} //end of getFirstName

// ------------------------------------getLastName--------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: returns customer's last name
// --------------------------------------------------------------------------------------------------- 
string Customer::getLastName() const
{
    return lastName;
}//end of getLastName

// ------------------------------------checkReturn--------------------------------------------------
// Pre-conditions: none
// Post-conditions: swaps movie position with the back vector position. 
// Description: purpose of this method is to traverse through entire movieDue vector and see if 
// the movie is in the vector. if it is, swap positions with the back vector to pop it off and then
// return true.
// --------------------------------------------------------------------------------------------------- 
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
} //end of checkReturn

// ------------------------------------operator=--------------------------------------------------
// Pre-conditions: none
// Post-conditions: sets current Customer class variables to parameterized Customer variables. 
// Description: method assigns a customer's information to the current customer. 
// --------------------------------------------------------------------------------------------------- 
Customer& Customer::operator=(const Customer &other)
{
    //cout << "operator= " << other.getID() << endl;
    id = other.id;
    firstName = other.firstName;
    lastName = other.lastName;
    return *this;
} //end of operator=
