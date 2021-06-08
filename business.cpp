#include "business.h"
#include <iostream>
using namespace std;


Business::Business(){}

Business::~Business(){}

void Business::buildMovies()//FINISHED
{
    char type;
    NodeData* ptr;
    bool flagIn;
    ifstream movieInfile("data4movies.txt");
    if (!movieInfile){
        cout << "File could not be opened." << endl;
        return;
    }
    //factory later....... for now this is fine..
    while(!movieInfile.eof()){
        type = movieInfile.get();

        if(type == 'F'){
            ptr = MovieFactory::createComedy(movieInfile)->makeNode();
            flagIn = comedyTree.insert(ptr);
            if(!flagIn)
                delete ptr;
        }
        else if(type == 'D'){
            ptr = MovieFactory::createDrama(movieInfile)->makeNode();
            flagIn = dramaTree.insert(ptr);
            if(!flagIn)
                delete ptr;
        }
        else if(type == 'C'){
            ptr = MovieFactory::createClassic(movieInfile)->makeNode();
            flagIn = classicTree.insert(ptr);
            if(!flagIn)
                delete ptr;
        }
        else {
            cout << "Movie type is invalid" << endl;
            movieInfile.ignore(100, '\n');
        }
    }
    /*cout << "comedy tree" << endl;
    cout << comedyTree << endl;
    cout << "\ndrama tree" << endl;
    cout << dramaTree << endl;
    cout << "\nclassic tree" << endl;
    cout << classicTree << endl;*/
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
    int custID;
    string movieName, fullTitle, temp, temp2, year, month;
    while(!commandInFile.eof())
    {
        commandInFile.get(command);

        if(command == 'I')
        {
            //CREATE COMMAND FROM COMMAND FACTORY METHOD HERE!!!
            transPtr = createCommand.createTransaction(command);
            //PERFORMS THAT COMMAND'S TRANSACTION 
            transPtr->display(comedyTree, classicTree, dramaTree, custID, fullTitle, genre, table);
            commandInFile.ignore(10, '\n');
            continue;
        }
        commandInFile.get();
        commandInFile >> custID;

        if(command == 'H')
        {
            transPtr = createCommand.createTransaction(command);
            transPtr->display(comedyTree, classicTree, dramaTree, custID, fullTitle, genre, table);
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
            transPtr->display(comedyTree, classicTree, dramaTree, custID, fullTitle, genre, table);
        }
        else if(command == 'R')
        {
            transPtr = createCommand.createTransaction(command);
            transPtr->display(comedyTree, classicTree, dramaTree, custID, fullTitle, genre, table);
        }
    }
}
