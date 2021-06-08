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
        bool setStock(int);
        bool setTitle(string);
        bool setDirector(string);
        bool setYear(string);
        bool setMonth(string);
        bool setFirstName(string);
        bool setLastName(string);

        //virtual NodeData* makeNode();

    protected:
        string title;
        string director;
        string year;
        string month;
        string first;
        string last;
        int stock;
};
#endif