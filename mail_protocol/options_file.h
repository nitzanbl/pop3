#ifndef __get_taxi_options_file__
#define __get_taxi_options_file__

#define OP_N 200

#include <iostream>
#include <fstream>
#include "str.h"


/*
 * This class is an iterator on an options file
 */

class Options_File
{
    std::ifstream _f;
    char _buffer[OP_N];
    int _parameter_count;
    Str *_parameters;
    
public:
    
    Options_File(const char* filename); // CTOR
    
    bool read_line(); // Loads the next non comment line in to the buffer return true on success
    int num_parameters(); // Returns how many parameters are in the current line
    const Str get_parameter(int i); // Returns copy of the i parameter in parameters
    int get_int_parameter(int i); // Returns the int value of the i parameter in parameters
    float get_float_parameter(int i); // Returns the float value of the i parameter in parameters
    char get_char_parameter(int i); // Returns the first char from the i parameter in parameters
    
    ~Options_File(); // DTOR
};

#endif
