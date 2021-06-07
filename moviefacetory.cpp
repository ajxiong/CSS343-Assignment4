#include "moviefactory.h"

MovieFactory::MovieFactory() { }

MovieFactory::~MovieFactory() { }

Movie* MovieFactory::createMovie(const char type, ifstream& infile) {
    Movie* movie = nullptr;
    if (type == 'D') {
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

        movie = new Drama();
        movie->setTitle(title);
        movie->setDirector(director);
        movie->setYear(year);
        movie->setStock(stock);
    } else if (type == 'F') {
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

        movie = new Comedy();
        movie->setTitle(title);
        movie->setDirector(director);
        movie->setYear(year);
        movie->setStock(stock);

    } else if (type == 'C') {
        int stock;
        string director, title, month, year, first, last, temp;

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

        movie = new Classic();
        movie->setTitle(title);
        movie->setDirector(director);
        movie->setYear(year);
        movie->setStock(stock);
        movie->setFirstName(first);
        movie->setLastName(last);
        movie->setMonth(month);
    }

    return movie;
}