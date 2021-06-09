
// ------------------------------------------------ movie.h -------------------------------------------------------
// Programmer Name Course Section Number 
// Phuong Phan CSS343 section B
// Creation Date 
// 6/1/21
// Date of Last Modification 
// 6/8/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of movie.cpp file is to contain the implementation of the Movie class's methods. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// to keep track of movies, we use binary search trees. 
// --------------------------------------------------------------------------------------------------------------------
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
