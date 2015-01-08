#include "str.h"

using namespace std;

Str::Str()
{
    _string = 0;
}

Str::Str(const Str &str)
{
    _string = 0;
    set_str(str);
}

Str::Str(int n) {
    if (n == 0) {
        _string = new char[2];
        _len = 1;
        strcpy("0");
    } else {
        int t = n;
        _len = 0;
        
        while (t != 0) {
            _len++;
            t /= 10;
        }
        
        _string = new char[_len+1];
        
        for (int j = 0; j < _len; j++) {
            _string[_len-1-j] = n%10 + '0';
            n /= 10;
        }
        _string[_len] = '\0';
    }
}

Str::Str(const char* string)
{
    
    _string = 0;
    _len = 0;
    
    if( string == NULL )
        return;
    
    while (string[_len] != '\0')
        _len++;
    
    _string = new char[_len + 1];
    strcpy(string);
}

void Str::set_str(const Str &str)
{
    if (_string != 0)
        delete [] _string;
    
    if (str._string == NULL) {
        _string = NULL;
        _len = 0;
        return;
    }
    
    _len = str._len;
    
    _string = new char[str._len + 1];
    strcpy(str._string);
}

int Str::get_length() const
{
    return _len;
}

char Str::get_char(int index) const
{
    return _string[index];
}

void Str::strcpy(const char* new_s)
{
    int i = 0;
    while (i < _len)
    {
        _string[i] = new_s[i];
        i++;
    }
    _string[i] = '\0';
}

bool Str::equals(const char *str) const
{
    int i = 0;
    while (str[i] != '\0' && _string [i] != '\0')
    {
        if (str[i] != _string[i]) return false;
        i++;
    }
    
    return str[i] == _string[i];
}

Str Str::get_line (int line )
{
    char *l = new char[_len + 1];
    for (int i = 0; i < _len+1; i++) {
        l[i] = _string[i];
    }
    l = strtok(l, "\n");
    for (int i = 1; i < line && l != NULL; i++) {
        l = strtok(NULL, "\n");
    }
    return Str(l);
}

const char* Str::get_string () const
{
    return _string;
}

Str& Str::operator=(const char* st)
{
    _string = 0;
    
    _len = 0;
    while (st[_len] != '\0')
        _len++;
    
    _string = new char[_len + 1];
    strcpy(st);
    return *this;
    
}

Str& Str::operator=(const Str & st)
{
    set_str(st);
    return *this;
}

Str& Str::operator<<(const Str &st) {
    if (_string == NULL) {
        set_str(st);
    } else {
        char *new_str = new char[_len + st._len + 1];
        for (int i = 0; i < _len; i++) {
            new_str[i] = _string[i];
        }
        for (int i = 0; i < st._len; i++) {
            new_str[i+_len] = st._string[i];
        }
        _len += st._len;
        new_str[_len] = '\0';
        delete [] _string;
        _string = new_str;
    }
    return *this;
}



Str::~Str()
{
    if (_string != 0)
        delete [] _string;
}
