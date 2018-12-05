#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "tools9.h"

using std::cout;
using std::endl;

/* Function overloads for simple functions that gets user input as either a
 * string or enter key press. */
void op_enter();
void op_enter( std::string& option, const std::string& DEFVAL );

int main() {
    /* The variables and containers that will be used in main */
    std::ifstream infile;
    std::ofstream outfile;
    std::ostringstream output;
    std::string line, outfilename = "", infilename = "";
    bool end = false;

    cout << "This program will draw different shapes based on the contents\n"
            "an input file. Make sure the contents are properly formatted for\n"
            "the shapes you want.\n";

    /* Ask the user for a file name to open, but use a default name if none is
     * provided by the user. */
    cout << "Please input the name or path to the file you want to read from.\n";
    op_enter(infilename, DEFAULT_IN);
    infile.open(infilename);

    /* Check is file could be opened before continuing. */
    if( ! infile.good() ) {
        cout << "Could not open the file. Make sure the file exists and you\n"
                "have the correct permissions to read it.\n";
        op_enter();
    }
    else {
        while( ! infile.eof() ) {

            /* Get a line from the input file with each loop. */
            std::getline(infile, line);

            /* Put the return shape from parse_line() in a string stream for
             * later output during output file write. */
            output << parse_line( line, end );

            /* Checks to see if the end character has been found and breaks out
             * of the loop if it has with a notification to the user that this
             * is why the program has stopped. */
            if( end == true ) {
                cout << "Found the end character. Printing output to file buffer.\n\n"
                        "Would you like to give the file a name?\n";
                op_enter(outfilename, DEFAULT_OUT);
                cout << output.str();
                output.seekp(0);
                cout << "Buffer printed to file " << outfilename << '\n';
                break;
            }
            else {
                cout << line << endl;
                cout << "Shape generated for output." << endl;
                line = "";
            }
        }
    }
    /* Close the input file. */
    infile.close();

    /* Open output file and, if successful, push output as string into outfile
     * then close, */
    outfile.open(outfilename);
    if( ! outfile.good() ) {
        cout << "Could not create file to save to.\n";
    }
    else {
        outfile << output.str();
        op_enter();
    }
    outfile.close();

    return 0;
}

/* Can't set a default value for reference parameters if they are not
 * constants, so I used function overloading instead which makes for much
 * cleaner functions that don't require if statements to deal with the
 * differences. */
void op_enter() {
    std::string temp;
    cout << "\n\nPress Enter to continue.";
    std::getline(std::cin, temp);
}

void op_enter( std::string& option, const std::string& DEFVAL ) {
    std::string temp = "";
    cout << "\nPlease enter an option.\n"
        "(leave blank for default '" << DEFVAL << "')\n"
        ":: ";
    std::getline(std::cin, temp);
    option = ( temp == "" )? DEFVAL : temp;
}
