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