// ------------------------------------------------ movie.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of movie.h file is to contain the Movie class, its methods, encapsulation, and data fields. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// to keep track movies, we use binary search tree. 
// --------------------------------------------------------------------------------------------------------------------
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include "nodedata.h"
using namespace std;

class Movie
{
public:
        //Constructor
        Movie();

        //Destructor
        ~Movie();

        //Displays
        //void display();

        //Overriding operators
        // bool operator==(const Movie &) const;
        // bool operator!=(const Movie &) const;
        // bool operator<(const Movie &) const;
        // bool operator>(const Movie &) const;

        //Getter
        int getStock() const;
        string getTitle() const;
        string getDirector() const;
        string getYear() const;

        //Setter
        void setStock(int);
        void setTitle(string);
        void setDirector(string);
        void setYear(string);
        void setReleaseDate(string);
        void setMajorActor(string);


        //virtual NodeData* makeNode();

    protected:
        string title;
        string director;
        string year;
        string releaseDate;
        string majorActor;
        int stock;
};
#endif
