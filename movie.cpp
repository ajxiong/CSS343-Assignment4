
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

void Movie::setStock(int stockNum) {
    stock = stockNum;
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

void Movie::setReleaseDate(string releaseDateStr) {
    releaseDate = releaseDateStr;
}

void Movie::setMajorActor(string majorActorStr) {
    majorActor = majorActorStr;
}