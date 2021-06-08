// ------------------------------------------------ customer.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of customer.h file is to contain the Customer class, its methods, encapsulation, and data fields. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// to keep track of customer movie history and due movies, we use vectors. 
// --------------------------------------------------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Customer
{
    private:
    int id;
    string firstName;
    string lastName;
    vector<string> movieDue;
    vector<string> movieHistory;

    public:
    
    // ------------------------------------Customer--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: assigns default values to Customer data fields
    // Description: default constructor initializes default values to class variables
    // --------------------------------------------------------------------------------------------------- 
    Customer(); //end of Customer
    
    // ------------------------------------Customer--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: assigns parameter values to Customer data fields
    // Description: parameterized constructor sets parameter values to class variables
    // --------------------------------------------------------------------------------------------------- 
    Customer(string first, string last, int custID); //end of Customer
    
    // ------------------------------------~Customer--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: default destructor included as a pre-cautionary measure
    // --------------------------------------------------------------------------------------------------- 
    ~Customer(); //end of ~Customer
    
    // ------------------------------------display--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: displays customer movie and transaction history 
    // --------------------------------------------------------------------------------------------------- 
    void display(); //end of display
    
    // ------------------------------------addTrans--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: adds movie and transaction to movieHistory vector
    // --------------------------------------------------------------------------------------------------- 
    void addTrans(string command, string movieTitle); //end of addTrans
    
    // ------------------------------------setID--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: sets customer ID 
    // Description: takes parameter value and assigns it to Customer id class variable 
    // --------------------------------------------------------------------------------------------------- 
    void setID(const int &ID); //end of setID
    
    // ------------------------------------getID--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: returns customer ID
    // --------------------------------------------------------------------------------------------------- 
    int getID() const; //end of getID
    
    // ------------------------------------getFirstName--------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: returns customer's first name
    // --------------------------------------------------------------------------------------------------- 
    string getFirstName() const; //end of getFirstName
    
    // ------------------------------------getLastName--------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: returns customer's last name
    // --------------------------------------------------------------------------------------------------- 
    string getLastName() const; //end of getLastName
    
    // ------------------------------------checkReturn--------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: swaps movie position with the back vector position. 
    // Description: purpose of this method is to traverse through entire movieDue vector and see if 
    // the movie is in the vector. if it is, swap positions with the back vector to pop it off and then
    // return true.
    // --------------------------------------------------------------------------------------------------- 
    bool checkReturn(const string& name); //end of checkReturn
    
    // ------------------------------------operator=--------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: sets current Customer class variables to parameterized Customer variables. 
    // Description: method assigns a customer's information to the current customer. 
    // --------------------------------------------------------------------------------------------------- 
    Customer& operator=(const Customer &other); //end of operator=
};

#endif
