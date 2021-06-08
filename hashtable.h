// ------------------------------------------------ hashtable.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of hashtable.h file is to contain the Hashtable class, its methods, encapsulation, and data fields. 
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
    
    // ------------------------------------findPrime--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: helper method for insertByHash. returns the first prime number less than the vector size. 
    // --------------------------------------------------------------------------------------------------- 
    int findPrime() const; //end of findPrime
    
    // ------------------------------------isPrime--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: helper method for findPrime. returns true if the parameterized value is a prime number.
    // --------------------------------------------------------------------------------------------------- 
    bool isPrime(const int &num) const; //end of isPrime

    public:
    
    // ------------------------------------Hashtable--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: assigns default values to Hashtable data fields
    // Description: default constructor initializes default values to class variables
    // --------------------------------------------------------------------------------------------------- 
    Hashtable(); //end of Hashtable
    
    // ------------------------------------Hashtable--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: assigns parameterized values to Hashtable data fields
    // Description: parameterized constructor initializes values to class variables
    // --------------------------------------------------------------------------------------------------- 
    Hashtable(const int &size); //end of Hashtable
    
    // ------------------------------------~Hashtable--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: deletes vector data field and assigns nullptr to dynamic vector pointer
    // Description: destructor makes sure that there is no memory leak or unused data left. 
    // --------------------------------------------------------------------------------------------------- 
    ~Hashtable(); //end of ~Hashtable
    
    // ------------------------------------find--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: returns true if method finds customer in vector hashtable. uses double hash probing
    // to find customer in O(1) time. if method finds customer, assigns customer object to customer pointer. 
    // --------------------------------------------------------------------------------------------------- 
    bool find(const int &custID, Customer* &custPtr) const; //end of find
    
    // ------------------------------------insertByHash--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: inserts customer data to hash table
    // Description: inserts customer object to customer pointer vector. uses double hash probing to 
    // insert customer object to vector hash table. 
    // --------------------------------------------------------------------------------------------------- 
    void insertByHash(const Customer &customerData); //end of insertByHash
    
    // ------------------------------------setSize--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: assigns hashtable size from value parameter
    // Description: method sets hashtable size from value parameter. if vector pointer is NOT nullptr,
    // then set the new size of vector and copy old contents of vector to newly created vector. otherwise,
    // create a new vector. 
    // --------------------------------------------------------------------------------------------------- 
    void setSize(const int &size); //end of setSize
    
    // ------------------------------------getSize--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: returns hash table size
    // --------------------------------------------------------------------------------------------------- 
    int getSize() const; //end of getSize
    
    // ------------------------------------display--------------------------------------------------------
    // Pre-conditions: none
    // Post-conditions: none
    // Description: displays current hashtable, customer position, and customer information. 
    // --------------------------------------------------------------------------------------------------- 
    void display() const; //end of display
};

#endif
