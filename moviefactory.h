// ------------------------------------------------ transactionfactorymethod.h --------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/9/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of moviefactory.h file is to contain the MovieFactory class, its methods, 
// data fields, and encapsulation. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// TransactionFactoryMethod is a factory method class that returns a transaction pointer based on the command inputted.
// if none of the correct commands are inputted, the pointer returns nullptr. 
// --------------------------------------------------------------------------------------------------------------------
#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H
#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classic.h"

class MovieFactory {
    public:
        MovieFactory(); //constructor
        ~MovieFactory(); //destructor
    
        //static Movie* createMovie(const char type, ifstream& infile) { };
        //creater pointer
        static Comedy* createComedy(ifstream& infile);
        static Drama* createDrama(ifstream& infile);
        static Classic* createClassic(ifstream& infile);
};
#endif
