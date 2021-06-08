#include "moviefactory.h"

MovieFactory::MovieFactory() { }

MovieFactory::~MovieFactory() { }

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