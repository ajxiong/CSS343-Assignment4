#include "drama.h"

Drama::Drama() {

}

Drama::~Drama() {

}

NodeData* Drama::makeNode(istream& file){
    int stock;
    string director, title, year;

    file.get();
    file.get();
    file >> stock;
    file.get();
    file.get();
    getline(file, director, ',');
    file.get();
    getline(file, title, ',');
    file.get();
    getline(file, year, '\n');

    year.erase(4);

    NodeData* newDrama = new NodeData(director + " " + title, stock);

    return newDrama;
}