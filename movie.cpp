#include "movie.h"

Movie::Movie() {
    year = 0;
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

int Movie::getYear() const {
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

bool Movie::setYear(int yearInt) {
    year = yearInt;
    if (year <= 0) {
        return false;
    } else {
        return true;
    }
}