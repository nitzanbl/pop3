#ifndef __get_taxi_str__
#define __get_taxi_str__

#include <iostream>
#include <cstring>

/*
 * This class represents a string
 */

class Str
{
    char *_string;
    int _len;
    
public:
    
    Str(); // Default CTOR
    Str(const Str &str); //Copy CTOR
    Str(const char* string); // Conversion CTOR
    Str(int n);
    
    Str get_line (int line );
    void set_str(const Str &str); // Sets the instances string
    int get_length() const; // Returns the len
    char get_char(int index) const; // Returns the index char from string
    bool equals(const char *str) const;// Returns true if str == _string
    const char* get_string () const;
    Str& operator=(const char* st);
    Str& operator=(const Str & st);

    Str& operator<<(const Str &st);
    
    ~Str(); //Dtor

private:
    
    void strcpy(const char* new_s); // Copies new_s into string
};

#endif
