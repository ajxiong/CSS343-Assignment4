
#include "movie.h"

// ------------------------------------constructor-----------------------------------------------
// Description: sets year, director and title to default
// -------------------------------------------------------------------------------------------------------------
Movie::Movie()
{
    year = "";
    director = "";
    title = "";
    stock = 0;
}

Movie::~Movie() {

}

string Movie::getTitle() const{
    return title;
}

string Movie::getDirector() const {
    return director;
}

string Movie::getYear() const {
    return year;
}

string Movie::getMonth() const {
    return month;
}

string Movie::getFirstName() const {
    return firstName;
}

string Movie::getLastName() const {
    return lastName;
}

int Movie::getStock() const {
    return stock;
}


void Movie::setTitle(string titleStr) {
    title = titleStr;
}

void Movie::setDirector(string directorStr) {
    director = directorStr;
}

void Movie::setYear(string yearStr) {
    year = yearStr;
}

void Movie::setMonth(string monthStr) {
    month = monthStr;
}

void Movie::setFirstName(string firstStr) {
    first = firstStr;
}

void Movie::setLastName(string lastStr) {
    last = lastStr;
}

void Movie::setStock(int stockNum) {
    stock = stockNum;
}
