//
//  main.cpp
//  Lab 9
//
//  Created by Nick Gray on 11/28/18.
//  Copyright © 2018 Nick Gray. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

void drawDiamond(ofstream &outputFile, char symbol, int width);
void drawSquare(ofstream &outputFile, char symbol, int width);
void drawTriangle(ofstream &outputFile, char symbol, int width);
void drawRectangle(ofstream &outputFile, char symbol, int width, int length);

int main() {

    ifstream filein;
    ofstream fileout;

    string shape;
    char symbol;
    int width;
    int length;

    filein.open("infile.txt");
    fileout.open("fileout.txt", ios::out | ios::app);

    if(!filein.good()) {
        cout << "Failed to read file\n";
    } else {


        while(!filein.eof()) {


            filein >> shape; // Get and determine shape

            if (shape == "D") {
                filein >> symbol >> width;
                drawDiamond(fileout, symbol, width);

            } else if (shape == "S") {
                filein >> symbol >> width;
                drawSquare(fileout, symbol, width);

            } else if (shape == "T") {
                filein >> symbol >> width;
                drawTriangle(fileout, symbol, width);

            } else if (shape == "R") {
                filein >> symbol >> width >> length;
                drawRectangle(fileout, symbol, width, length);

            } else if (shape == "E"){
                filein.close();
                fileout.close();
                return 0;
            } else {
                cout << "invalid shape detected";
                filein.close();
                fileout.close();
                return 0;
            }

        }

    }

}

/********************************
 *
 * drawDiamond
 * --------------------
 * This function takes in‹
 * a symbol and draws a Diamond
 * with given width
 *
 ********************************/
void drawDiamond(ofstream &outputFile, char symbol, int width){

    int space;
    int row = 0;

    for (int i=1; i<2*width; i+=2){

        if(i<=width) {
            row = i;
        }

        if(i>width) {
            row = 2*width-i;
        }

        space = (width-row)/2;

        for (int j=0; j<space; j++){
            cout << " ";
            outputFile << " ";
        }

        for (int j=0; j<row; j++){
            cout << symbol;
            outputFile << symbol;
        }
        cout << endl;
        outputFile << endl;
    }
    cout << endl;
    outputFile << endl;
};

/********************************
 *
 * drawSquare
 * --------------------
 * This function takes in
 * a symbol and draws a Square
 * with given width
 *
 ********************************/
void drawSquare(ofstream &outputFile, char symbol, int width){
    for (int i=0; i < width; i++) {
        for (int i=0; i < width; i++) {
            cout << symbol;
            outputFile << symbol;
        }
        cout << endl;
        outputFile << endl;
    }
    cout << endl;
    outputFile << endl;
};

/********************************
 *
 * drawTriangle
 * --------------------
 * This function takes in
 * a symbol and draws a Triangle
 * with given width
 *
 ********************************/
void drawTriangle(ofstream &outputFile, char symbol, int width){

    for (int i = 0; i <= width; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << symbol;
            outputFile << symbol;
        }
        cout << endl;
        outputFile << endl;
    }
    cout << endl;
    outputFile << endl;
};

/********************************
 *
 * drawRectangle
 * --------------------
 * This function takes in
 * a symbol and draws a Rectangle
 * with given width and length
 *
 ********************************/
void drawRectangle(ofstream &outputFile, char symbol, int width, int length){
    for(int i=0; i < length; i++) {
        for (int i=0; i < width; i++) {
            cout << symbol;
            outputFile << symbol;
        }
        cout << endl;
        outputFile << endl;
    }
    cout << endl;
    outputFile << endl;
};
