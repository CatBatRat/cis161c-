#include <iostream>
#include <sstream>
#include <string>
#include "tools9.h"

using std::endl;
using std::string;
using std::stringstream;

/* This will make the decision about what function to call and check for the E
 * char the signals the end of the file. */
string parse_line( const string& line, bool& end ) {

    char type, fill;
    int width = 0, height = 0;
    stringstream is;
    stringstream os;

    /* Put line into an input stream so the elements can be easily separated
     * out into the correct variable types. */
    is << line;

    /* Separate out each element into the correct containers. I can attempt
     * filling a container and not have to worry about there not being anything
     * there because unlike an array, a stream won't keep going past it's end.
     * */
    is >> type >> fill >> width >> height;

    /* Switch on the first element in the line. */
    switch (type) {
        case 'D':
            os << "\nI drew a diamond made of "<< fill << "\n";
            os << diamond( fill, width );
            break;
        case 'S':
            os << "\nI drew a square made of "<< fill << "\n";
            os << square( fill, width );
            break;
        case 'T':
            os << "\nI drew a triangle made of "<< fill << "\n";
            os << triangle( fill, width );
            break;
        case 'R':
            os << "\nI drew a rectangle made of "<< fill << "\n";
            os << rectangle( fill, width, height );
            break;
        case 'E':
            end = true;
            break;
        /* Make sure to check for invalid input. */
        default:
            os << line;
            os << "\nI'm not sure what you wanted me to draw here.\n"
                    "Moving on to the next one.\n";
            break;
    }
    os << endl;
    return os.str();
}
