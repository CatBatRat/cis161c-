#include <string>
#include <vector>

#ifndef __TOOLS9__
#define __TOOLS9__

/* Constants for the default file names of input and output. These will also be used
 * in the prompts for user input. */
const std::string DEFAULT_IN = "infile.dat";
const std::string DEFAULT_OUT = "outfile.txt";

std::string parse_line( const std::string& line, bool& end);

std::string diamond( char fill, int width );

std::string square( char fill, int width );

std::string triangle( char fill, int width );

std::string rectangle( char fill, int width, int height );

#endif // __TOOLS9__
