#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "customer.h"
#include <fstream>

using namespace std;

class Hashtable
{
    private:
    Customer* hashTable;
    int hashTableSize;

    int findPrime() const;
    bool isPrime(const int &num) const;

    public:
    Hashtable();
    Hashtable(const int &size);
    ~Hashtable();
    bool find(const int &custID, Customer* &custPtr) const;
    void insertByHash(const Customer &customerData);
    void setSize(const int &size);
    int getSize();
    void display();
};

#endif