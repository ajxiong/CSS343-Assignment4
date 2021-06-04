#ifndef movie_h
#define movie_h

#include <string>
#include <iostream>
#include "nodedata.h"

class Movie {
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
        int getYear() const;

        //Setter
        bool setStock(int);
        bool setTitle(string);
        bool setDirector(string);
        bool setYear(int);

    protected:
        string title;
        string director;
        int year;
        int stock;
};
#endif