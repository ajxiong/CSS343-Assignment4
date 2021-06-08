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
    Customer();
    Customer(string first, string last, int custID);
    ~Customer();
    void setCustomer();
    void display(); //display customer command history 
    void addTrans(string command, string movieTitle); //add command action customer performed?
    void getHistory(); //display customer history
    void setID(const int &ID);
    int getID() const;
    string getFirstName() const;
    string getLastName() const;

    Customer& operator=(const Customer &other);
};

#endif