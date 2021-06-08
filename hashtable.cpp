#include "hashtable.h"
#include <iostream>

using namespace std;

Hashtable::Hashtable()
{
    hashTable = nullptr;
    hashTableSize = 0;
}

Hashtable::Hashtable(const int &size)
{
    //call setSize() to initialize size and assign default values to hash array
    hashTable = nullptr;
    hashTableSize = 0;
    setSize(size);
}

Hashtable::~Hashtable()
{
    delete [] hashTable;
    hashTable = nullptr;
}

bool Hashtable::find(const int &custID, Customer* &custPtr) const
{
    bool found = false;
    int hashPosition = custID % hashTableSize;
    if(hashTable[hashPosition].getID() == custID)
    {
        custPtr = &hashTable[hashPosition];
        found = true;
        return found;
    }
    else
    {
        int counter = 1;
        int r = findPrime();
        while(1)
        {
            int hashPosition2 = (hashPosition + (counter * (r - (custID % r)))) % hashTableSize;
            if(hashTable[hashPosition2].getID() == custID)
            {
                found = true;
                return found;
            }
            else if(hashTable[hashPosition2].getID() == 0)
            {
                cout << "Customer ID: " << custID << " not found." << endl;
                break;
            }
            counter++;
        }
    }
    return found;
}

bool Hashtable::isPrime(const int &num) const
{
    bool numIsPrime = true;

    for(int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            numIsPrime = false;
            break;
        }
    }
    return numIsPrime;
}

int Hashtable::findPrime() const
{
    int r = 2;
    for(int i = hashTableSize; i >= 2; i--)
    {
        if(isPrime(i))
        {
            r = i; //r should be 23 here
            break;
        }
    }
    return r;
}

void Hashtable::insertByHash(const Customer &customerData)
{
    int hashPosition;
    //we are going to be using double hash probing
    hashPosition = customerData.getID() % hashTableSize; //this should be 21
    if(hashTable[hashPosition].getID() == 0)
        hashTable[hashPosition] = customerData;
    else
    {
        int counter = 1;
        //find prime number smaller than current hash table size
        int r = findPrime();
        bool positionNotFound = true;
        while(positionNotFound)
        {
            int hashPosition2 = (hashPosition + (counter * (r - (customerData.getID() % r)))) % hashTableSize; //should be 23 here
            if(hashTable[hashPosition2].getID() == 0)
            {
                hashTable[hashPosition2] = customerData;
                positionNotFound = false;
            }
            else
                counter++;
        }
    }
}

void Hashtable::setSize(const int &size)
{
    if(hashTable != nullptr)
    {
        Customer* newTable = new Customer[size];
        for(int i = 0; i < hashTableSize; i++)
            newTable[i] = hashTable[i];
        delete [] hashTable;
        hashTable = newTable;
    }
    else
        hashTable = new Customer[size];
    hashTableSize = size; //assign size to our hash table size. should be 24!
}

int Hashtable::getSize() const
{
    return hashTableSize;
}

void Hashtable::display() const
{
    for(int i = 0; i < hashTableSize; i++)
    {
        if(hashTable[i].getID() != 0)
        {
            cout << "hash position " << i << ": ";
            cout << hashTable[i].getID() << " " << hashTable[i].getFirstName() <<
            " " << hashTable[i].getLastName() << endl;
        }
    }
}
