#include "transaction.h"
#include "transactionfactorymethod.h"
#include "hashtable.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void buildMovies(BinTree ComedyTree, BinTree DramaTree, BinTree ClassicTree) {
    char type, action, movieType;
    NodeData* ptr;
    bool flag;

    ifstream in("data4movies.txt");
    if (!in){
        cout << "File could not be opened." << endl;
        return 1;
    }
    //factory later....... for now this is fine..
    while(!in.eof()){
        type = in.get();

        if(type == 'F'){
            Comedy ComedyNode;
            ptr = ComedyNode.makeNode(in);
            flag = ComedyTree.insert(ptr);
            if(!flag)
                delete ptr;
        }
        else if(type == 'D'){
            Drama DramaNode;
            ptr = DramaNode.makeNode(in);
            flag = DramaTree.insert(ptr);
            if(!flag)
                delete ptr;
        }
        else if(type == 'C'){
            Classic ClassicNode;
            ptr = ClassicNode.makeNode(in);
            flag = ClassicTree.insert(ptr);
            if(!flag)
                delete ptr;
        }
        else if(type == 'Z'){
            cout << "invalid movie entry" << endl;
            in.ignore(100, '\n');
        }
    }

    cout << endl;
    in.close();
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
    BinTree ComedyTree;
    BinTree DramaTree;
    BinTree ClassicTree;
    void buildMovies(BinTree ComedyTree, BinTree DramaTree, BinTree ClassicTree);
    //comment for now
    //Hashtable hTable1;
    //buildCustomers(hTable1);
    cout << "done" << endl;
    return 0;
}
