#include <iomanip>
#include <sstream>
#include <string>
#include "tools9.h"

using std::string;
using std::setw;
using std::ostringstream;

/* This one turned out to be very simple. I had thought I would need something
 * to check when it got to the halfway point until I realized a diamond is just
 * two triangles. :) */
string diamond(char fill, int width) {

    /* I use a string stream because it makes it much easier to work with other
     * data types. I really wish we had known about this when we were doing the
     * lab with the calculator. Would have made my one liner input much easier
     * to parse. */
    ostringstream out;

    /* This is a check to ensure the width is always an odd number, as an even
     * number would mess up the look of the diamond. */
    width = ( width%2 == 0 )? width+1:width;
    int buff = width/2+1;
    for( int x = 0; x < width/2; x++ ) {
        out << setw((buff-x));
        out << fill;

        /* Simply use a string to create each line of chars as I feel it makes
         * the code a lot easier to follow than using nested loops to do such a
         * simple thing. */
        out << string(x*2,fill);
        out << '\n';
    }
    for( int x = width/2; x >= 0; --x ) {
        out << setw((buff-x));
        out << fill;
        out << string(x*2,fill);
        out << '\n';
    }
    /* Return the stream object out as a string. */
    return out.str();
}

string rectangle(char fill, int width, int height) {
    ostringstream out;
    for( int x = 0; x<height; x++ ) {
        out << string(width, fill) ;
        out << '\n';
    }
    return out.str();
}

string square(char fill, int width) {
    ostringstream out;
    for( int x = 0; x<width; x++ ) {
        out << string(width, fill) ;
        out << '\n';
    }
    return out.str();
}

string triangle(char fill, int width) {
    ostringstream out;
    for( int x = 0; x<width; x++ ) {
        out << string(x+1, fill);
        out << '\n';
    }
    return out.str();
}
