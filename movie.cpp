
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

int Movie::getStock() const {
    return stock;
}

bool Movie::setStock(int stockNum) {
    stock = stockNum;
    if (stock < 0) {
        return false;
    } else {
        return true;
    }
}

bool Movie::setTitle(string titleStr) {
    title = titleStr;
    if (title.empty()) {
        return false;
    } else {
        return true;
    }
}

bool Movie::setDirector(string directorStr) {
    director = directorStr;
    if (director.empty()) {
        return false;
    } else {
        return true;
    }
}

bool Movie::setYear(string yearStr) {
    year = yearStr;
    if (year.empty()) {
        return false;
    } else {
        return true;
    }
}

bool Movie::setMonth(string monthStr) {
    month = monthStr;
    if (year.empty()) {
        return false;
    } else {
        return true;
    }
}

bool Movie::setFirstName(string firstStr) {
    first = firstStr;
    if (first.empty()) {
        return false;
    } else {
        return true;
    }
}

bool Movie::setLastName(string lastStr) {
    last = lastStr;
    if (last.empty()) {
        return false;
    } else {
        return true;
    }
}