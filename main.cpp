// ------------------------------------------------ main.cpp --------------------------------------------------------
// Programmer Name Course Section Number 
// Alex Xiong CSS343 section B
// Creation Date 
// 6/7/21
// Date of Last Modification 
// 6/9/21
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of the program's function 
// purpose of main.cpp is to test the business.cpp class and its functionality. 
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// main.cpp creates a business object and calls its respective methods. 
// --------------------------------------------------------------------------------------------------------------------

#include "business.h"
#include <iostream>

using namespace std;


// ------------------------------------main---------------------------------------------------------
// Pre-conditions: none
// Post-conditions: none
// Description: creates a business object and calls its respective methods to thoroughly test
// its functionality. 
// --------------------------------------------------------------------------------------------------- 
int main() //main driver function
{
    Business b1;

    //comment for now
    cout << "Read the movie data" << endl;
    b1.buildMovies();

    cout << "Build Customer Hash Table" << endl;
    b1.buildCustomers();

    cout << "Process command" << endl;
    b1.processTrans();

    cout << "We are done" << endl;
    return 0;
} // end of main
