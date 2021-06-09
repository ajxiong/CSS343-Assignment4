// ------------------------------------------------ moviefactory.cpp --------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/9/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of moviefactory.cpp file is to contain the method implementation for the MovieFactory class. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// MovieFactory class is a factory method class that returns a transaction pointer based on the command inputted.
// if none of the correct commands are inputted, the pointer returns nullptr. 
// --------------------------------------------------------------------------------------------------------------------
#include "moviefactory.h"

// ------------------------------------ MovieFactory -------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default constructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
MovieFactory::MovieFactory() { }

// ------------------------------------ ~MovieFactory ------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default constructor included as a pre-cautionary measure
// --------------------------------------------------------------------------------------------------- 
MovieFactory::~MovieFactory() { }

// ------------------------------------createComedy---------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: method returns a Comedy pointer based on the command inputted. since these 
// classes are derrived from the Transaction class, any Transaction pointer will point to that 
// specific derrived class object. 
// --------------------------------------------------------------------------------------------------- 
Comedy* MovieFactory::createComedy(ifstream& infile) {
        int stock;
        string director, title, year;

        infile.get();
        infile.get();
        infile >> stock;
        infile.get();
        infile.get();
        getline(infile, director, ',');
        infile.get();
        getline(infile, title, ',');
        infile.get();
        getline(infile, year, '\n');

        year.erase(4);

        Comedy* comedy = new Comedy();
        comedy->setTitle(title);
        comedy->setDirector(director);
        comedy->setYear(year);
        comedy->setStock(stock);
        return comedy;
}

// ------------------------------------createDrama---------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: method returns a Drama pointer based on the command inputted. since these 
// classes are derrived from the Transaction class, any Transaction pointer will point to that 
// specific derrived class object. 
// --------------------------------------------------------------------------------------------------- 
Drama* MovieFactory::createDrama(ifstream& infile) {
        int stock;
        string director, title, year;

        infile.get();
        infile.get();
        infile >> stock;
        infile.get();
        infile.get();
        getline(infile, director, ',');
        infile.get();
        getline(infile, title, ',');
        infile.get();
        getline(infile, year, '\n');

        year.erase(4);

        Drama* drama = new Drama();
        drama->setTitle(title);
        drama->setDirector(director);
        drama->setYear(year);
        drama->setStock(stock);
        return drama;
}

// ------------------------------------createClassic--------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: method returns a Classic pointer based on the command inputted. since these 
// classes are derrived from the Transaction class, any Transaction pointer will point to that 
// specific derrived class object. 
// --------------------------------------------------------------------------------------------------- 
Classic* MovieFactory::createClassic(ifstream& infile) {
        int stock;
        string director, title, month, year, first, last;

        infile.get();
        infile.get();
        infile >> stock;
        infile.get();
        infile.get();
        getline(infile, director, ',');
        infile.get();
        getline(infile, title, ',');
        infile.get();
        getline(infile, first, ' ');
        getline(infile, last, ' ');
        getline(infile, month, ' ');
        getline(infile, year, '\n');

        year.erase(4);

        Classic* classic= new Classic();
        classic->setTitle(title);
        classic->setDirector(director);
        classic->setReleaseDate(year + ' ' + month);
        classic->setMajorActor(first + ' ' + last);
        classic->setStock(stock);
        return classic;
}
