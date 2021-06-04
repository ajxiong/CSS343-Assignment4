#include "comedy.h"

Comedy::Comedy() {

}

Comedy::~Comedy() {

}

NodeData* Comedy::makeNode(istream& file) {
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

    NodeData* newComedy = new NodeData(title + " " + year, stock);

    return newComedy;
}

bool Comedy::operator==(const Comedy& c2) const {
    return ((this->getTitle() == c2.getTitle()) && (this->getYear() == c2.getYear()));
}

bool Comedy::operator!=(const Comedy& c2) const {
    return !(*this == c2);
}

bool Comedy::operator>(const Comedy& c2) const {
    if(this->getTitle() != c2.getTitle()) {
        return (this->getTitle() > c2.getTitle());
    }
    return (this->getYear() > c2.getYear());
}

bool Comedy::operator<(const Comedy& c2) const {
    if(this->getTitle() != c2.getTitle()) {
        return (this->getTitle() < c2.getTitle());
    }
    return (this->getYear() < c2.getYear());
}