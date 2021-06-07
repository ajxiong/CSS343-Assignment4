#include "transaction.h"
#include "transactionfactorymethod.h"
#include "hashtable.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void buildMovies(BinTree BSTree) {
    char type;
    NodeData* ptr;
    bool flagIn;

    ifstream movieInfile("data4movies.txt");
    if (!movieInfile){
        cout << "File could not be opened." << endl;
        return 1;
    }
    //factory later....... for now this is fine..
    while(!movieInfile.eof()){
        type = movieInfile.get();

        if (type = "F" || type == 'D' ||  type == 'C') {
            ptr = MovieFactory::createMovie(type, movieInfile)->makeNode();
            flagIn = BSTree.insert(ptr);
            if(!flagIn)
                delete ptr;
        }
        else {
            cout << "invalid movie entry" << endl;
            movieInfile.ignore(100, '\n');
        }
    }

    cout << endl;
    movieInfile.close();
}

void buildCustomers(Hashtable &table) //we need to take in/return a hashtable object/pointer??
{
    ifstream customerInfile("data4customers.txt");
	if (!customerInfile) 
    {
		cout << "customer data file could not be opened." << endl;
		return;
	}
    int custID;
    string firstName, lastName;
    vector<Customer*> customerData;
    while(!customerInfile.eof())
    {
        customerInfile >> custID;
        customerInfile.get();
        getline(customerInfile, firstName, ' ');
        getline(customerInfile, lastName, '\n');
        //cout << custID << " " << firstName << " " << lastName << endl;
        //might need to delete every new Customer object created here?
        customerData.push_back(new Customer(firstName, lastName, custID));
        customerInfile.peek();
    }

    //insert customer data by hash method
    table.setSize(customerData.size() * 2); //should be 24
    table.insertByHash(customerData[0]->getID());
    customerInfile.close();
}

void processTrans()
{
    
}

int main() //main driver function 
{
    BinTree BSTree;
    buildMovies(BSTree);
    //comment for now
    //Hashtable hTable1;
    //buildCustomers(hTable1);
    cout << "done" << endl;
    return 0;
}
