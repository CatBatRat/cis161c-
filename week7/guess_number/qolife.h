#ifndef __QO_LIFE__
#define __QO_LIFE__

#include <iostream> // std::cin, std::cout, std::endl
#include <iomanip>  // std::setprecision, std::fixed
#include <vector>   // std::vector
#include <cstdio>   // std::exit(), std::system()
#include <string>


int _validate( std::vector<std::string>&, int limit = 0 );

std::string _dec_string( double, int prec = 5, bool fixed = false );

void _print_center( std::vector<std::string>, int width=74,
        int delay=1000, char lfill = '#', char rfill='\n' );

void _sleep( int sleep_time );

void _cin_clear();

void _print_line( int iters );

void _scroller( std::string, std::string direc = "left", int width=0 );

double long _g_positive( std::string prompt );

std::string _to_lower(std::string& str);

void _wait_enter();


#endif
