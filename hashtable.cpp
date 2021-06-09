// ------------------------------------------------ hashtable.cpp -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of hashtable.cpp file is to contain the Hashtable class methods implementation. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// to keep track of customer information and hash implementation, we use a vector with double the size of total customers. 
// for hash insertion and probing, we use double hashing. instructions for double hash insertion are as follows:
/*
 1. first find vector position by customer ID % vector size.
    if vector position is empty, then we can assign it there. 
 2. if vector position is NOT empty, then we must use following double hashing probing method: 
    hashPosition2 = (hashPosition + (counter * (r - (customerData.getID() % r)))) % hashTableSize
    r is any prime number less than the vector size. EX - if vector size is 24, then r is 23. 
    we keep using this method and loop through until we find an empty spot within our vector. 
*/
// additionally, we also use the double hash probing method in a similar fashion for our find() function. 
// --------------------------------------------------------------------------------------------------------------------

#include "hashtable.h"
#include <iostream>

using namespace std;

// ------------------------------------Hashtable--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: assigns default values to Hashtable data fields
// Description: default constructor initializes default values to class variables
// --------------------------------------------------------------------------------------------------- 
Hashtable::Hashtable()
{
    hashTable = nullptr;
    hashTableSize = 0;
}//end of Hashtable

// ------------------------------------Hashtable--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: assigns parameterized values to Hashtable data fields
// Description: parameterized constructor initializes values to class variables
// --------------------------------------------------------------------------------------------------- 
Hashtable::Hashtable(const int &size)
{
    //call setSize() to initialize size and assign default values to hash array
    hashTable = nullptr;
    hashTableSize = 0;
    setSize(size);
}//end of HashTable

// ------------------------------------~Hashtable--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: deletes vector data field and assigns nullptr to dynamic vector pointer
// Description: destructor makes sure that there is no memory leak or unused data left. 
// --------------------------------------------------------------------------------------------------- 
Hashtable::~Hashtable()
{
    delete [] hashTable;
    hashTable = nullptr;
}//end of ~Hashtable

// ------------------------------------find--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: returns true if method finds customer in vector hashtable. uses double hash probing
// to find customer in O(1) time. if method finds customer, assigns customer object to customer pointer. 
// --------------------------------------------------------------------------------------------------- 
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
                custPtr = &hashTable[hashPosition2];
                found = true;
                return found;
            }
            else if(hashTable[hashPosition2].getID() == 0)
                break;
            counter++;
        }
    }
    return found;
} //end of find

// ------------------------------------isPrime--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: helper method for findPrime. returns true if the parameterized value is a prime number.
// --------------------------------------------------------------------------------------------------- 
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
} //end of isPrime

// ------------------------------------findPrime--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: helper method for insertByHash. returns the first prime number less than the vector size. 
// --------------------------------------------------------------------------------------------------- 
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
} //end of findPrime

// ------------------------------------insertByHash--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: inserts customer data to hash table
// Description: inserts customer object to customer pointer vector. uses double hash probing to 
// insert customer object to vector hash table. 
// --------------------------------------------------------------------------------------------------- 
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
} //end of insertByHash

// ------------------------------------setSize--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: assigns hashtable size from value parameter
// Description: method sets hashtable size from value parameter. if vector pointer is NOT nullptr,
// then set the new size of vector and copy old contents of vector to newly created vector. otherwise,
// create a new vector. 
// --------------------------------------------------------------------------------------------------- 
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
} //end of setSize

// ------------------------------------getSize--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: returns hash table size
// --------------------------------------------------------------------------------------------------- 
int Hashtable::getSize() const
{
    return hashTableSize;
} //end of getSize

// ------------------------------------display--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: displays current hashtable, customer position, and customer information. 
// --------------------------------------------------------------------------------------------------- 
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
} //end of display
