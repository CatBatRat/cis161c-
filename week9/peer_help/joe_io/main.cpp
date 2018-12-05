#include <iostream>
#include <fstream>
#include "functions.hpp"

using namespace std;

int main()
{
    //define infile as an input file
    ifstream infile;
    infile.open ("infile.txt");
    //define outfile as an output file
    ofstream outfile;
    outfile.open ("outfile.txt");

    if (!infile.good()){
        cout << "Couldn't open..." << endl;
    }else// all is good, continue with rest of program
	{
	    int value = 6;
		char type;
		char symbol;
		int width;
		int length;

        do{
            infile >> type;
            infile >> symbol;
            infile >> width;
            if (type == 'D'){
                D_function(symbol, width);
                outfile << D_function(symbol, width);
            }else if (type == 'R'){
                infile >> length;
                R_function(symbol, width, length);
                outfile << R_function(symbol, width, length);
            }else if (type == 'S'){
                S_function(symbol, width);
                outfile << S_function(symbol, width);
            }else if (type == 'T'){
                T_function(symbol, width);
                outfile << T_function(symbol, width);
            }else if (type == 'E'){
                E_function(infile);
                E_function(outfile);
            }
        }while(!infile.eof());
        infile.close();
	}

    return 0;
}

