#include "classic.h"

Classic::Classic() {

}

Classic::~Classic() {

}

NodeData* Classic::makeNode(istream& file) {
    int stock;
    string director, title, month, year, first, last, temp;

    file.get();
    file.get();
    file >> stock;
    file.get();
    file.get();
    getline(file, director, ',');
    file.get();
    getline(file, title, ',');
    file.get();
    getline(file, first, ' ');
    getline(file, last, ' ');
    getline(file, month, ' ');
    getline(file, year, '\n');

    year.erase(4);

    NodeData* newClassic = new NodeData(year +" " +  month + " " +  first + " " +  last, stock);

    return newClassic;
}