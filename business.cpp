// ------------------------------------------------ business.cpp -------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of business.h file is to contain the method implementation from the Business class. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// each method takes a .txt file and reads in data from that .txt file. 
// --------------------------------------------------------------------------------------------------------------------

#include "business.h"
#include <iostream>
using namespace std;

// ------------------------------------Business--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default constructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Business::Business(){} //end of Business

// ------------------------------------~Business--------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default destructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
Business::~Business(){} //end of ~Business

// ------------------------------------buildMovies--------------------------------------------------
// Pre-conditions: none
// Post-conditions: assigns each movie genre type to its respective genre binary search tree. 
// Description: buildMovies reads in movie data and assigns each movie to a tree based on genre 
// type. method also takes in any data error reading. 
// --------------------------------------------------------------------------------------------------- 
void Business::buildMovies()
{
    ifstream movieInfile("data4movies.txt");
    if (!movieInfile) {
        cout << "File could not be opened." << endl;
        return;
    }

    char type;
    int invalidCount;
    NodeData* movieNode;
    bool ifInsert;

    while(!movieInfile.eof()) {
        type = movieInfile.get();

        if(type == 'F') {
            movieNode = MovieFactory::createComedy(movieInfile)->makeNode();
            ifInsert = comedyTree.insert(movieNode);
            if(!ifInsert)
                delete movieNode;
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
            cout << "Movie code is invalid" << endl;
	    invalidCount++;
            movieInfile.ignore(100, '\n');
        }
    }
    cout << endl << "There are " << invalidCount << " invalid codes in the data file" << endl;
    cout << endl;
    movieInfile.close();
} //end of buildMovies

// ------------------------------------buildCustomers--------------------------------------------------
// Pre-conditions: none
// Post-conditions: assigns customer information to hash table object. 
// Description: buildCustomers takes in customer information and inserts them as NodeData into
// the hash table object. 
// --------------------------------------------------------------------------------------------------- 
void Business::buildCustomers()
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
    //table.display();

    customerInfile.close();
} //end of buildCustomers

// ------------------------------------processTrans--------------------------------------------------
// Pre-conditions: none
// Post-conditions: modifies movie trees and customer history based on transaction commands and 
// other information
// Description: processTrans takes in transaction commands and other information to modify movie
// trees and customer history. method also takes in any data error reading. 
// --------------------------------------------------------------------------------------------------- 
void Business::processTrans()
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
    int custID;
    string movieName, fullTitle, temp, temp2, year, month;
    while(!commandInFile.eof())
    {
        commandInFile.get(command);

	if(command == 'X')
        {
            commandInFile.ignore(10, '\n');
            continue;
        }

        if(command == 'I')
        {
            //CREATE COMMAND FROM COMMAND FACTORY METHOD HERE!!!
            transPtr = createCommand.createTransaction(command);
            //PERFORMS THAT COMMAND'S TRANSACTION
            transPtr->display(comedyTree, classicTree, dramaTree, table, genre, custID, fullTitle);
            commandInFile.ignore(10, '\n');
            continue;
        }
        commandInFile.get();
        commandInFile >> custID;

        if(command == 'H')
        {
            transPtr = createCommand.createTransaction(command);
            transPtr->display(comedyTree, classicTree, dramaTree, table, genre, custID, fullTitle);
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
            case 'F' :
            getline(commandInFile, movieName, ',');
            commandInFile.get();
            getline(commandInFile, year, '\n');
            year.erase(4);
            fullTitle = movieName + " " + year;
            break;

            case 'D' :
            getline(commandInFile, temp, ' ');
            getline(commandInFile, temp2, ',');
            commandInFile.get();
            getline(commandInFile, movieName, ',');
            commandInFile.ignore(10, '\n');
            fullTitle = temp + " " + temp2 + " " + movieName;
            break;

            case 'C' :
            commandInFile >> month;
            commandInFile.get();
            commandInFile >> year;
            commandInFile.get();
            getline(commandInFile, temp, ' ');
            getline(commandInFile, temp2, '\n');
            temp2.erase(temp2.size() - 1);
            fullTitle = year + " " + month + " " + temp + " " + temp2;
            break;

            case 'Z' :
            commandInFile.ignore(100, '\n');
            default : break;
        }
        if(command == 'B')
        {
            transPtr = createCommand.createTransaction(command);
            transPtr->display(comedyTree, classicTree, dramaTree, table, genre, custID, fullTitle);
        }
        else if(command == 'R')
        {
            transPtr = createCommand.createTransaction(command);
            transPtr->display(comedyTree, classicTree, dramaTree, table, genre, custID, fullTitle);
        }
    }
} //end of processTrans
