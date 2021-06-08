#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include "nodedata.h"
using namespace std;

class Movie {
        
protected:
        string title;
        string director;
        string year;
        string month;
        string firstName;
        string lastName;
        int stock;
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
        string getTitle() const;
        string getDirector() const;
        string getYear() const;
        int getStock() const;

        //Setter
        void setTitle(string);
        void setDirector(string);
        void setYear(string);
        void setMonth(string);
        void setFirstName(string);
        void setLastName(string);
        void setStock(int);
        
        //virtual NodeData* makeNode();
};
#endif
