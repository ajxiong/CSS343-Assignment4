#include "business.h"
#include <iostream>
#include "moviefactory.h"
using namespace std;


Business::Business(){}

Business::~Business(){}

void Business::buildMovies(){
    ifstream movieInfile("data4movies.txt");
    if (!movieInfile){
        cout << "Movie files cannot be opened." << endl;
        return;
    }
	
    NodeData* movieNode;
    char type;
    bool ifInsert;
	
    while(!movieInfile.eof()){
        type = movieInfile.get();
        if(type == 'F') {
            movieNode = MovieFactory::createComedy(movieInfile)->makeNode();
            ifInsert = comedyTree.insert(movieNode);
            if(!ifInsert) {
                delete node;
	    }
        }
        else if(type == 'D') {
            movieNode = MovieFactory::createDrama(movieInfile)->makeNode();
            ifInsert = dramaTree.insert(movieNode);
            if(!ifInsert)
                delete movieNode;
        }
        else if(type == 'C') {
            movieNode = MovieFactory::createClassic(movieInfile)->makeNode();
            ifInsert = classicTree.insert(movieNode);
            if(!ifInsert)
                delete movieNode;
        }
        else {
            cout << "Movie type is invalid" << endl;
            movieInfile.ignore(100, '\n');
        }

    cout << endl;
    movieInfile.close();
}

void Business::buildCustomers() //FINISHED
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
    //adding customer data to our Customer vector
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

    //take Customer vector and insert customer data by hash method
    table.setSize(customerData.size() * 2); //should be 24
    for(int i = 0; i < customerData.size(); i++)
    {
        table.insertByHash(*customerData[i]);
        delete customerData[i];
    }
    table.display();
    //test find function
    Customer* custPtr = nullptr;
    bool found = table.find(5000, custPtr);
    
    customerInfile.close();
}

void Business::processTrans() //NOT FINISHED
{
    ifstream commandInFile("data4commands.txt");
    if(!commandInFile)
    {
        cout << "command file could not be opened" << endl;
        return;
    }
    TransactionFactoryMethod createCommand;
    Transaction* transPtr;
    char command, dvd, genre;
    int custID, year;
    string movieName;
    /*while(!commandInFile.eof())
    {
        commandInFile.get(command);

        if(command == 'I')
        {
            transPtr = createCommand.createTransaction(command);
            transPtr->doTrans();
            commandInFile.ignore(10, '\n');
            continue;
        }
        commandInFile.get();
        commandInFile >> custID;

        if(command == 'H')
        {
            transPtr = createCommand.createTransaction(command);
            transPtr->doTrans();
            commandInFile.ignore(10, '\n');
            continue;
        }

        commandInFile.get();
        commandInFile.get(dvd);

        if(dvd != 'D')
        {
            commandInFile.ignore(100, '\n');
            continue;
        }

        commandInFile.get();
        commandInFile.get(genre);
        commandInFile.get();

        switch(genre)
        {
            case 'F' : getline(commandInFile, movieName, ',');
            commandInFile.get();
            getline(commandInFile, year, '\n');
            year.erase(4);
            
            break;
        }
    }*/
}
