#include <thread>
#include <chrono>
#include "qolife.h"

/* Creates a sleep timer that should be compatible with whatever system it is
 * used on.*/
void _sleep( int sleep_time ) {
    // Gets time according to running system and stores value in 'timer'.
    std::chrono::milliseconds timer( sleep_time );
    // Runs the 'sleep_for' command using the value of 'timer'.
    std::this_thread::sleep_for( timer );
}

/* Discovered std::getline() will end on Enter press, so this makes a great
 * tool to pause a program until key press. */
void _wait_enter() {
    std::string hold;
    std::cout << "\nPress Enter to continue" << std::flush;
    std::getline( std::cin, hold );
    /* Need to investigate why clearing cin causes enter to fail on the first
     * press but not the second. */
    //_cin_clear();
    std::cout << std::endl << std::endl;
}

/* Fully clears 'std::cin' of all contents. This has become a standard tool and
 * there really isn't a reason not to use it after most uses of cin as it
 * eliminates the possibility of the contents of 'std::cin' being reused
 * unexpectedly. EOF now exits the program cleanly, will see about adding a
 * prompt in case the button combo was pressed on accident. */
void _cin_clear() {
    if( std::cin.eof()) {
            std::cout << "Exit command received." << std::endl;
            std::exit(0);
    }
    std::cin.clear();
    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
}

/* This function takes a vector of strings and turns them into a numbered list
 * of options. The First element is used as the header for the list. User input
 * the number for the option they want and that value is returned. Can also
 * provide an optional limit and the number of options will be truncated as well
 * as validation adjusting to the new number of items. */
int _validate( std::vector<std::string>& check, int limit ) {
    int option;
    std::string output = "";
    if( limit == 0 )
        limit=check.size();
    else limit = limit+1;
    do {
        std::cout << std::endl << check[0] << std::endl;
        /* Use the size (number of elements) of the vector to determine
         * how many to print and which number to show next to each option.*/
        for( int x=1;x<limit;x++ ) {
            output = std::to_string(x) + " " + check[x];
            _scroller( output, "right", 40 );
            std::cout << std::endl;
        }
        std::cin >> option;
        _cin_clear();
        /* Compare input from the user and make sure sure only a number
         * from the list is input. */
        if( option < 1 or option > limit - 1 ) {
            std::cout << "You must input a number from the list" << std::endl;
        }
    } while( option < 1 or option > limit-1 );
    std::cout << std::endl;
    return option;
}

