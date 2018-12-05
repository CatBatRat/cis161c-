// This program opens an existing file and appends to it (adds stuff at the end)

#include <iostream>

 // include fstream any time you are reading or writing to a file
#include <fstream>

using namespace std;

int main()
{
        // first we will open and read the file to see
        // how it looks before we change it
        // This is the simply reading a file and copying
        // it to the console.
    ifstream infile;
    infile.open("append.txt");
    string buffer;
        // read a line from the file and display it on the console
    while ( !infile.eof() )
    {
        getline(infile, buffer);
        cout << buffer << endl;
    }
        // Close the file when we are done.
    infile.close();
    

        // now add some stuff to it

		// define outfile as an ofstream -- this is the file you will be writing to
		// you can use any name, just like any other variable
	ofstream outfile;

		// now that outfile is defined, open the file you want to write to
		// use the ios::app flag to tell the system you want to append to the file
		// instead of deleting it and starting over
		// if the file does not exist, it will be created
	outfile.open("append.txt", ios::app);

        // Lets add a couple of lines
    outfile << "this is added line one\n";
    outfile << "and this is added line two\n";

        // always close your file when you are done
    outfile.close();


        // now see how it looks
        // Again, this is identical to the above code
        // reading from a file and writing it to the console.
    cout << endl << " after appending " << endl << endl;
    infile.open("append.txt");
    while ( !infile.eof() )
    {
        getline(infile, buffer);
        cout << buffer << endl;
    }
    infile.close();

    return 0;
}
