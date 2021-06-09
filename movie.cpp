
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

// ------------------------------------ Movie --------------------------------------------------------
// Pre-conditions: none
// Post-conditions: assigns default values to movie data fields
// Description: default constructor initializes default values to class variables
// --------------------------------------------------------------------------------------------------- 
Movie::Movie()
{
    year = "";
    director = "";
    title = "";
    stock = 0;
}

// ---------------------------------------~Movie-------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: default destructor included as a pre-cautionary measure
// ---------------------------------------------------------------------------------------------------- 
Movie::~Movie() {

}

// ----------------------------------------getTittle--------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: returns movie's tittle
// ---------------------------------------------------------------------------------------------------
string Movie::getTitle() const{
    return title;
}

// ----------------------------------------getDirector------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: returns movie's director
// ---------------------------------------------------------------------------------------------------
string Movie::getDirector() const {
    return director;
}


// ----------------------------------------getYear----------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: returns movie's year
// ---------------------------------------------------------------------------------------------------
string Movie::getYear() const {
    return year;
}

// ----------------------------------------getStock---------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: returns movie's stock
// ---------------------------------------------------------------------------------------------------
int Movie::getStock() const {
    return stock;
}

// ----------------------------------------setStock---------------------------------------------------
// Pre-conditions: parameter is valid
// Post-conditions: store the parameter value
// Description: store the parameter value
// ---------------------------------------------------------------------------------------------------
void Movie::setStock(int stockNum) {
    stock = stockNum;
}

// ----------------------------------------setTittle--------------------------------------------------
// Pre-conditions: parameter is valid
// Post-conditions: store the parameter value
// Description: store the parameter value
// ---------------------------------------------------------------------------------------------------
void Movie::setTitle(string titleStr) {
    title = titleStr;
}

// ----------------------------------------setDirector------------------------------------------------
// Pre-conditions: parameter is valid
// Post-conditions: store the parameter value
// Description: store the parameter value
// ---------------------------------------------------------------------------------------------------
void Movie::setDirector(string directorStr) {
    director = directorStr;
}

// ----------------------------------------setYear----------------------------------------------------
// Pre-conditions: parameter is valid
// Post-conditions: store the parameter value
// Description: store the parameter value
// ---------------------------------------------------------------------------------------------------
void Movie::setYear(string yearStr) {
    year = yearStr;
}

// ----------------------------------------setReleaseDate---------------------------------------------
// Pre-conditions: parameter is valid
// Post-conditions: store the parameter value
// Description: store the parameter value
// ---------------------------------------------------------------------------------------------------
void Movie::setReleaseDate(string releaseDateStr) {
    releaseDate = releaseDateStr;
}

// ----------------------------------------setMajorActor----------------------------------------------
// Pre-conditions: parameter is valid
// Post-conditions: store the parameter value
// Description: store the parameter value
// ---------------------------------------------------------------------------------------------------
void Movie::setMajorActor(string majorActorStr) {
    majorActor = majorActorStr;
}
