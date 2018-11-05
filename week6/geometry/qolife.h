#ifndef __QO_LIFE__
#define __QO_LIFE__

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <limits>
#include <sstream>
#include <thread>
#include <chrono>


int _validate(std::vector<std::string>&,int limit=0);

std::string _dec_string(double, int prec=2);

void _print_center(std::vector<std::string>&, int width, char sfill='#');

void _sleep(int sleep_time);

void _cin_clear();

void _print_line(int iters);

void _scroller(std::string,int width,std::string direc="left");

double long _g_positive(std::string prompt);

void _clear() {
    char clear_screen[] = "clear";
    std::cout << std::flush;
    std::system(clear_screen);
}

/* This function uses 'vectors' which allow for a greater degree of
 * options when manipulating the contents, passing by reference, or
 * adding additional elements.*/
int _validate(std::vector<std::string>& check,int limit) {
    int option;
    std::string output = "";
    if( limit == 0 ) limit=check.size();
    else limit = limit+1;
    do {
        std::cout << std::endl << check[0] << std::endl;
        /* Use the size (number of elements) of the vector to determine
         * how many to print and which number to show next to each option.*/
        for( int x=1;x<limit;x++ ) {
            output = std::to_string(x) + " " + check[x];
            _scroller(output,40,"right");
            std::cout << std::endl;
        }
        std::cin >> option;
        /* Compare input from the user and make sure sure only a number
         * from the list is input. */
        if( std::cin.fail() or option < 1 or option > limit - 1 ) {
            std::cout << "You must input a number from the list" << std::endl;
            _cin_clear();
        }
    } while( option < 1 or option > limit-1 );
    _cin_clear();
    std::cout << std::endl;
    return option;
}

/* This uses some simple math to print out some centered text and set a
 * fill character/s for each line. I will expand on this later to take
 * more options and allow for more kinds of formatting that are difficult
 * or inconvenient to achieve with the standard library.*/
void _print_center( std::vector<std::string>& tocenter, int width, char sfill ) {
    int len = tocenter.size();
    for ( int x=0; x<len;x++ ) {
        int to_pad = width - tocenter[x].length();
        int left_pad = to_pad / 2;
        int right_pad = to_pad - left_pad;
        std::cout << std::string( left_pad, sfill )
            << tocenter[x]
            << std::string( right_pad, sfill )
            << std::endl;
        _sleep(1000);
    }
}

/* This function is used to scroll text in two ways. The first is scrolling
 * from right to left, much like a news ticker where text will scroll into and
 * then out of view. The second scrolls text in from left to right until the
 * text is fully in view. Useful for menu items and when you want to add a
 * little extra flair to printed text. */
void _scroller(std::string line,int width,std::string direc) {
    std::string output = "";
    int len = line.size();
    if( direc == "right" ) {
        for( int n = len - 1; n >= 0;n-- ) {
            // Uses the substring function to control how much text shows.
            output = line.substr(n,len);
            std::cout << output;
            // Pause display for 30 milliseconds
            _sleep(30);
            // Flush the line, then return to beginning.
            std::cout << std::flush << '\r';
        }
    }
    else {
        for( int n = 0; n <= width + len; n++ ) {
            // Create line of spaces matching 'width' then append 'line'.
            output = std::string(width,' ') + line;
            // Truncate start of 'line' each iteration until end of 'line'.
            output = output.substr(n, output.size()) + std::string(n, ' ');
            // Set end of line to match 'width' to create the scroll in effect.
            output.resize(width);
            std::cout << output;
            // Sleep for 80 milliseconds which seems to be a comfortable speed.
            _sleep(80);
            // Flush the line, then return to beginning.
            std::cout << std::flush << '\r';
        }
    }
    /* One more flush to allow for effects like loading bars that will them be
     * replaced on the same line with the requested information rather than
     * creating a new line every time. */
    std::cout << std::flush;
}

/* Creates a sleep timer that should be compatible with whatever system it is
 * used on.*/
void _sleep(int sleep_time) {
    // Gets time according to running system and stores value in 'timer'.
    std::chrono::milliseconds timer(sleep_time);
    // Runs the 'sleep_for' command using the value of 'timer'.
    std::this_thread::sleep_for(timer);
}

/* Fully clears 'std::cin' of all contents. This has become a standard tool and
 * there really isn't a reason not to use it after most uses of cin as it
 * eliminates the possibility of the contents of 'std::cin' being reused
 * unexpectedly. */
void _cin_clear() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/* This prints a single line animated. No matter how long the line it will
 * always take approximately the same time to print as the delay between
 * characters decreases by 2/3 with every iteration.*/
void _print_line(int iters) {
    int sleeper = 1000;
    for( int x=0;x<iters;x++ ) {
        std::cout << '|';
        std::cout << std::flush;
        _sleep(sleeper);
        sleeper /= 1.66;
    }
}


std::string _dec_string(double num, int prec)
{
    std::ostringstream to_dec;
    to_dec << std::fixed;
    to_dec << std::setprecision(prec);
    to_dec << num;
    std::string dec = to_dec.str();
    return dec;
}

/* Get input from the user and check if valid input. Can also be given a string
 * for use as the prompt for the user allowing to change the prompt for each
 * call to this function, which is important as it will then become part of the
 * loop and won't be lost on subsequent iterations.*/
double long _g_positive(std::string prompt) {
    double long num = 0;
    bool go = true;
    do {
        std::cout << prompt << std::endl;
        std::cout << "Entering a non number or 0 will exit" << std::endl;
        std::cin >> num;
        _cin_clear();
        if(num == 0) return 0;
        if(num <= 0) std::cout << "You must input a positive number." << std::endl;
        else go=false;
    } while ( go );
    std::cout << std::endl;
    return num;
}
#endif
