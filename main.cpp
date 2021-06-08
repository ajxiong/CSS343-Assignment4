#include "business.h"
#include <iostream>

using namespace std;

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
}